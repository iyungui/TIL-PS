import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [Int] {
    // return num_list[0..<n].map { $0 }
    
    return Array(num_list.prefix(n))     
    // 왜 Array 로 묶어야 하는지? => prefix의 반환타입은 ArraySlice<Int> 형임. 이것은 원본 배열을 "참조"하는 것으로, 원본 배열이 변경되면 같이 변경됨. 보통 완전하게 사용하기 위해, Array로 형변환 하여 사용함.
    
    // return Array(num_list[0..<n])
}