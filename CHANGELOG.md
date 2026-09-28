# Changelog

## 4.2.0

**A 3-D Secure challenge drawn in your app, two projects in one app, a flat checkout, and an
optional success screen.** Nothing you have already written stops working: everything below is
either invisible or opt-in.

Add the package from `https://github.com/paymentwall/paymentwall-ios-sdk`, from `4.2.0`. Products:
`PWCoreSDK`, and `PWMyCardPlugin` if you offer MyCard.

### Added

- **A 3-D Secure challenge is now drawn in your app** rather than in a web view, wherever the issuer
  supports it. Where they do not, the web-view flow is unchanged.

  An in-app challenge means the payment takes **two charges**: charge the token as usual, and when
  the SDK reports a token whose `secureToken` is set, charge again sending `secure_token` and
  `charge_id`. Your charge should also send `reference_id` from `PWBrickToken.secureReferenceId`
  whenever it is set — without it the gateway cannot offer a native challenge for that payment.
- **`PWBrickToken.secureReferenceId`, `.secureToken` and `.chargeId`** — the three values a 3-D
  Secure 2 charge needs. All nil on a payment with no 3-D Secure session.
- **`-[PWOptionBrick handleBackendChargeResult:chargeObject:secureURL:errorMessage:]` now reads the
  charge response you pass it.** If `chargeObject` carries a `secure` object, the SDK starts the
  challenge from it — so you can pass the gateway's response verbatim and stop picking the URL out
  of it. Passing `secureURL:` yourself behaves exactly as before.
- **`-[PWCoreSDK setShowsSuccessScreen:]`** — set it to `NO` and a successful payment returns to
  your app immediately instead of after the SDK's confirmation countdown. `-paymentResponse:` is
  still called exactly once, with the same response; it simply arrives earlier. The processing and
  failure screens are unaffected. Default `YES`, so nothing changes unless you ask.
- **`overrideProjectKey` on `PWPaymentOptionProtocol`** (`@optional`) — an option can tell the SDK
  it carries its own key, so one app can pay against more than one Paymentwall project. See
  *Two projects in one app* in the [integration guide](INTEGRATION.md).

### Changed

- ⚠️ **A charge held for FRAUD REVIEW is no longer reported as a completed payment, and there is a
  response code for it: `PWPaymentResponseCodePending`.** Paymentwall can take the money and hold
  the charge — `captured: true` with `risk: "pending"` — and that used to be reported as
  `PWPaymentResponseCodeSuccessful`. An integrator who handed the charge response back verbatim was
  told the payment had succeeded and could ship goods against a charge that had not cleared.

  The SDK shows a **"Payment under review"** screen and polls the charge: approved reports success,
  a review that ends badly reports failure, and a review still unfinished when the screen closes
  reports `Pending`.

  - **Handle `PWPaymentResponseCodePending`.** It is not a success and not a failure — treat it as
    you treat `PWPaymentResponseCodeUnknown` and ship on Paymentwall's pingback, which is the
    authority.
  - **A `switch` over `PWPaymentResponseCode` with no `default` will warn until you add the case.**
    It is appended at the END of the enumeration, so every existing case keeps its raw value.
  - **Polling needs a secret key in the app**, which is not the recommended setup. Without one the
    SDK cannot poll, shows no review screen, and reports `Pending` immediately — still strictly
    better than calling it a success. Set `PWOptionBrick.overrideSecretKey` or
    `-[PWCoreSDK setGlobalSecretKey:]` if you want the polling, knowing a key in an app can be
    extracted from it.
  - **Unchanged:** an `approved` charge, and a charge response with no `risk` field at all, behave
    exactly as before — including the "Store card?" prompt.

- **The payment sheet is one flat list.** Every option you register is one row, in the order you
  register them. Options used to be split into a top-level group and a "Local Payments" sub-list, so
  tapping a row could open a second screen with the same title containing a row with the same label.
  - ⚠️ **Row order is yours.** Card and prepaid used to be hoisted above local methods whatever
    order they were registered in. If you depend on cards first, put them first in the array.
- **A global project key is not required when every option carries its own.** `-setGlobalProjectKey:`
  used to be mandatory even for an app whose every option overrode it. The check is per option — and
  stricter for it: one global key no longer covers an option with no key of its own.
- **The payment screens link to Paymentwall's privacy policy** from their footer, so a payer can
  read it before they pay.

### Deprecated

- **`-[PWPaymentOptionProtocol presentation]`** and `PWPaymentOptionPresentationMain`. Nothing reads
  them: the list is flat and follows your registration order. They still compile and will be removed
  in the next major version.
