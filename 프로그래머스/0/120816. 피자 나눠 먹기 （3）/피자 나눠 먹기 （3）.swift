import Foundation

func solution(_ slice:Int, _ n:Int) -> Int {
    // var cnt = 1, s = slice
    // while s < n {
    //     cnt += 1
    //     s += slice
    // }
    // return cnt
    
    // return Int(ceil(Double(n / slice)))
    
    return n % slice == 0 ? n / slice : n / slice + 1
}