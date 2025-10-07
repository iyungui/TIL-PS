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
        cur = max(cur, arrivalTime)
        cur += inspectionTime
    }

    print(cur)
}

main()