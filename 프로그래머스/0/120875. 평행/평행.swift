import Foundation

func solution(_ dots:[[Int]]) -> Int {
    let cases = [
        ((0, 1), (2, 3)),
        ((0, 2), (1, 3)),
        ((0, 3), (1, 2))
    ]
    
    for ((a, b), (c, d)) in cases {
        // 기울기 공식
        // (a.y - b.y) / (a.x - b.x) == (c.y - d.y) / (c.x - d.x)
        // 양변에 분모인 (a.x - b.x)(c.x - d.x) 를 곱하면
        // 결국 (a.y - b.y) * (c.x - d.x) == (c.y - d.y) * (a.x - b.x)
        //         y1      *     x2      ==     y2      *     x1
        let y1 = dots[a][1] - dots[b][1]
        let x2 = dots[c][0] - dots[d][0]
        let y2 = dots[c][1] - dots[d][1]
        let x1 = dots[a][0] - dots[b][0]
        
        if y1 * x2 == y2 * x1 {
            return 1
        }
    }
    
    return 0
}