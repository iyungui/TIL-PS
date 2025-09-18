import Foundation

func solution(_ friends:[String], _ gifts:[String]) -> Int {
    var giftDicts = [String: [String: Int]]()
    var give = [String: Int]()
    var received = [String: Int]()

    for friend in friends {
        give[friend] = 0
        received[friend] = 0
        giftDicts[friend] = [:]
        for other in friends where other != friend {
            giftDicts[friend]![other] = 0
        }
    }

    for gift in gifts {
        let parts = gift.components(separatedBy: " ")
        let (giver, receiver) = (parts[0], parts[1])
        give[giver]! += 1
        received[receiver]! += 1
        giftDicts[giver]![receiver]! += 1
    }
    let n = friends.count
    var cnt = Array(repeating: 0, count: n)

    for i in 0..<n {
        for j in (i + 1)..<n {
            let (a, b) = (friends[i], friends[j])
            let aToB = giftDicts[a]![b]!
            let bToA = giftDicts[b]![a]!

            if aToB > bToA {
                cnt[i] += 1
            } else if aToB < bToA {
                cnt[j] += 1
            } else {
                let aScore = give[a]! - received[a]!
                let bScore = give[b]! - received[b]!
                if aScore == bScore { continue }
                else if aScore > bScore {
                    cnt[i] += 1
                }
                else {
                    cnt[j] += 1
                }
            }
        }
    }

    return cnt.max() ?? 0
}