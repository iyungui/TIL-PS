import Foundation

func main() {
    let n = Int(readLine()!)!
    var arr = [(Int, Int)]()
    for _ in 0..<n {
        let a = readLine()!.split(separator: " ").map { Int($0)! }
        arr.append((a[0], a[1]))
    }
    arr.sort { $0.0 < $1.0 }
    var cur = 0

    for (arrivalTime, inspectionTime) in arr {
        // 만약 현재 시간이 소의 도착시간보다 빠르다면, 현재 시간 업데이트
        if arrivalTime > cur { cur = arrivalTime }

        // 소의 검문시간 추가
        cur += inspectionTime
    }

    print(cur)
}

main()