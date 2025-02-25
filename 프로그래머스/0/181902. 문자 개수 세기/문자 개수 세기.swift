import Foundation

func solution(_ my_string:String) -> [Int] {
    var result = Array(repeating: 0, count: 52)
    my_string.forEach { c in
        if c.isUppercase {
            result[Int(c.asciiValue! - Character("A").asciiValue!)] += 1
        } else {
            result[Int(c.asciiValue! - Character("a").asciiValue!) + 26] += 1
        }
    }
    return result
}

/*
    for c in my_string {
        if let asciiValue = c.asciiValue {
            if asciiValue >= 97 {   // 소문자
                let index = Int(asciiValue - 97 + 26)
                result[index] += 1
            } else {
                let index = Int(asciiValue - 65)
                result[index] += 1
            }
        }
    }
*/
