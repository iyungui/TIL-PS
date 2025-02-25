import Foundation

func solution(_ ineq:String, _ eq:String, _ n:Int, _ m:Int) -> Int {
    switch ineq {
        case ">":
            if n < m { return 0 } 
            else {
                if eq == "=" { return 1 }
                else {
                    if n > m { return 1 }
                    else { return 0 }
                }
            }
        case "<":
            if n > m { return 0 }
            else {
                if eq == "=" { return 1 }
                else {
                    if n < m { return 1 }
                    else { return 0 }
                }
            }
        default: return 0
    }
}