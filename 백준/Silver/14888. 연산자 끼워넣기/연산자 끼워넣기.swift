import Foundation

let n = Int(readLine()!)!
let nums = readLine()!.components(separatedBy: " ").map { Int($0)! }

// +, -, *, /
var oper = readLine()!.components(separatedBy: " ").map { Int($0)! }


var minR = Int.max, maxR = Int.min

func go(idx: Int, ret: Int) {
    if idx == n {
        minR = min(minR, ret)
        maxR = max(maxR, ret)
        return
    }
    
    for i in 0..<4 {
        if oper[i] > 0 {
            oper[i] -= 1
            var nextRet = ret
            
            switch i {
            case 0: nextRet += nums[idx]
            case 1: nextRet -= nums[idx]
            case 2: nextRet *= nums[idx]
            case 3: nextRet = nextRet < 0 && nums[idx] >= 0 ? -(-nextRet / nums[idx]) : nextRet / nums[idx]
            default: break
            }
            
            go(idx: idx + 1, ret: nextRet)
            
            oper[i] += 1
        }
    }
}

go(idx: 1, ret: nums[0])

print(maxR)
print(minR)