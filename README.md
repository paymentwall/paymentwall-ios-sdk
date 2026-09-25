# paymentwall-ios-sdk

Accept payments inside your iOS app. Paymentwall is a global payment gateway reaching more than 200
countries with 100+ alternative payment options, and this SDK becomes a native part of your
application — so a payer never leaves it for a browser.

**Version 4.0** is a substantial change from 3.x: Swift Package Manager distribution, signed dynamic
frameworks, and a smaller set of shipped modules. If you are upgrading, read
[CHANGELOG.md](CHANGELOG.md) first. If you are integrating for the first time, start at
[Add the SDK](#add-the-sdk).

The payment screens are native, follow the payer's light or dark mode, and format the total the way
the currency is actually written in the payer's region. Build [Demo](Demo) to see them.

## Requirements

| | |
|---|---|
| **Deployment target** | iOS 15.0 |
| **Xcode** | 15 or later |
| **Swift** | Not required. The API is Objective-C and usable from either language; the samples are Swift |
| **Architectures** | Device `arm64`; simulator `arm64` and `x86_64`, so Apple Silicon works |

## How it works

1. Add the package to your app.
2. Your app builds a `PWPaymentObject` and presents the SDK.
3. The SDK shows a payment screen offering the methods **you** listed, takes the payment, and hands
   back a typed result.
4. Your server confirms the payment through Paymentwall's pingback. **The pingback is the
   authoritative record** — see [Confirming a payment](#confirming-a-payment).

## Credentials

Your app needs a **project key**, from the application settings of your Merchant Account at
[paymentwall.com](https://api.paymentwall.com/developers/applications).

**The project key is also your public key.** The card form uses that same value, and there is no
separate card credential to configure. If card payments come back *"Public key is missed or
invalid"*, that project does not have card processing enabled — enable it in the merchant portal.

Your **secret key stays on your server.** Some payment methods need a signed request; your server
signs it and hands the signature back — see
[Signing on your server](INTEGRATION.md#signing-on-your-server). Anything in an app bundle can be
extracted from it, so treat a secret that has ever shipped inside an app binary as compromised.

## Add the SDK

The SDK ships through **Swift Package Manager**. In Xcode: **File → Add Package Dependencies…**, then

```
https://github.com/paymentwall/paymentwall-ios-sdk
```

and choose **Up to Next Major Version** from `4.2.0`. Or, in a `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/paymentwall/paymentwall-ios-sdk", from: "4.2.0")
]
```

Add the **`PWCoreSDK`** product to your target. Add **`PWMyCardPlugin`** as well if you offer MyCard.

⚠️ **A plugin needs `PWCoreSDK` alongside it.** Swift Package Manager cannot express a dependency
between binary targets, so adding a plugin on its own fails to link with an undefined symbol naming
`PWCoreSDK`.

The frameworks are **dynamic** and are embedded in your app. Xcode does that for you for a package
dependency; if you instead drag an `.xcframework` in by hand, choose **Embed & Sign**. You do **not**
need `-ObjC` in *Other Linker Flags*, and Swift consumers do **not** need a bridging header — use
`import PWCoreSDK`.

`SHA256SUMS` sits beside the frameworks. Check the digest — a file you were sent is not a file you
resolved:

```sh
shasum -a 256 -c SHA256SUMS
codesign -dv --verbose=2 Frameworks/PWCoreSDK.xcframework   # TeamIdentifier=D44Q8LH786
```

Full instructions, including the payment flow and every callback:
**[Integration guide](INTEGRATION.md)**

## Payment methods

| Method | What it is | How to add it |
|---|---|---|
| **Local payments** (`PWOptionWidget`) | Paymentwall's hosted page: local methods, bank transfer, cash and wallets, chosen for the payer's country | Built in |
| **Card** (`PWOptionBrick`) | Visa, Mastercard, Amex — a native card form, no browser | Built in |
| **Prepaid** (`PWOptionMint`) | Vouchers and ePins | Built in |
| **MyCard** (`PWOptionMyCard`) | Taiwan prepaid card | A separate product — add `PWMyCardPlugin` |

The first three need nothing beyond `PWCoreSDK`. You choose which to offer per payment, and the SDK
only ever shows what you asked for. A method you have not included is simply **not offered** to the
payer — it is never drawn as a row that fails when tapped.

## Confirming a payment

`PWPaymentResponseCodeSuccessful` means the payer completed the flow on the device. **It is not proof
of a settled transaction.** Deliver goods on your server's pingback, not on the device result alone.

`PWPaymentResponseCodeUnknown` is neither success nor failure: the SDK lost the page mid-payment, so
the charge may or may not have been authorised. Reconcile it server-side, and do not treat it as a
failure.

## Diagnostics

The SDK is **silent by default**. To see what it is doing while you integrate:

```swift
import PWCoreSDK

PWCoreSDK.sharedInstance().setLogLevel(.info)
```

It cannot leak payment data: the logging API takes no strings, and URLs have their query stripped
before printing. Turn it off before you ship.

## Sample app

**[Demo](Demo)** is a complete, minimal integration written only against the frameworks published
here — the same files you resolve. It contains **no credentials**: you enter your keys in the running
app.

## Licence

MIT — see [LICENSE](LICENSE).

## Support

Questions and integration help: [support@paymentwall.com](mailto:support@paymentwall.com)
