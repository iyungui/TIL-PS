import Foundation

func main() {
    let n = Int(readLine()!)!
    var meetings = [(start: Int, end: Int)]()
    for _ in 0..<n {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        let start = line[0] // 회의 시작 시간
        let end = line[1]   // 회의 종료 시간
        meetings.append((start, end))
    }

    // 종료 시간을 기준으로 오름차순 정렬, 종료 시간이 같다면 시작 시간을 기준으로 오름차순 정렬
    meetings.sort { (m1, m2) -> Bool in
        if m1.end == m2.end {
            return m1.start < m2.start
        } else {
            return m1.end < m2.end
        }
    }
    
    var count = 0          // 최대 회의 개수
    var lastEndTime = 0    // 마지막으로 선택된 회의의 종료 시간
    for meeting in meetings {
        if meeting.start >= lastEndTime {
            count += 1
            lastEndTime = meeting.end
        }
    }
    print(count)
}

main()
