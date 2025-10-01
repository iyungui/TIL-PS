import Foundation

func permute<T>(_ arr: [T]) -> [[T]] {
    var ret: [[T]] = []
    var cur: [T] = []
    var used = Array(repeating: false, count: arr.count)
    
    func backtrack() {
        if cur.count == arr.count {
            ret.append(cur)
            return
        }
        for i in 0..<arr.count {
            if used[i] { continue }
            used[i] = true
            cur.append(arr[i])
            backtrack()
            cur.removeLast()
            used[i] = false
        }
    }
    
    backtrack()
    return ret
}

func solution(_ expression:String) -> Int64 {
    var nums: [Int] = []
    var ops:[Character] = []
    var num = ""
    
    for ch in expression {
        if ch.isNumber {
            num += String(ch)
        } else {
            nums.append(Int(num)!)
            ops.append(ch)
            num = ""
        }
    }
    nums.append(Int(num)!)
    
    let priority = permute(Array(Set(ops)))
    
    var ret = 0

    func calc(_ nums: [Int], _ opers: [Character], _ priority: [Character]) -> Int {
        var nums = nums, ops = opers
        
        for prior in priority {
            var i = 0
            while i < ops.count {
                if ops[i] == prior {
                    nums[i] = go(prior, i, nums)
                    nums.remove(at: i + 1)
                    ops.remove(at: i)
                } else {
                    i += 1
                }
            }
        }
        return abs(nums[0])
    }
    
    func go(_ prior: Character, _ i: Int, _ nums: [Int]) -> Int {
        switch prior {
            case "*": return nums[i] * nums[i + 1]
            case "+": return nums[i] + nums[i + 1]
            case "-": return nums[i] - nums[i + 1]
            default: return 0
        }
    }

    for prior in priority {
        let cur = calc(nums, ops, prior)
        ret = max(cur, ret)
    }
    
    return Int64(ret)
}