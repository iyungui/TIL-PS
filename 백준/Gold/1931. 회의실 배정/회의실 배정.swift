import Foundation

func main() {
    let n = Int(readLine()!)!
    var meetings: [(start: Int, end: Int)] = [(Int, Int)]()

    for _ in 0..<n {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        meetings.append((start: line[0], end: line[1]))
    }
    
    meetings.sort { $0.end == $1.end ? $0.start < $1.start : $0.end < $1.end }

    var lastEndTime = 0
    var cnt = 0

    for meeting in meetings {
        if meeting.start >= lastEndTime {
            lastEndTime = meeting.end
            cnt += 1
        }
    }

    print(cnt)
}

main()