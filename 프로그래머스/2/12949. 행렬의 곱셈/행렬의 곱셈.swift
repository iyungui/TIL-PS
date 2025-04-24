import Foundation
func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    let rowCount = arr1.count
    let colCount = arr2[0].count
    let commonDimension = arr2.count  // arr1의 열 수와 arr2의 행 수는 같아야 함
    
    var res = Array(repeating: Array(repeating: 0, count: colCount), count: rowCount)
    
    for i in 0..<rowCount {
        for j in 0..<colCount {
            for k in 0..<commonDimension {
                res[i][j] += arr1[i][k] * arr2[k][j]
            }
        }
    }
    
    return res
}