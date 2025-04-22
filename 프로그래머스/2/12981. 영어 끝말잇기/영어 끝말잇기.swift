import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var s: Set<String> = []
    var prev: Character = words.first!.last!
    // curr = element.
    for (offset, element) in words.enumerated() {
        if offset == 0 {
            // 첫 번째 사람은 무조건 패스
            s.insert(element)
            continue
        }
        
        let curr: Character = element.first!
        
        // 이전에 등장했던 단어라면 또는 앞사람 단어 마지막 문자로 시작하지 않는다면
        if s.contains(element) || prev != curr {
            return [offset % n + 1, offset / n + 1]
        }
        prev = element.last!
        s.insert(element)
    }
    return [0, 0]
}