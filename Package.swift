// swift-tools-version:5.9
//
//  Package.swift — Paymentwall iOS SDK
//
//  Each product is a signed dynamic-framework XCFramework committed to this repository. Adding the
//  package by URL and version is all an integrator needs; Xcode embeds and signs the frameworks for
//  you.
//
//  ONE TAG VERSIONS BOTH. The plugin is released together with the core, so it cannot ship a fix on
//  its own — pin one version and you have a consistent set.
//
//  swift-tools-version 5.9 is a floor chosen so the package works with Xcode 15 and later.

import PackageDescription

let package = Package(
    name: "PWCoreSDK",

    platforms: [
        .iOS(.v15)
    ],

    products: [
        // Cards (Brick), local payment methods (PWLocal) and Mint. Required.
        .library(name: "PWCoreSDK",      targets: ["PWCoreSDK"]),
        // MyCard prepaid vouchers. Optional. Requires PWCoreSDK.
        .library(name: "PWMyCardPlugin", targets: ["PWMyCardPlugin"]),
        // Optional. Requires PWCoreSDK.
    ],

    // ⚠️ EMBED & SIGN, not link-only. These are DYNAMIC frameworks: that is what lets them carry
    // their own resources and load their Objective-C categories without you setting `-ObjC`. Xcode
    // does the right thing automatically for a package dependency. If you instead drag an
    // .xcframework into a project by hand, choose "Embed & Sign".
    //
    // ⚠️ THE PLUGINS REQUIRE PWCoreSDK, and Swift Package Manager cannot express that here: a binary
    // target may not declare a dependency on another binary target. Add PWCoreSDK alongside any
    // plugin you use, or your build fails with an undefined-symbol error naming it.
    targets: [
        .binaryTarget(name: "PWCoreSDK",      path: "Frameworks/PWCoreSDK.xcframework"),
        .binaryTarget(name: "PWMyCardPlugin", path: "Frameworks/PWMyCardPlugin.xcframework"),
    ]
)
