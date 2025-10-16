import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var stk = [Character]()
    var nums = Array(number)
    var remaining = k
    
    for num in nums {
        while !stk.isEmpty && remaining > 0 && stk.last! < num {
            remaining -= 1
            _ = stk.removeLast()
        }
        stk.append(num)
    }
    
    while remaining > 0 {
        _ = stk.removeLast()
        remaining -= 1
    }
    return String(stk)
}