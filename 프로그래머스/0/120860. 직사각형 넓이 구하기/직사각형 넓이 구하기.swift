import Foundation

func solution(_ dots:[[Int]]) -> Int {
    // let xValues = dots.map { $0[0] }
    // let yValues = dots.map { $0[1] }
    // let width = xValues.max()! - xValues.min()!
    // let height = yValues.max()! - yValues.min()!
    // return width * height
    
    // tuple sort (x와 y 정렬)
    let dots = dots.sorted(by: { ($0[0], $0[1]) < ($1[0], $1[1]) })
    return (dots.last![0] - dots.first![0]) * (dots.last![1] - dots.first![1])
}