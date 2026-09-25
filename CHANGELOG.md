# Changelog

## 4.2.0

**Nothing to change in your integration.** The SDK's own screens now link to Paymentwall's privacy
policy from their footer, so a payer can read it before they pay. The public API is unchanged.

## 4.1.0

**Two projects in one app, a flat checkout, and an optional success screen.**

### Added

- **A 3-D Secure challenge is now drawn in your app** rather than in a web view, wherever the
  issuer supports it. Where they do not, the web-view flow is unchanged.

  An in-app challenge means the payment takes **two charges**: charge the token as usual, and when the
  SDK reports a token whose `secureToken` is set, charge again sending `secure_token` and
  `charge_id`. Your charge should also send `reference_id` from `PWBrickToken.secureReferenceId`
  whenever it is set — without it the gateway cannot offer a native challenge for that payment.
- **`PWBrickToken.secureReferenceId`, `.secureToken` and `.chargeId`** — the three values a 3-D
  Secure 2 charge needs. All nil on a payment with no 3-D Secure session.
- **`-[PWOptionBrick handleBackendChargeResult:chargeObject:secureURL:errorMessage:]` now reads the
  charge response you pass it.** If `chargeObject` carries a `secure` object, the SDK starts the
  challenge from it — so you can pass the gateway's response verbatim and stop picking the URL out of
  it. Passing `secureURL:` yourself behaves exactly as before.
- **`-[PWCoreSDK setShowsSuccessScreen:]`** — set it to `NO` and a successful payment returns to your
  app immediately instead of after the SDK's confirmation countdown. `-paymentResponse:` is still
  called exactly once, with the same response; it simply arrives earlier. The processing and failure
  screens are unaffected. Default `YES`, so nothing changes unless you ask.
- **`overrideProjectKey` on `PWPaymentOptionProtocol`** (`@optional`) — an option can now tell the SDK
  it carries its own key. See *Changed*.
- **`Distribution/INTEGRATION.md`** gains **“Where the widget code comes from”** and **“Two projects
  in one app”**. The per-option key overrides have shipped since before 4.0.0 and were documented
  nowhere.

### Changed

- ⚠️ **A charge held for FRAUD REVIEW is no longer reported as a completed payment, and there is
  a new response code for it: `PWPaymentResponseCodePending`.** Paymentwall can take the money and
  hold the charge — `captured: true` with `risk: "pending"` — and the SDK used to report that as
  `PWPaymentResponseCodeSuccessful`. An integrator who handed the charge response back verbatim was
  told the payment had succeeded and could ship goods against a charge that had not cleared.

  The SDK now shows a **"Payment under review"** screen and polls the charge: approved reports
  success as before, a review that ends badly reports failure, and a review still unfinished when
  the screen closes reports the new `Pending`.

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
  register them. Previously options were split into a top-level group and a “Local Payments”
  sub-list, so tapping a row could open a second screen with the same title containing a row with the
  same label.
  - ⚠️ **Row order is now yours.** Card and prepaid used to be hoisted above local methods whatever
    order they were registered in. If you depend on cards first, put them first in the array.
- **A global project key is no longer required when every option carries its own.**
  `-setGlobalProjectKey:` used to be mandatory even for an app whose every option overrode it. The
  check is now per option — and stricter for it: one global key no longer covers an option with no
  key of its own.

### Deprecated

- **`-[PWPaymentOptionProtocol presentation]`** and `PWPaymentOptionPresentationMain`. Nothing reads
  them: the list is flat and follows your registration order. They still compile and will be removed
  in the next major version.


## 4.0.0

A new distribution channel, a new packaging shape, and a smaller set of shipped modules. An existing
3.x integration needs changes — the table at the top of [README.md](README.md) lists them in the
order they will stop your build.

### Distribution

- The SDK ships through **Swift Package Manager** only. Add
  `https://github.com/paymentwall/paymentwall-ios-sdk` from `4.0.0`.
- **CocoaPods is not a v4 channel.** `pod 'PWCoreSDK'` continues to resolve 3.1.1 and will not
  receive v4.
- Products: `PWCoreSDK` and `PWMyCardPlugin`. One tag versions them together.
- Each is a **signed dynamic-framework XCFramework**. `SHA256SUMS` beside them lets you verify what
  you received; `codesign -dv` shows the signing team.

### Packaging

- **Dynamic frameworks, not a static library.** Xcode embeds and signs them for you as a package
  dependency; adding an `.xcframework` by hand means choosing **Embed & Sign**.
- **`-ObjC` is no longer required.** It used to be mandatory, and omitting it produced
  `unrecognized selector` at payment time.
- **`import PWCoreSDK` works.** No bridging header.
- Resources — localizations, images, the privacy manifest — are **inside** each framework. There is
  no loose `PWCoreSDKResource.bundle` to copy.
- Each framework carries a `PrivacyInfo.xcprivacy`.
- Simulator slices include **arm64**, so the SDK builds on Apple Silicon.

### Requirements

- **iOS 15.0** minimum, raised from iOS 8.0.
- **Xcode 15** minimum.

### API

- **Added `PWPaymentResponseCodeUnknown`.** The outcome is not known — the SDK lost the page
  mid-payment. **Handle it, and do not treat it as a failure:** reconcile server-side before shipping
  goods. These cases previously reported `.failed`, which was wrong.
- Removed **`PWOptionMobiamo`**. Carrier billing is not available in v4.
- `PWCardScannerPlugin` is not published. `PWCardScannerProtocol` remains, so you can supply your own
  scanner.
- The game-styled UI plugin is not published in 4.0.

### Payment methods

- **Built in:** card (Brick), local payments (PWLocal), prepaid (Mint).
- **Separate product:** MyCard.
- **Not published in 4.0:** Alipay, WeChat Pay, UnionPay. Contact support before upgrading if you
  offer one of them.

### Sample app

- `Demo/` is a complete, minimal integration built against the frameworks in this repository,
  replacing the 3.x sample. **It contains no credentials** — you enter your keys in the running app.

### Licence

- **MIT**, and the file now contains the licence text.
