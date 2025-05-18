import Foundation

let N = Int(readLine()!)!
let nums = readLine()!.components(separatedBy: " ").map { Int($0)! }
var oper = readLine()!.components(separatedBy: " ").map { Int($0)! }
var minResult = Int.max
var maxResult = Int.min

func dfs(idx: Int, ret: Int) {
    if idx == N {
        minResult = min(minResult, ret)
        maxResult = max(maxResult, ret)
        return
    }
    
    for i in 0..<4 {
        if oper[i] > 0 {
            oper[i] -= 1    // 연산자 사용
            var nextRet = ret
            
            switch i {
            case 0: nextRet += nums[idx]
            case 1: nextRet -= nums[idx]
            case 2: nextRet *= nums[idx]
            case 3: nextRet = nextRet < 0 && nums[idx] >= 0 ?  -(-nextRet / nums[idx]) : nextRet / nums[idx]
            default: break
            }
            
            dfs(idx: idx + 1, ret: nextRet)
            
            oper[i] += 1
        }
    }
    return
}

dfs(idx: 1, ret: nums[0])
print(maxResult)
print(minResult)
