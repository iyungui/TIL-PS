import Foundation

func solution(_ s:String) -> Int {
    let a = Array(s)
    let n = a.count
    var result = 0
    
    let match: [Character: Character] = [")": "(", "}": "{", "]": "["]
    
    // 홀수길이는 올바른 괄호문자열 아니므로 early return
    if n % 2 == 1 { return 0 }
    
    // 회전
    for x in 0..<n {
        var stack = [Character]()
        var isValid = true
        
        for i in 0..<n {
            // 원형 인덱스 계산(회전 효과)
            let ch = a[(i + x) % n]
            
            // 닫는 괄호인 경우
            if let open = match[ch] {
                // 스택이 비어있지 않고, 짝이 맞으면 제거
                if stack.last == open {
                    stack.removeLast()
                } else {
                    // 짝이 안 맞거나 스택이 비어있으면 실패
                    isValid = false
                    break
                }
            }
            // 여는 괄호는 스택에 추가
            else { stack.append(ch) }
        }
        
        if isValid && stack.isEmpty { result += 1 }
    }
    return result
}