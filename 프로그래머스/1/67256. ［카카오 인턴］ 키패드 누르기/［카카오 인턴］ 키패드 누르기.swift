import Foundation

func solution(_ numbers: [Int], _ hand: String) -> String {

    func getPos(_ num: Int) -> (Int, Int) {
        switch num {
            case 1: return (0, 0)
            case 2: return (0, 1)
            case 3: return (0, 2)
            case 4: return (1, 0)
            case 5: return (1, 1)
            case 6: return (1, 2)
            case 7: return (2, 0)
            case 8: return (2, 1)
            case 9: return (2, 2)
            case 0: return (3, 1)
            default: return (0, 0)
        }
    }

    func getDist(_ pos1: (Int, Int), _ pos2: (Int, Int)) -> Int {
        return abs(pos1.0 - pos2.0) + abs(pos1.1 - pos2.1)
    }

    var leftPos = (3, 0)
    var rightPos = (3, 2)
    var ret = ""

    for num in numbers {
        if num == 1 || num == 4 || num == 7 {
            ret += "L"; leftPos = getPos(num)
        }
        else if num == 3 || num == 6 || num == 9 {
            ret += "R"; rightPos = getPos(num)
        }
        else {
            let targetPos = getPos(num)
            let leftDist = getDist(leftPos, targetPos)
            let rightDist = getDist(rightPos, targetPos)

            if leftDist < rightDist {
                ret += "L"; leftPos = targetPos
            }
            else if leftDist > rightDist {
                ret += "R"; rightPos = targetPos
            }
            else {
                if hand == "left" { ret += "L"; leftPos = targetPos }
                else { ret += "R"; rightPos = targetPos }
            }
        }
    }

    return ret
}