# Integration guide

Everything a payment needs, in the order you will write it. Start at
[README.md](README.md) if you have not added the package yet.

## Contents

- [A complete integration](#a-complete-integration)
- [Handling the response](#handling-the-response)
- [Payment methods](#payment-methods)
- [Where the widget code comes from](#where-the-widget-code-comes-from)
- [Two projects in one app](#two-projects-in-one-app)
- [Returning from another app](#returning-from-another-app)
- [Signing on your server](#signing-on-your-server)
- [Everything you can set](#everything-you-can-set)

## A complete integration

```swift
import PWCoreSDK
import UIKit

final class Checkout: NSObject, PWCoreSDKDelegate {

    func startPayment(from host: UIViewController) {
        let sdk = PWCoreSDK.sharedInstance()

        // Your project key, which is also your public key.
        sdk.setGlobalProjectKey("YOUR_PROJECT_KEY")

        // PWPaymentObject is immutable — everything is set here.
        let payment = PWPaymentObject(name: "Gold pack",
                                      price: NSDecimalNumber(string: "0.99"),
                                      itemID: "item456",
                                      userID: "user123",
                                      currency: "USD",
                                      image: nil)

        let card  = PWOptionBrick()
        let local = PWOptionWidget(type: .digitalGoodsFlexible)

        sdk.showPaymentVC(withParentVC: host,
                          paymentObject: payment,
                          paymentOption: [card, local],
                          delegate: self)
    }

    func paymentResponse(_ response: PWCoreSDKResponse) {
        // See "Handling the response".
    }
}
```

`userID` and `itemID` must be alphanumeric.

## Handling the response

Every payment ends in exactly one of these.

```swift
import PWCoreSDK

extension Checkout {

    func handle(_ response: PWCoreSDKResponse) {
        switch response.responseCode {

        case .successful:
            // The payer completed the flow on the device. NOT proof of a settled
            // transaction — deliver goods on your server's pingback.
            break

        case .failed:
            // The payment did not go through. The SDK has already told the payer.
            break

        case .cancel:
            // The payer backed out.
            break

        case .unknown:
            // Neither success nor failure: the SDK lost the page mid-payment, so the
            // charge may or may not have been authorised. Reconcile server-side.
            // Do not treat it as a failure — refusing to ship on this alone risks
            // refusing a payment that succeeded.
            break

        case .merchantProcessing:
            // Your backend has work to do. See "Card" below.
            break

        case .signatureRequiring:
            // You did not give the SDK a secret key. See "Signing on your server".
            break

        @unknown default:
            break
        }
    }
}
```

## Payment methods

### Card

```swift
import PWCoreSDK

extension Checkout {

    func makeCardOption() -> PWOptionBrick {
        return PWOptionBrick()
    }

    // The SDK collects the card and obtains a one-time token, then calls back with
    // `.merchantProcessing`. Create the charge from your backend — never from the app.
    func continueCardCharge(_ brick: PWOptionBrick, response: PWCoreSDKResponse) {
        guard response.paymentType == PWPaymentTypeBrick else { return }

        // POST response.token to your server, which calls
        //   https://api.paymentwall.com/api/brick/charge
        // and returns the result. Then:
        brick.handleBackendChargeResult(true,
                                        chargeObject: nil,   // the charge dict, to offer "save this card"
                                        secureURL: nil,      // a URL, to run 3-D Secure
                                        errorMessage: nil)   // a message, to show the failure dialog
    }
}
```

### Local payments

```swift
import PWCoreSDK

extension Checkout {

    func makeLocalOption() -> PWOptionWidget {
        let params = PWWidgetDigitalGoodsFlexible()
        params.widget = "pw_1"        // Optional — see "Where the widget code comes from".
        params.ag_type = "fixed"

        return PWOptionWidget(type: .digitalGoodsFlexible, extraParams: params)
    }
}
```

`extraParams` may be a dictionary or one of `PWWidgetDigitalGoodsFlexible`,
`PWWidgetDigitalGoodsDefaut`, `PWWidgetVirtualCurrency`, `PWWidgetCart`. Values that also exist on
`PWPaymentObject` — price, currency, user id, item name — are taken from the payment object and
ignored here.

### Prepaid

```swift
import PWCoreSDK

extension Checkout {
    func makePrepaidOption() -> PWOptionMint { return PWOptionMint() }
}
```

### MyCard

```swift
import PWCoreSDK
import PWMyCardPlugin

extension Checkout {
    func makeMyCardOption() -> PWOptionMyCard { return PWOptionMyCard() }
}
```

## Where the widget code comes from

`params.widget` is **optional**, and it is worth understanding before you decide whether to set it.

A **widget** is a named set of payment methods, configured in the
[Paymentwall merchant area](https://api.paymentwall.com/): open your project, then **Widgets**. Each
one has a short code such as `pw_1`. The code decides which methods the hosted checkout offers, and
to whom.

| | What happens |
|---|---|
| **Omit it** | Paymentwall offers whatever your project is configured to offer. This is the right choice for most integrations: the method list becomes something you change in the merchant area, with no app release |
| **Set it** | The checkout offers exactly that widget. Use it when one app pays through more than one widget — a different method mix per storefront, per country, or per price point |

**A widget code belongs to exactly one project.** It is not a global identifier: the code and the
project key it was created under travel together, and swapping one without the other cannot work. If
you move a payment to a different project, change both.

## Two projects in one app

One app can pay against more than one Paymentwall project — cards on one, local payments on another.
Set the key on the **option** rather than globally, and it wins over
`setGlobalProjectKey` for that option alone:

```swift
import PWCoreSDK

extension Checkout {

    /// Your keys, from wherever your app keeps them — a build setting, your server, the keychain.
    /// They are written as inputs here rather than as literals on purpose: see the warning below.
    struct ProjectKeys {
        let brickPublic: String
        let localProject: String
        let localSecret: String
    }

    func makeTwoProjectOptions(keys: ProjectKeys) -> [PWPaymentOptionProtocol] {
        let card = PWOptionBrick()
        card.overrideProjectKey = keys.brickPublic

        let params = PWWidgetDigitalGoodsFlexible()
        params.widget = "pw_1"
        let local = PWOptionWidget(type: .digitalGoodsFlexible, extraParams: params)
        local.overrideProjectKey = keys.localProject
        local.overrideSecretKey = keys.localSecret

        return [card, local]
    }
}
```

Anything you do not override still comes from the global keys, so an app with one project needs none
of this.

### The card option takes a public key, and only a public key

Your Brick project in the merchant area shows **two** keys, a public one and a private one. Only the
**public** key belongs in the app.

The private key creates the charge, and that happens **on your server** — see
[Handling the response](#handling-the-response), where the SDK hands you a token to send there. The
SDK has no charge call in it at all; the only key it puts on the wire for a card is the public one,
when it exchanges the card details for that token.

> **Never ship the private key in your app.** Anything compiled into an app can be read out of it,
> and that key can charge money.

Local payments are the other way round: the widget's request is **signed on the device**, so
`overrideSecretKey` above is that project's secret. If you would rather not put it in the app at all,
sign on your server instead — see [Signing on your server](#signing-on-your-server).

## Returning from another app

Some payment methods hand off to a bank or wallet app. Wire **both** hooks — an integration with only
the first has a return path that can never fire.

```swift
import PWCoreSDK
import UIKit

final class PWAppDelegateHooks {

    func application(_ app: UIApplication, open url: URL) -> Bool {
        PWCoreSDK.sharedInstance().handlePingbackURL(url)
        return true
    }

    func application(_ app: UIApplication, continue activity: NSUserActivity) -> Bool {
        PWCoreSDK.sharedInstance().handlePingbackUniversalLink(activity)
        return true
    }
}
```

## Signing on your server

Some methods sign their requests, and **your secret key must never be in your app** — anything
shipped in a bundle can be extracted from it.

So the SDK does not ask you for one. It calls back with `.signatureRequiring` and the string to
sign, you sign it on your server, and hand the signature back.

```swift
import PWCoreSDK

extension Checkout {

    func signOnServer(_ response: PWCoreSDKResponse) {
        guard let stringToSign = response.stringToSign else { return }

        // Send stringToSign to your backend, which appends your secret key and hashes it
        // with the algorithm named by response.signatureAlgorithm (.MD5 or .SHA256).
        let signature = mySigningService(stringToSign, response.signatureAlgorithm)

        PWCoreSDK.sharedInstance().continuePayment(withSign: signature)
    }

    func mySigningService(_ s: String, _ algorithm: PWSignatureType) -> String { return "" }
}
```

## Everything you can set

Every one of these is called on `PWCoreSDK.sharedInstance()`. Only the project key is
required; the rest have working defaults, so an integration that sets nothing else still
works.

| Method | What it does | Default |
|---|---|---|
| `setGlobalProjectKey(_:)` | Your **public** project key. Required. | — |
| `showPaymentVC(withParentVC:paymentObject:paymentOption:delegate:)` | Starts a payment and presents the SDK's screens. | — |
| `setShowsSuccessScreen(_:)` | Whether the SDK draws its own "Paid" confirmation before calling you back. Set `false` when your app shows its own. | `true` |
| `showsSuccessScreen()` | Reads back what the above was set to. | `true` |
| `continuePayment(withSign:)` | Resumes a payment after your server signs the string you were given. | — |
| `setRequestTimeOut(_:)` | Network timeout, in seconds. Also bounds how long the SDK waits for you after `.merchantProcessing` or `.signatureRequiring`. | `60` |
| `setExtraParams(_:)` | Extra parameters added to every payment request. | none |
| `setLogLevel(_:)` | How much the SDK logs about its own network activity. It cannot log a request body, a header or a response body. Leave it off in a shipped app. | `.none` |
| `handlePingbackURL(_:)` | Hands the SDK a URL your app was opened with, when the payer returns from another app. | — |
| `handlePingbackUniversalLink(_:)` | The same, for a universal link. Returns whether the SDK handled it. | — |

### Showing your own success screen

`setShowsSuccessScreen(false)` changes **when** you are told, not **whether**.
`paymentResponse(_:)` is still called exactly once with the same response — it simply
arrives seconds earlier, while your app is still on screen, so show your confirmation
from there.

It does not affect the processing indicator or the failure screen. A payer who has just
handed over card details still needs to see that something is happening, and still needs
to be told when it did not work.

```swift
PWCoreSDK.sharedInstance().setShowsSuccessScreen(false)
```
