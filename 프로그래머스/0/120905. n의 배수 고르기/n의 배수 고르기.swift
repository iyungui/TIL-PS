import Foundation

func solution(_ n:Int, _ numlist:[Int]) -> [Int] {
    // n의 배수가 아닌 수들을 제거하는 방법 -> n의 배수만 리턴
    return numlist.filter { $0 % n == 0 }
}