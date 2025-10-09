import Foundation

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    let rates = [10, 20, 30, 40]
    let n = emoticons.count
    
    var maxPlusCount = 0
    var maxSales = 0
    
    func go(_ discounts: [Int]) {
        var curSales = 0
        var curPlusCount = 0
        
        for user in users {
            let userDiscount = user[0]
            let userTotalMoney = user[1]
            var userTotalSales = 0
            var plus = false
            
            for (discount, emoticonCost) in zip(discounts, emoticons) {
                if userDiscount > discount { continue }
                userTotalSales += emoticonCost * (100 - discount) / 100
                if userTotalSales >= userTotalMoney {
                    plus = true
                    userTotalSales = 0
                    break
                }
            }
            if plus { curPlusCount += 1 }
            curSales += userTotalSales
        }
        
        // 현재 이모티콘 플러스 가입자수가 더 많다면 업데이트
        if maxPlusCount < curPlusCount {
            maxPlusCount = curPlusCount
            maxSales = curSales
        }
        // 그게 아니라면, 가입자수는 같고 현재 판매액이 더 크다면 업데이트
        else if maxPlusCount == curPlusCount && maxSales < curSales {
            maxPlusCount = curPlusCount
            maxSales = curSales
        }
        // 그외는 업데이트 x
    }
    
    let totalCases = Int(pow(4.0, Double(n)))   // 1 << (2 * n)과 동일
    
    for i in 0..<totalCases {
        var discounts = [Int]()
        var num = i
        
        for _ in 0..<n {
            discounts.append(rates[num % 4])
            num /= 4
        }
        
        go(discounts)
    }
    
    return [maxPlusCount, maxSales]
}