import Foundation

func solution(_ places:[[String]]) -> [Int] {
    var result = [Int]()
    
    for place in places {
        let room = place.map { Array($0) }
        result.append(isDistanceOk(room) ? 1 : 0)
    }
    
    return result
}

private func isDistanceOk(_ room: [[Character]]) -> Bool {
    // 모든 P(응시자) 위치 찾기
    var people: [(Int, Int)] = []
    for i in 0..<5 {
        for j in 0..<5 {
            if room[i][j] == "P" {
                people.append((i, j))
            }
        }
    }
    
    // 모든 응시자 쌍에 대해 거리두기 확인
    for i in 0..<people.count {
        for j in i+1..<people.count {
            let person1 = people[i]
            let person2 = people[j]
            
            let manhattanDistance = abs(person1.0 - person2.0) + abs(person1.1 - person2.1)
            
            // 맨해튼 거리가 2 이하인 경우만 검사
            if manhattanDistance <= 2 {
                if !isBlocked(room, person1, person2) {
                    return false
                }
            }
        }
    }
    
    return true
}

private func isBlocked(_ room: [[Character]], _ p1: (Int, Int), _ p2: (Int, Int)) -> Bool {
    let (r1, c1) = p1
    let (r2, c2) = p2
    
    let manhattanDistance = abs(r1 - r2) + abs(c1 - c2)
    
    // 맨해튼 거리가 1인 경우 (바로 인접) - 무조건 위반
    if manhattanDistance == 1 {
        return false
    }
    
    // 맨해튼 거리가 2인 경우 - 중간에 파티션이 있는지 확인
    if manhattanDistance == 2 {
        // 같은 행에 있는 경우 (가로로 한 칸 떨어짐)
        if r1 == r2 {
            let midCol = (c1 + c2) / 2
            return room[r1][midCol] == "X"
        }
        // 같은 열에 있는 경우 (세로로 한 칸 떨어짐)
        else if c1 == c2 {
            let midRow = (r1 + r2) / 2
            return room[midRow][c1] == "X"
        }
        // 대각선으로 떨어진 경우 - 두 경로 모두 막혀있어야 함
        else {
            let blocked1 = room[r1][c2] == "X"
            let blocked2 = room[r2][c1] == "X"
            return blocked1 && blocked2
        }
    }
    
    // 맨해튼 거리가 2보다 큰 경우는 항상 OK
    return true
}