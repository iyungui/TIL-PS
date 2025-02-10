import Foundation

func solution(_ arr:[Int], _ n:Int) -> [Int] {
//     S1 (함수형)
//     return arr.enumerated().map { (index, value) in
//         let isOddLength = arr.count % 2 == 1
//         return (isOddLength && index % 2 == 0) || (!isOddLength && index % 2 == 1) ? value + n : value
//     }
    
    // S1 클로저 축약
    // return arr.enumerated().map {
    //     if arr.count % 2 == 1 { // arr 길이가 홀수 라면
    //         // 짝수 인덱스 위치 값에 +n
    //         return $0.offset % 2 == 0 ? $0.element + n : $0.element
    //     } else {    // arr 길이가 짝수라면
    //         // 홀수 인덱스 위치 값에 +n
    //         return $0.offset % 2 == 1 ? $0.element + n : $0.element
    //     }
    // }

    
//     S2 (명령형)
//     var result = arr
//     let isOddLength = arr.count % 2 == 1
    
//     for i in arr.indices {
//         if (isOddLength && i % 2 == 0) || (!isOddLength && i % 2 == 1) {
//             result[i] += n
//         }
//     }
//     return result
    
    
    // S3 (stride 사용) -- 필요한 인덱스만 수행 (절반 인덱스)
    var result = arr
    let startIndex = arr.count % 2 == 1 ? 0 : 1
    for i in stride(from: startIndex, to: arr.count, by: 2) {
        result[i] += n
    }
    
    return result
}