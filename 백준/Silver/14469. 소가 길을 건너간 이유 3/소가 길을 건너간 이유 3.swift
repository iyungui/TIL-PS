import Foundation


func main() {
    let n = Int(readLine()!)!
    var arr = [(Int, Int)]()   // (소 도착 시간, 검문 시간)
    var ret = 0   // 모든 소가 농장에 도착하는 데 걸리는 최소 시간

    for _ in 0..<n {
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        let a = input[0]    // 소 도착 시간
        let b = input[1]    // 검문 시간
        arr.append((a, b))
    }

    // 도착 시간 기준 오름차순 정렬
    arr.sort { $0.0 < $1.0 }

    var currentTime = 0  // 현재 시간

    for (arrivalTime, inspectionTime) in arr {
        // 소가 도착한 시간이 현재 시간보다 늦으면, 현재 시간을 소의 도착 시간으로 갱신
        if arrivalTime > currentTime {
            currentTime = arrivalTime
        }
        // 검문 시간을 더해 현재 시간 갱신
        currentTime += inspectionTime
        // 모든 소가 농장에 도착하는 데 걸리는 최소 시간 갱신
        ret = currentTime
    }

    print(ret)
}

main()  // 15