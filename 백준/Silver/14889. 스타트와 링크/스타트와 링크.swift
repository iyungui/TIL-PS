import Foundation

// 입력 받기
let n = Int(readLine()!)!
var abilities = [[Int]]()

for _ in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    abilities.append(row)
}

// 최소 능력치 차이
var minDifference = Int.max

// 팀 능력치 계산 함수
func calculateTeamAbility(team: [Int]) -> Int {
    var ability = 0
    for i in 0..<team.count {
        for j in 0..<team.count {
            if i != j {
                ability += abilities[team[i]][team[j]]
            }
        }
    }
    return ability
}

// 조합 함수를 사용한 팀 나누기 (인덱스 기반)
func divideTeams(start: Int, currentTeam: [Int]) {
    // 스타트 팀이 완성된 경우 (n/2명 선택됨)
    if currentTeam.count == n/2 {
        // 링크 팀 구성 (스타트 팀에 속하지 않은 사람들)
        var linkTeam = [Int]()
        for i in 0..<n {
            if !currentTeam.contains(i) {
                linkTeam.append(i)
            }
        }
        
        // 각 팀의 능력치 계산
        let startAbility = calculateTeamAbility(team: currentTeam)
        let linkAbility = calculateTeamAbility(team: linkTeam)
        
        // 능력치 차이 계산 및 최솟값 갱신
        let difference = abs(startAbility - linkAbility)
        minDifference = min(minDifference, difference)
        return
    }
    
    // 조합 생성 (인덱스 기반)
    for i in start..<n {
        var newTeam = currentTeam
        newTeam.append(i)
        divideTeams(start: i + 1, currentTeam: newTeam)
    }
}

// 팀 나누기 시작 (빈 스타트 팀으로 시작)
divideTeams(start: 0, currentTeam: [])

// 결과 출력
print(minDifference)