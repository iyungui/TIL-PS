import Foundation

func solution(_ name:String) -> Int {
    var cnt = 0
    for ch in name {
        if ch == "A" { continue }
        let target = Int(ch.asciiValue!) - 65
        cnt += min(target, 26 - target)
    }
    
    // 오른쪽으로 쭉 가는 경우(기본)
    var chars = Array(name)
    let n = chars.count

    var minMove = n - 1
    
    for i in 0..<n {
        // i위치 다음부터 연속된 A의 끝 찾기
        var endA = i + 1
        while endA < n && chars[endA] == "A" { endA += 1 }


        // i까지 갔다가 돌아오는 거리
        let goRight = i * 2
        // 뒤에서부터 endA까지 오는 거리
        let goLeft = (n - endA) * 2

        // i까지 간 후 돌아와서 뒤쪽 끝까지
        minMove = min(minMove, goRight + n - endA)

        // 뒤쪽 먼저 처리하고 앞쪽 i까지
        minMove = min(minMove, goLeft + i)
    }
    
    return cnt + minMove
}
