import Foundation

// 입력 처리
let n = Int(readLine()!)!
let numbers = readLine()!.split(separator: " ").map { Int($0)! }
var operators = readLine()!.split(separator: " ").map { Int($0)! }
// 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷) 순서

var maxResult = Int.min
var minResult = Int.max

// 백트래킹 함수
func dfs(index: Int, result: Int) {
    // 모든 수를 다 사용했을 때
    if index == n {
        maxResult = max(maxResult, result)
        minResult = min(minResult, result)
        return
    }
    
    // 각 연산자에 대해 시도
    for i in 0..<4 {
        // 해당 연산자가 남아있으면
        if operators[i] > 0 {
            operators[i] -= 1  // 연산자 사용
            
            var nextResult = result
            
            // 연산 수행
            switch i {
            case 0: // 덧셈
                nextResult += numbers[index]
            case 1: // 뺄셈
                nextResult -= numbers[index]
            case 2: // 곱셈
                nextResult *= numbers[index]
            case 3: // 나눗셈
                // C++14 기준 나눗셈 처리
                if nextResult < 0 {
                    nextResult = -(-nextResult / numbers[index])
                } else {
                    nextResult /= numbers[index]
                }
            default:
                break
            }
            
            // 다음 수로 진행
            dfs(index: index + 1, result: nextResult)
            
            // 백트래킹 (연산자 복원)
            operators[i] += 1
        }
    }
}

// DFS 시작 (첫 번째 수는 결과값으로 초기화)
dfs(index: 1, result: numbers[0])

// 결과 출력
print(maxResult)
print(minResult)
