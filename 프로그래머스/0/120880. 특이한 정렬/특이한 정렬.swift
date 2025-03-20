import Foundation

func solution(_ numlist:[Int], _ n:Int) -> [Int] {
    let diffList = numlist.map { (abs($0 - n), $0) }    // (거리, 값)
    
    // (1)거리 기준으로 오름차순,  같으면 값 기준으로 내림차순
    let sortedList = diffList.sorted { ($0.0, $1.1) < ($1.0, $0.1) }
    
    // 튜플에서 값만 출력
    return sortedList.map { $0.1 }
}