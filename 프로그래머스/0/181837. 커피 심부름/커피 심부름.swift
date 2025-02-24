import Foundation

func solution(_ order:[String]) -> Int {
    // 아무거나, 아메리카노 -> 4500
    // 카페라떼 -> 5000
    var result = 0
    order.forEach {
        if($0.contains("americano") || $0.contains("anything")) {
            result += 4500
        } else if($0.contains("cafelatte")) {
            result += 5000
        }
    }
    return result
}