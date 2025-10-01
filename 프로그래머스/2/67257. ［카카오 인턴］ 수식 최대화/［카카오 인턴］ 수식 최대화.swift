import Foundation

enum Operation: Character {
    case multiple = "*"
    case plus = "+"
    case minus = "-"

    func cal(_ a: Int64, _ b: Int64) -> Int64 {
        switch self {
            case .multiple: return a * b
            case .plus: return a + b
            case .minus: return a - b
            default: return -1
        }
    }
}

func go(_ numbers: [Int64], _ opers: [Character], prior: [Operation]) -> Int64 {
    var nums = numbers, opers = opers

    for p in prior {
        while let idx: Array<Character>.Index = opers.firstIndex(of: p.rawValue) {
            nums[idx] = p.cal(nums[idx], nums[idx + 1])
            nums.remove(at: idx + 1)
            opers.remove(at: idx)
        } 
    }
    return abs(nums[0])
}

func solution(_ expression: String) -> Int64 {
    let numbers = expression.components(separatedBy: ["*", "+", "-"]).map { Int64($0)! }
    let opers = (expression.filter { !$0.isNumber }).map { Character(String($0)) }
    let myOper = "*-+"
    var ret: Int64 = 0

    for first in myOper {
        for second in myOper {
            guard first != second else { continue }
            let third = myOper.filter { $0 != first && $0 != second }[0]
            let cur = go(numbers, opers, prior: [
                Operation(rawValue: first)!,
                Operation(rawValue: second)!,
                Operation(rawValue: third)!,
            ])
            ret = max(cur, ret)
        }
    }

    return ret
}