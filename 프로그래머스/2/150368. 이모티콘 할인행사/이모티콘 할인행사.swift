import Foundation

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    var maxPlus = 0, maxSales = 0
    let rates = [10, 20, 30, 40]
    
    func combi(_ idx: Int, _ cur: [Int]) {
        if idx == emoticons.count {
            go(cur)
            return
        }
        
        for rate in rates {
            combi(idx + 1, cur + [rate])
        }
    }
    
    func go(_ discounts: [Int]) {
        var curPlus = 0
        var curSales = 0
        
        for user in users {
            let userRate = user[0]
            var userMoney = user[1]
            var userTotalSales = 0
            
            for i in 0..<emoticons.count {
                if userRate <= discounts[i] {
                    userTotalSales += emoticons[i] * (100 - discounts[i]) / 100
                }
            }
            
            if userMoney <= userTotalSales {
                curPlus += 1
            } else {
                curSales += userTotalSales
            }
        }
        
        // 해당 조합에서, maxPlus, maxSales 업데이트
        if maxPlus < curPlus || (maxPlus == curPlus && maxSales < curSales) {
            maxPlus = curPlus
            maxSales = curSales
        }
    }
    
    combi(0, [])
    
    return [maxPlus, maxSales]
}