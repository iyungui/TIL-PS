
import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }

let N = input[0], M = input[1]
var arr: [[Int]] = []
for _ in 0..<N {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    arr.append(line)
}

/*
1. 테트로미노 형태 정의

 5가지 기본 테트로미노의 모든 회전/대칭 형태를 2차원 배열로 정의
 각 형태를 좌표로 표현
 */

let tetrominos = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],   // 가로
    [(0, 0), (1, 0), (2, 0), (3, 0)],    // 세로

    [(0, 0), (0, 1), (1, 0), (1, 1)],
    
    [(0, 0), (0, 1), (0, 2), (1, 1)],    // ㅜ
    [(1, 0), (1, 1), (0, 1), (2, 1)],   // ㅓ
    [(1, 0), (1, 1), (1, 2), (0, 1)],   // ㅗ
    [(0, 0), (1, 0), (2, 0), (1, 1)],    // ㅏ

    [(0, 0), (1, 0), (1, 1), (2, 1)],   // s
    [(1, 0), (1, 1), (0, 1), (0, 2)],   // s 90 회전
    [(1, 0), (2, 0), (1, 1), (0, 1)],   // s 대칭
    [(0, 0), (0, 1), (1, 1), (1, 2)],
    
    [(0, 0), (1, 0), (2, 0), (2, 1)],   // L
    [(2, 0), (2, 1), (1, 1), (0, 1)],   // L 좌우 반전
    [(1, 0), (1, 1), (1, 2), (0, 2)],
    [(0, 0), (0, 1), (0, 2), (1, 2)],
    [(0, 0), (0, 1), (1, 0), (2, 0)],
    [(0, 0), (0, 1), (1, 1), (2, 1)],
    [(0, 0), (1, 0), (1, 1), (1, 2)],
    [(0, 0), (0, 1), (0, 2), (1, 0)]
]

var ret = 0

for i in 0..<N {
    for j in 0..<M {
        for tetromino in tetrominos {
            var sum = 0
            var flag = true
            for (dy, dx) in tetromino {
                let ny = i + dy
                let nx = j + dx
                
                if ny < 0 || ny >= N || nx < 0 || nx >= M {
                    flag = false
                    break   // 해당 테트로미노는 더이상 탐색x
                }
                
                sum += arr[ny][nx]
            }
            if flag { ret = max(ret, sum) }
        }
    }
}

print(ret)
