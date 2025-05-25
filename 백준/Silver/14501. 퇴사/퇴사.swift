import Foundation

let n = Int(readLine()!)!
var arr = [(time: Int, price: Int)]()

for _ in 0..<n {
    let a = readLine()!.components(separatedBy: " ").map { Int($0)! }
    arr.append((time: a[0], price: a[1]))
}

print(solve(0))

func solve(_ day: Int) -> Int {
    // base case: 퇴사일
    if day >= n { return 0 }
    
    // 상담을 하지 않는 경우 (다음 날로 이동)
    let skip: Int = solve(day + 1)
    
    // 상담을 하는 경우
    var take: Int = 0
    let endDate = day + arr[day].time
    if endDate <= n {
        take = arr[day].price + solve(endDate)
    }
    
    return max(skip, take)
}