# Changelog

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
