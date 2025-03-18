import Foundation

func solution(_ dots:[[Int]]) -> Int {
//     var minX: Int = Int.max, minY: Int = Int.max, maxX: Int = 0, maxY: Int = 0
    
//     for i in (0..<4) {
//         minX = min(minX, dots[i][0])
//         minY = min(minY, dots[i][1])
//         maxX = max(maxX, dots[i][0])
//         maxY = max(maxY, dots[i][1])
//     }
    
//     return (maxX - minX) * (maxY - minY)
    
    var width: Int = 0, height: Int = 0, pX:Int = dots[0][0], pY:Int = dots[0][1]
    for dot in dots {
        // dot: [Int]
        let x = dot[0], y = dot[1]  // Int
        if abs(x - pX) > 0 {
            width = abs(x - pX)
        }
        if abs(y - pY) > 0 {
            height = abs(y - pY)
        }
        pX = x; pY = y
    }
    return width * height
}