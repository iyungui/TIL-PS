import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    let t = brown + yellow
    var h: Int
    for w in 3...Int(sqrt(Double(t))) {
        if t % w == 0 { 
            h = t / w
            if (2 * (w + h - 2) == brown) && ((w - 2) * (h - 2) == yellow) {
                return [h, w]
            }
        }
    }
    return [0, 0]
}