import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var prev: Character = words.first!.last!
    var arr: [String] = [words.first!]
    for (offset, element) in words.enumerated() {
        if offset == 0 { continue }
        
        let curr = element.first!

        // 앞사람이 말한 단어의 마지막 문자로 시작하지 않거나, 이전에 등장했던 단어일 경우
        if curr != prev || arr.contains(element) {
            return [(offset % n) + 1, (offset / n) + 1]
        }
        prev = element.last!
        arr.append(element)
    }
    return [0, 0]
}