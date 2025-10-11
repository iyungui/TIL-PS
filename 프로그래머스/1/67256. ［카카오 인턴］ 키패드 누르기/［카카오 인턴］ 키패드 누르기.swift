import Foundation

private func getDist(_ n: Int, _ target: Int) -> Int {
    let mp = [[1,2,3], [4,5,6], [7,8,9], [-1,0,-2]]
    var (y1,y2,x1,x2) = (0,0,0,0)
    for i in 0..<4 {
        for j in 0..<3 {
            if mp[i][j] == n { y1 = i; x1 = j }
            if mp[i][j] == target { y2 = i; x2 = j }
        }
    }
    
    return abs(y1 - y2) + abs(x1 - x2)
}

func solution(_ numbers:[Int], _ hand:String) -> String {
    var ret = ""
    var left = -1, right = -2
    for num in numbers {
        if num == 1 || num == 4 || num == 7 {
            ret += "L"
            left = num
        }
        else if num == 3 || num == 6 || num == 9 {
            ret += "R"
            right = num
        }
        else {
            let l = getDist(left, num)
            let r = getDist(right, num)
            
            if l == r {
                if hand == "left" { ret += "L"; left = num }
                else { ret += "R"; right = num }
            }
            else if l < r { ret += "L"; left = num }
            else { ret += "R"; right = num }
        }
    }
    return ret
}