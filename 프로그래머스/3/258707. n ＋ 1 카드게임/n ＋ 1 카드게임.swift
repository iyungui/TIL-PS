import Foundation

func solution(_ coin:Int, _ cards:[Int]) -> Int {
    let n = cards.count
    let target = n + 1
    var coin = coin
    var cardIdx = n / 3
    // 손에 담고있는 카드들 배열 a
    // 뽑은 카드 중 아직 사용하지 않은 카드들 배열 b
    var a = Set(cards.prefix(cardIdx))
    var b = Set<Int>()
    var round = 0

    while true {
        round += 1
        if cardIdx + 1 >= n {
            break
        }
        // 카드 뽑기
        b.insert(cards[cardIdx])
        b.insert(cards[cardIdx + 1])
        cardIdx += 2
        var flag = false
        
        // 0 순위: 가지고 있는 카드 a 배열에서 target 만들 수 있는 경우
        for card1 in a {
            let card2 = target - card1
            if card1 != card2 && a.contains(card2) {
                a.remove(card1)
                a.remove(card2)
                
                flag = true
                break
            }
        }
        
        // 1 순위: 가지고 있는 카드 배열에서 하나, b 배열에서 하나 (코인 1개 사용)로 target
        if !flag && coin >= 1 {
            for card1 in a {
                let card2 = target - card1
                if card1 != card2 && b.contains(card2) {
                    coin -= 1
                    
                    a.remove(card1)
                    b.remove(card2)
                    
                    flag = true
                    break
                }
            }
        }
        
        // 2 순위: b 배열에서 두 개로 (코인 2개 사용) target
        if !flag && coin >= 2 {
            for card1 in b {
                let card2 = target - card1
                if card1 != card2 && b.contains(card2) {
                    coin -= 2
                    b.remove(card1)
                    b.remove(card2)
                    
                    flag = true
                    break
                }
            }
        }
        
        if !flag { break }  // 게임 종료
    }
    
    return round
}