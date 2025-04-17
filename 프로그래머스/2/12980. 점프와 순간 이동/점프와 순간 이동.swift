import Foundation

func solution(_ n:Int) -> Int {
/*
    N이 짝수일 경우, N/2 위치에서 순간이동 하면 N에 도달할 수 있음
N이 홀수일 경우, (N-1)/2 위치에서 순간이동한 후 1칸 점프하거나, (N+1)/2 위치에서 순간이동 후 1칸 뒤로 가야 함 (뒤로 가는 건 불가능하므로 앞으로 1칸 점프)    
*/
    var n = n
    var jump = 0
    while n > 0 {
        if n % 2 == 0 {
            n /= 2  // 순간이동
        } else {
            n -= 1; jump += 1   // 점프
        }
    }
    return jump
}