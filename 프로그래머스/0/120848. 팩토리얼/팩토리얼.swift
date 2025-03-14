import Foundation

func f(_ n: Int) -> Int {
    if (n <= 1) { return 1 }
    return n * f(n - 1)
}

func solution(_ n:Int) -> Int {
    var num = 0, count = 1
    while num <= n {
        num = f(count)
        count += 1
    }
    return count - 2
}