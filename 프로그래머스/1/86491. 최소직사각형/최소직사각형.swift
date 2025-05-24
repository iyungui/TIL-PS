import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var maxW = 0, maxH = 0
    for size in sizes {
        let w = max(size[0], size[1])
        let h = min(size[0], size[1])
        maxW = max(maxW, w); maxH = max(maxH, h)
    }
    return maxW * maxH
}