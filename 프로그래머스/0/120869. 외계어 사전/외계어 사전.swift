import Foundation

func solution(_ spell: [String], _ dic: [String]) -> Int {
    // spell에 있는 모든 문자를 Set으로 변환하여 빠른 조회 가능하게 함
    let spellSet = Set(spell)
    let spellCount = spell.count
    
    for word in dic {
        // 단어 길이가 spell 길이와 다르면 건너뜀
        if word.count != spellCount { continue }
        
        // 단어의 각 문자를 Set으로 변환
        let wordSet = Set(word.map { String($0) })
        
        // 두 Set이 동일한지 확인 - O(1) 연산
        if wordSet == spellSet {
            return 1
        }
    }
    
    return 2
}