import Foundation

// 직선의 기울기 구하기
func getSlope(_ point1: [Int], _ point2: [Int]) -> Double {
    let x1 = Double(point1[0]), x2 = Double(point2[0])
    let y1 = Double(point1[1]), y2 = Double(point2[1])
    
    return (y1 - y2) / (x1 - x2)
}

func solution(_ dots:[[Int]]) -> Int {
    let combi = [
        ((0, 1), (2, 3)),
        ((0, 2), (1, 3)),
        ((0, 3), (1, 2))
    ]
    
    for ((a, b), (c, d)) in combi {
        let slope1 = getSlope(dots[a], dots[b])
        let slope2 = getSlope(dots[c], dots[d])
        
        if slope1 == slope2 {
            return 1
        }
    }
    return 0
}