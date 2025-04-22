import Foundation

func solution(_ elements:[Int]) -> Int {
    let n = elements.count
    var psum = Array(repeating: 0, count: n * 2 + 1)
    var res = Set<Int>()
    
    // make prefix sum
    for i in 0..<2*n {
        // psum[0] = 0, psum[1] = elements[0], psum[2] = psum[1] + elements[1]..
        psum[i + 1] = psum[i] + elements[i % n]
    }
    
    // calculate prefix sum
    for length in 1...n {
        for start in 0..<n {
            let sum = psum[start + length] - psum[start]
            res.insert(sum)
        }
    }
    
    return res.count
}