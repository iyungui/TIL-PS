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
            
            for (discount, emoticonCost) in zip(discounts, emoticons) {
                if userDiscount > discount { continue }
                let discounted = emoticonCost * (100 - discount) / 100
                userTotalSales += discounted
                if userTotalSales >= userTotalMoney {
                    curPlusCount += 1
                    userTotalSales = 0
                    break
                }
            }
            curSales += userTotalSales
        }
        
        // 현재 이모티콘 플러스 가입자수가 더 많다면 업데이트
        if maxPlusCount < curPlusCount {
            maxPlusCount = curPlusCount
            maxSales = curSales
        }
        // 그게 아니라면, 가입자수는 같고 현재 판매액이 더 크다면 업데이트
        else if maxPlusCount == curPlusCount && maxSales < curSales {
            maxSales = curSales
        }
        // 그외는 업데이트 x
    }

    for mask in 0..<(1 << (2 * n)) {
        var discounts = [Int]()
        
        for i in 0..<n {
            let shift = i * 2
            let value = (mask >> shift) & 0b11  // 2비트 추출
            discounts.append(rates[value])
        }
        
        go(discounts)
    }
    
    return [maxPlusCount, maxSales]
}