import Foundation

// func solution(_ balls:Int, _ share:Int) -> Int {
//     let min = balls - share < share ? balls - share : share
//     var result: Double = 1
    
//     for i in 0..<min {
//         result *= Double(balls - i) / Double(i + 1)
//     }
    
//     return Int(round(result))
// }



func solution(_ balls:Int, _ share:Int) -> Int {
    var result = (balls - share + 1...balls)
        .map { Double($0) }
        .reduce(1.0, *)

    (1...share)
        .map { result /= Double($0) }

    return Int(result)
}