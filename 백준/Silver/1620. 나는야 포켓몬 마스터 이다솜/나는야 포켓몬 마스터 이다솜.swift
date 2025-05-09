import Foundation

// 입력에서 N과 M을 받음
let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let N = input[0], M = input[1]

// 포켓몬 이름을 인덱스로 빠르게 찾기 위한 딕셔너리
var nameToNumber: [String: Int] = [:]
// 포켓몬 번호로 이름을 빠르게 찾기 위한 배열 (인덱스 = 포켓몬 번호 - 1)
var numberToName: [String] = []

// N개의 포켓몬 정보 입력 받기
for i in 1...N {
    let pokemonName = readLine()!
    nameToNumber[pokemonName] = i
    numberToName.append(pokemonName)
}

// M개의 문제 처리
for _ in 0..<M {
    let query = readLine()!
    
    // 입력이 숫자인지 확인
    if let number = Int(query) {
        // 숫자가 입력된 경우 해당 번호의 포켓몬 이름 출력
        // 배열은 0부터 시작하므로 number - 1을 인덱스로 사용
        print(numberToName[number - 1])
    } else {
        // 이름이 입력된 경우 해당 이름의 포켓몬 번호 출력
        print(nameToNumber[query]!)
    }
}