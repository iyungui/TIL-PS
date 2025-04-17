func solution(_ n:Int) -> Int {
    var v1: Int = 0
    var v2: Int = 1

    for _ in 2...n {
        let v = v1 + v2
        v1 = v2
        v2 = v % 1234567
    }

    return v2
}