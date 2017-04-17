//
//  ItemViewController.swift
//  PWDungeon
//
//  Created by Tien Nhat Vu on 6/24/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

import UIKit

enum Item {
    case mana,
    gem,
    shield
    
    var name: String {
        switch self {
        case .mana:
            return "Mana booster"
        case .gem:
            return "Score gem"
        case .shield:
            return "Iron shield"
        }
    }
    
    var price: String {
        switch self {
        case .mana:
            return "0.49"
        case .gem:
            return "0.99"
        case .shield:
            return "9.99"
        }
    }
    
    var image: UIImage? {
        switch self {
        case .mana:
            return UIImage(named: "item2")
        case .gem:
            return UIImage(named: "item1")
        case .shield:
            return UIImage(named: "item3")
        }
    }
}

class ItemViewController: UIViewController {

    @IBOutlet weak var itemView1: UIView!
    @IBOutlet weak var itemView2: UIView!
    @IBOutlet weak var itemView3: UIView!
    
    @IBOutlet weak var item1Button: UIButton!
    @IBOutlet weak var item2Button: UIButton!
    @IBOutlet weak var item3Button: UIButton!
    
    let appScheme = "paymentwallsdkdemo";
    
    public var choosenItem: Item!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        item1Button.setTitle("  "+Item.mana.price, for: UIControlState())
        item2Button.setTitle("  "+Item.gem.price, for: UIControlState())
        item3Button.setTitle("  "+Item.shield.price, for: UIControlState())
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        itemView1.isHidden = false
        itemView2.isHidden = false
        itemView3.isHidden = false
    }
    
    override var preferredInterfaceOrientationForPresentation: UIInterfaceOrientation {
        return .landscapeLeft
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        return .allButUpsideDown
    }
    
    override var shouldAutorotate: Bool {
        return true
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func buttonPressed(_ sender: UIButton) {
        
        switch sender {
        case item1Button:
            choosenItem = Item.mana
        case item2Button:
            choosenItem = Item.gem
        case item3Button:
            choosenItem = Item.shield
        default:
            break
        }
        
        itemView1.isHidden = true
        itemView2.isHidden = true
        itemView3.isHidden = true
        
        //Setup payment, see Payment.swift for demo
        self.setupPaymentwall()
    }
    
    @IBAction func dismissButtonTouch(_ sender: AnyObject) {
        self.dismiss(animated: true, completion: nil)
    }
    
    @IBAction func unwindFromPaymentView(_ segue: UIStoryboardSegue) {
        itemView1.isHidden = false
        itemView2.isHidden = false
        itemView3.isHidden = false
    }
}


