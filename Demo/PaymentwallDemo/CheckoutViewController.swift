//
//  CheckoutViewController.swift — the whole integration, in one screen.
//
//  ⚠️ NO CREDENTIAL IS COMPILED INTO THIS APP. Both keys are typed in at runtime and remembered in
//  UserDefaults on this device only. Nothing is stored in the source or the app binary.
//
//  ⚠️ THE SECRET KEY FIELD IS A TESTING AFFORDANCE, NOT A PATTERN TO COPY.
//
//  Brick and PWLocal sign their requests, so without a secret key this demo can only ever reach
//  `.signatureRequiring` and you cannot complete a test payment. That is fine for a demo you run on
//  your own device. It is NOT fine in a shipped app: a secret key inside an app binary is a secret
//  you have handed to everyone who downloads it, and it can be extracted in minutes.
//
//  Leave the secret field EMPTY to see the flow a production app should use — the SDK then asks you
//  to sign on your server. Both paths are handled in `paymentResponse` below, on purpose.
//
import UIKit
import PWCoreSDK
import PWMyCardPlugin

final class CheckoutViewController: UIViewController {

    private let projectKeyField = UITextField()
    private let secretKeyField  = UITextField()
    private let amountField     = UITextField()
    private let statusLabel     = UILabel()

    private static let projectKeyDefaultsKey = "demo.projectKey"
    private static let secretKeyDefaultsKey  = "demo.secretKey"

    // MARK: - The integration

    private func pay() {
        let projectKey = projectKeyField.text ?? ""
        guard !projectKey.isEmpty else {
            report("Enter your project key first. It is the PUBLIC key from your Merchant Account.")
            return
        }
        UserDefaults.standard.set(projectKey, forKey: Self.projectKeyDefaultsKey)

        let sdk = PWCoreSDK.sharedInstance()
        sdk.setGlobalProjectKey(projectKey)

        // The secret key, if you supplied one. Brick and PWLocal sign their requests, so without it
        // every payment stops at `.signatureRequiring` and you cannot complete a test charge.
        //
        // ⚠️ FOR TESTING ON YOUR OWN DEVICE ONLY. Do not do this in a shipped app — see the note at
        // the top of this file. Leave the field empty to exercise the server-signing flow instead.
        let secretKey = secretKeyField.text ?? ""
        UserDefaults.standard.set(secretKey, forKey: Self.secretKeyDefaultsKey)
        if !secretKey.isEmpty {
            sdk.setGlobalSecretKey(secretKey)
            sdk.setGlobalSign(.SHA256)   // NS_SWIFT_NAME renames setGlobalSignType: to this
        }

        sdk.setLogLevel(.info)   // .none in a shipped app. Safe to raise: the logger has no
                                 // string parameter and strips query strings, so it cannot print
                                 // card data or a signature.

        // PWPaymentObject is IMMUTABLE — everything is set here, there are no settable properties.
        let payment = PWPaymentObject(name: "Gold pack",
                                      price: NSDecimalNumber(string: amountField.text ?? "0.99"),
                                      itemID: "demoitem",
                                      userID: "demouser",
                                      currency: "USD",
                                      image: nil)

        let card = PWOptionBrick()
        let mint = PWOptionMint()

        // PWLocal. `widget` is REQUIRED — without it the API answers with an error that blames the
        // payer's country rather than the missing parameter, which is a long walk to a short fix.
        let localParams = PWWidgetDigitalGoodsFlexible()
        localParams.widget = "m2_1"
        localParams.ag_type = "fixed"
        let local = PWOptionWidget(type: .digitalGoodsFlexible, extraParams: localParams)

        let mycard = PWOptionMyCard()

        sdk.showPaymentVC(withParentVC: self,
                          paymentObject: payment,
                          paymentOption: [card, local, mint, mycard],
                          delegate: self)
    }
}

// MARK: - Handling the outcome

extension CheckoutViewController: PWCoreSDKDelegate {

    func paymentResponse(_ response: PWCoreSDKResponse) {
        switch response.responseCode {

        case .successful:
            // ⚠️ For a LOCAL payment method this is not proof that money moved. It means the
            // payer's browser reached your configured success URL — a client-side signal. Ship
            // goods on your server-side pingback, not on this callback.
            report("Payer finished. Reconcile server-side before shipping anything.")

        case .failed:
            report("Failed: \(response.message ?? "no message")")

        case .cancel:
            report("Cancelled by the payer.")

        case .unknown:
            // NEW IN v4, and it is NOT a failure. The SDK lost the page mid-payment, so the charge
            // may or may not have been authorised. Refusing to ship on this alone risks refusing a
            // payment that succeeded. Before v4 these were reported as `.failed`.
            report("Outcome UNKNOWN — reconcile server-side. Do not treat as a failure.")

        case .merchantProcessing:
            // Cards reach here with a one-time token. A real integration posts it to its own
            // backend, which calls api.paymentwall.com/api/brick/charge, then reports back.
            report("Backend work needed: token \(response.token?.token ?? "-"). "
                   + "Create the charge from your server, then call handleBackendChargeResult.")

        case .signatureRequiring:
            // Reached when no secret key was given, which is what a PRODUCTION app should do.
            // Send response.stringToSign to your server, sign it there with the algorithm in
            // response.signatureAlgorithm, and call continuePayment(withSign:).
            report("Signature required — this is the production flow. Sign this on your SERVER:\n"
                   + (response.stringToSign ?? "-")
                   + "\n\n(For a quick local test you can paste a secret key into the field above "
                   + "instead. Never do that in a shipped app.)")

        @unknown default:
            report("Unrecognised response code.")
        }
    }
}

// MARK: - Plumbing, which is not the interesting part

extension CheckoutViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Paymentwall v4"
        view.backgroundColor = .systemBackground

        projectKeyField.placeholder = "Project key (public)"
        projectKeyField.text = UserDefaults.standard.string(forKey: Self.projectKeyDefaultsKey)
        projectKeyField.autocapitalizationType = .none
        projectKeyField.autocorrectionType = .no
        projectKeyField.borderStyle = .roundedRect

        secretKeyField.placeholder = "Secret key — testing only, leave empty for the real flow"
        secretKeyField.text = UserDefaults.standard.string(forKey: Self.secretKeyDefaultsKey)
        secretKeyField.autocapitalizationType = .none
        secretKeyField.autocorrectionType = .no
        secretKeyField.isSecureTextEntry = true
        secretKeyField.borderStyle = .roundedRect

        let secretWarning = UILabel()
        secretWarning.text = "⚠️ Brick and PWLocal need a signed request, so a secret key is "
            + "required to complete a test payment here. A shipped app must never contain one — "
            + "leave it empty to see the server-signing flow."
        secretWarning.numberOfLines = 0
        secretWarning.font = .preferredFont(forTextStyle: .caption2)
        secretWarning.textColor = .systemOrange

        amountField.placeholder = "Amount"
        amountField.text = "0.99"
        amountField.keyboardType = .decimalPad
        amountField.borderStyle = .roundedRect

        let button = UIButton(type: .system)
        button.setTitle("Pay", for: .normal)
        button.titleLabel?.font = .preferredFont(forTextStyle: .headline)
        button.addTarget(self, action: #selector(payTapped), for: .touchUpInside)

        statusLabel.numberOfLines = 0
        statusLabel.font = .preferredFont(forTextStyle: .footnote)
        statusLabel.textColor = .secondaryLabel

        let stack = UIStackView(arrangedSubviews: [projectKeyField, secretKeyField, secretWarning,
                                                   amountField, button, statusLabel])
        stack.axis = .vertical
        stack.spacing = 16
        stack.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(stack)

        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.leadingAnchor, constant: 20),
            stack.trailingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.trailingAnchor, constant: -20),
            stack.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: 32),
        ])
    }

    @objc private func payTapped() {
        view.endEditing(true)
        pay()
    }

    private func report(_ message: String) {
        statusLabel.text = message
        print("[demo]", message)
    }
}
