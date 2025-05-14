import Foundation

let n = Int(readLine()!)!

// tuple
var arr: [(time: Int, price: Int)] = []

for _ in 0..<n {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    arr.append((line[0], line[1]))
}

func solve(_ day: Int) -> Int {
    // 기저 사례: day가 n을 넘어가는 경우, 0
    if day >= n { return 0 }
    
    // 현재 상담을 하지 않는 경우(다음 날 상담)
    let a = solve(day + 1)
    
    // 현재 day에 상담하는 경우
    var b = 0
    if day + arr[day].time <= n {   // n일까지는 회사에 있으므로 n 포함
        b = arr[day].price + solve(day + arr[day].time)
    }
    
    return max(a, b)
}

print(solve(0))