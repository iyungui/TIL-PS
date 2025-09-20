import Foundation

func solution(_ commands: [String]) -> [String] {
    var result: [String] = []
    var merged = Array(repeating: Array(repeating: (0, 0), count: 50), count: 50)
    var arr = Array(repeating: Array(repeating: "EMPTY", count: 50), count: 50)
    
    func update(r: Int, c: Int, value: String) {
        let (y, x) = merged[r][c]
        arr[y][x] = value
    }

    func update(val1: String, val2: String) {
        for i in 0..<50 {
            for j in 0..<50 {
                if arr[i][j] == val1 { arr[i][j] = val2 }
            }
        }
    }

    func merge(r1: Int, c1: Int, r2: Int, c2: Int) {
        if r1 == r2 && c1 == c2 { return }
        let (y1, x1) = merged[r1][c1]
        let (y2, x2) = merged[r2][c2]
        if y1 == y2 && x1 == x2 { return }

        if arr[y1][x1] == "EMPTY" && arr[y2][x2] != "EMPTY" {
            arr[y1][x1] = arr[y2][x2]
        }

        // merged의 모든 (y2, x2)를 (y1, x1)으로 변경
        for i in 0..<50 {
            for j in 0..<50 {
                if merged[i][j] == (y2, x2) {
                    merged[i][j] = (y1, x1)
                }
            }
        }

        arr[y2][x2] = "EMPTY"
    }

    func unmerge(r: Int, c: Int) {
        let (y, x) = merged[r][c]
        let temp = arr[y][x]

        for i in 0..<50 {
            for j in 0..<50 {
                if merged[i][j] == (y, x) {
                    merged[i][j] = (i, j)
                    arr[i][j] = "EMPTY"
                }
            }
        }
        arr[r][c] = temp
    }

    func print(r: Int, c: Int) {
        let (y, x) = merged[r][c]
        result.append(arr[y][x])
    }
    
    for i in 0..<50 {
        for j in 0..<50 {
            merged[i][j] = (i, j)
        }
    }

    for command in commands {
        let com = command.components(separatedBy: " ")
        let a = com[0]

        if a == "UPDATE" {
            if com.count == 4 {
                update(r: Int(com[1])! - 1, c: Int(com[2])! - 1, value: com[3])
            } else {
                update(val1: com[1], val2: com[2])
            }
        }
        else if a == "MERGE" {
            merge(r1: Int(com[1])! - 1, c1: Int(com[2])! - 1, r2: Int(com[3])! - 1, c2: Int(com[4])! - 1)
        }
        else if a == "UNMERGE" {
            unmerge(r: Int(com[1])! - 1, c: Int(com[2])! - 1)
        }
        else if a == "PRINT" {
            print(r: Int(com[1])! - 1, c: Int(com[2])! - 1)
        }
    }

    return result
}