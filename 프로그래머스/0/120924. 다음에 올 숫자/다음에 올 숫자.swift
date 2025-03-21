import Foundation

func solution(_ common:[Int]) -> Int {
    // Calculate first differences
    let diff1 = common[1] - common[0]
    let diff2 = common[2] - common[1]
    
    if diff1 == diff2 {
        // It's an arithmetic sequence (등차수열)
        return common.last! + diff1
    } else {
        // It's a geometric sequence (등비수열)
        let ratio = common[1] / common[0]
        return common.last! * ratio
    }
}