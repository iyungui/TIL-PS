func solution(_ elements: [Int]) -> Int {
    let n = elements.count
    var sums = Set<Int>()
    
    // 원형 수열을 처리하기 위해 배열을 두 번 연결
    let circular = elements + elements
    
    // 길이가 1부터 n까지인 모든 연속 부분 수열의 합을 구함
    for length in 1...n {
        for start in 0..<n {
            var sum = 0
            for i in 0..<length {
                sum += circular[start + i]
            }
            sums.insert(sum)
        }
    }
    
    return sums.count
}