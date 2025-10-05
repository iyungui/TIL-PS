func solution(_ stones:[Int], _ k:Int) -> Int {
    var left = 1
    var right = 200_000_000
    
    while left <= right {
        let mid = (left + right) / 2
        var cnt = 0
        var canCross = true
        for i in 0..<stones.count {
            if stones[i] - mid <= 0 { cnt += 1 }
            else { cnt = 0 }
            if cnt >= k { canCross = false; break }
        }
        if canCross { left = mid + 1 }
        else { right = mid - 1 }
    }
    
    return left
}
