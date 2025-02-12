import Foundation

func solution(_ arr:[Int]) -> [Int] {
    /* 오답
    return arr.map { 
        if ($0 >= 50 && $0 % 2 == 0) { $0 /= 2 }  // 오류: $0 직접 수정 불가
        else if ($0 < 50 && $0 % 2 == 1) { $0 *= 2}  // 오류: $0 직접 수정 불가
        // 기본 리턴값 누락
    }   
    */
    
    // S1 (오답 수정)       // best
    // return arr.map { 
    //     if ($0 >= 50 && $0 % 2 == 0) { return $0 / 2 }
    //     else if ($0 < 50 && $0 % 2 == 1) { return $0 * 2 }
    //     return $0
    // }
    
    // S2 삼항 연산자 사용
    return arr.map { n in n >= 50 && n % 2 == 0 ? n / 2 : n < 50 && n % 2 == 1 ? n * 2 : n }
}