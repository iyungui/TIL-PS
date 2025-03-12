import Foundation

func solution(_ hp:Int) -> Int {
    // return (hp / 5) + (hp % 5 / 3) + (hp % 5 % 3)
    
    var result = 0
    var hp = hp
    for i in [5, 3, 1] {
        result += hp / i
        hp %= i
    }
    return result
}
