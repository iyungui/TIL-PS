import Foundation

func solution(_ keyinput:[String], _ board:[Int]) -> [Int] {
    let dictDirX: [String: Int] = [
        "left": -1,
        "right": 1,
        "up": 0,
        "down": 0
    ]
    let dictDirY: [String: Int] = [
        "left": 0,
        "right": 0,
        "up": 1,
        "down": -1
    ]
    var y = 0, x = 0
    var ny: Int
    var nx: Int
    var my = board[1] / 2, mx = board[0] / 2
    for key in keyinput {
        ny = y + dictDirY[key]!
        nx = x + dictDirX[key]!
        
        if ny >= -my && ny <= my && nx >= -mx && nx <= mx {
            y = ny
            x = nx
        }
    }
    return [x, y]
}