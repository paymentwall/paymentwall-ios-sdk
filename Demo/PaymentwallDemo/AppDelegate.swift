//
//  AppDelegate.swift — Paymentwall iOS SDK v4 demo
//
//  Deliberately tiny. This app exists to show a merchant the shortest correct integration, so
//  everything that is not the integration has been left out: no storyboards, no scene delegate,
//  no asset catalogue.
//
import UIKit
import PWCoreSDK

@main
final class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        let window = UIWindow(frame: UIScreen.main.bounds)
        window.rootViewController = UINavigationController(rootViewController: CheckoutViewController())
        window.makeKeyAndVisible()
        self.window = window
        return true
    }

    // MARK: - Returning from a bank or wallet app
    //
    // Both hooks, because payment methods use both. The published 3.x demo wired only the first,
    // so any method returning by universal link had a path that could never fire.

    func application(_ app: UIApplication,
                     open url: URL,
                     options: [UIApplication.OpenURLOptionsKey: Any] = [:]) -> Bool {
        PWCoreSDK.sharedInstance().handlePingbackURL(url)
        return true
    }

    func application(_ application: UIApplication,
                     continue userActivity: NSUserActivity,
                     restorationHandler: @escaping ([UIUserActivityRestoring]?) -> Void) -> Bool {
        PWCoreSDK.sharedInstance().handlePingbackUniversalLink(userActivity)
        return true
    }
}
