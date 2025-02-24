import Foundation

func solution(_ num_list:[Int]) -> Int {
    var result = 0
    num_list.forEach { n in
        var num = n
        var cnt = 0
        while(num > 1) {
            
            if(num % 2 == 0) {
                num /= 2
            } else {
                num -= 1
                num /= 2
            }
            cnt += 1
        }
        result += cnt
    }
    return result
}