import Foundation

func solution(_ numbers: [Int], _ hand: String) -> String {
    var ret = ""
    var l = -1, r = -2
    func getDist(_ cur: Int, _ target: Int) -> Int {
        let mp = [[1,2,3],[4,5,6],[7,8,9],[-1,0,-2]]
        var s = (0, 0), e = (0, 0)
        for i in 0..<4 {
            for j in 0..<3 {
                if mp[i][j] == cur { s = (i, j) }
                if mp[i][j] == target { e = (i, j) }
            }
        }
        return abs(s.0 - e.0) + abs(s.1 - e.1)
    }

    for n in numbers {
        switch n {
            case 1, 4, 7: ret += "L"; l = n
            case 3, 6, 9: ret += "R"; r = n
            default:
                let distL = getDist(l, n)
                let distR = getDist(r, n)

                if distL == distR {
                    if hand == "left" {
                        ret += "L"
                        l = n
                    } else {
                        ret += "R"
                        r = n
                    }
                }
                else if distL < distR {
                    ret += "L"; l = n
                }
                else {
                    ret += "R"; r = n
                }
        }
    }
    return ret
}