import Foundation

func solution(_ arr:[Int]) -> Int {
    var currnet = arr
    var cnt = 0
    while true {
        let next = currnet.map { (num: Int) -> Int in
            if num >= 50 && num % 2 == 0 {
                return num / 2
            } else if num < 50 && num % 2 == 1 {
                return num * 2 + 1
            } else {
                return num
            }
        }
        if currnet == next {
            return cnt
        }
        cnt += 1
        
        currnet = next
    }
}