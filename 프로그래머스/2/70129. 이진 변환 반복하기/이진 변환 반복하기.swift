import Foundation

func solution(_ s:String) -> [Int] {
    // 이진 변환의 횟수
    var cnt = 0
    // 변환 과정에서 제거된 모든 0의 개수
    var cnt2 = 0
    
    var str: String = s
    
    while str != "1" {
        // 0 제거하기
        let c = Array(str).filter { $0 != "0" }.count
        cnt2 += (str.count - c)

        // c 를 이진법으로 표현한 문자열로 바꾸기
        str = String(c, radix: 2)
        print(str)
        cnt += 1
    }
    return [cnt, cnt2]
}