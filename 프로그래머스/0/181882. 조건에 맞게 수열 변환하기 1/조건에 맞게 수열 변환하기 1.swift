import Foundation

func solution(_ arr:[Int]) -> [Int] {
    arr.map { (num: Int) -> Int in
        if (num >= 50 && num % 2 == 0) { 
            return num / 2
        }
        else if (num < 50 && num % 2 == 1) { 
            return num * 2
        }
        return num
    }
}