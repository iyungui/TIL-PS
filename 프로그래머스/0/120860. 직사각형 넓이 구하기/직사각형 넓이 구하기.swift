import Foundation

func solution(_ dots:[[Int]]) -> Int {
    let xValues = dots.map { $0[0] }
    let yValues = dots.map { $0[1] }
    let width = xValues.max()! - xValues.min()!
    let height = yValues.max()! - yValues.min()!
    return width * height
}