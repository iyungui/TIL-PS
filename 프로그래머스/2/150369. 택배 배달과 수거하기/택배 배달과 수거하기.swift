import Foundation

struct House {
    let number: Int
    var quantity: Int
}

func solution(_ cap:Int, _ n:Int, _ deliveries:[Int], _ pickups:[Int]) -> Int64 {
    var result: Int64 = 0
    var stk1 = [House]()
    var stk2 = [House]()

    for (i, d) in deliveries.enumerated() where d > 0 {
        stk1.append(House(number: i + 1, quantity: d))
    }
    for (i, p) in pickups.enumerated() where p > 0 {
        stk2.append(House(number: i + 1, quantity: p))
    }
    
    while !stk1.isEmpty || !stk2.isEmpty {
        let dist = max(stk1.last?.number ?? 0 , stk2.last?.number ?? 0) * 2
        result += Int64(dist)

        var c = cap

        while c > 0 && !stk1.isEmpty {
            let idx = stk1.count - 1
            if stk1[idx].quantity > c {
                stk1[idx].quantity -= c
                c = 0
            }
            else {
                c -= stk1[idx].quantity
                stk1.removeLast()
            }
        }
        c = cap

        while c > 0 && !stk2.isEmpty {
            let idx = stk2.count - 1
            if stk2[idx].quantity > c {
                stk2[idx].quantity -= c
                c = 0
            }
            else {
                c -= stk2[idx].quantity
                stk2.removeLast()
            }
        }
    }

    return result
}
