import Foundation

func solution(_ a:Int, _ b:Int) -> Int {
    let sum: Int = Int(String(a) + String(b))!
    let mul: Int = 2 * a * b
    if(sum >= mul) { return sum }
    return mul
}