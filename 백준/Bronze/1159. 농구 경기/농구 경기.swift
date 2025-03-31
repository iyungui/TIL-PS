import Foundation

let n = Int(readLine()!)!

var players: [String] = []

for _ in 0..<n {
    let temp = readLine()!
    players.append(temp)
}

var counts: [Character: Int] = [:]

for player in players {
    counts[player.first!, default: 0] += 1
}

let answer = counts.filter { $0.value >= 5 }.keys.sorted().map { String($0) }.joined()

answer.count > 0 ? print(answer) : print("PREDAJA")