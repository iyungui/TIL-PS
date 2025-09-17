import Foundation

func main() {
    let n = Int(readLine()!)!
    let signs = readLine()!.split(separator: " ").map { String($0) }
    
    var visited = Array(repeating: false, count: 10)
    
    // 부등호 조건 체크
    func isGood(_ op: String, _ x: Int, _ y: Int) -> Bool {
        if op == "<" && x < y { return true }
        if op == ">" && x > y { return true }
        return false
    }
    
    // 백트래킹 (최댓값용: 큰 수부터, 최솟값용: 작은 수부터)
    func solve(_ idx: Int, _ num: String, _ findMax: Bool) -> String? {
        if idx == n + 1 {
            return num
        }
        
        let range = findMax ? (0...9).reversed() : Array(0...9)
        
        for i in range {
            if idx == 0 || (!visited[i] && isGood(signs[idx - 1], Int(String(num.last!))!, i)) {
                visited[i] = true
                if let result = solve(idx + 1, num + String(i), findMax) {
                    return result
                }
                visited[i] = false
            }
        }
        
        return nil
    }
    
    // 최댓값 찾기
    visited = Array(repeating: false, count: 10)
    let maxResult = solve(0, "", true)!
    
    // 최솟값 찾기  
    visited = Array(repeating: false, count: 10)
    let minResult = solve(0, "", false)!
    
    print(maxResult)
    print(minResult)
}

main()