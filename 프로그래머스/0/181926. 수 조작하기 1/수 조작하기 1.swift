import Foundation

func solution(_ n:Int, _ control:String) -> Int {
    var answer = n
    control.map { str in
        if(str == "w") {
            answer += 1
        } else if(str == "s") {
            answer -= 1
        } else if(str == "d") {
            answer += 10
        } else if(str == "a") {
            answer -= 10
        }
    }
    return answer
}