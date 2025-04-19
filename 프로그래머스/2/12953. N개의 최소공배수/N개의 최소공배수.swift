func solution(_ arr:[Int]) -> Int {
    arr.reduce(1) { result, num in
        if result == 1 { return num }    // 첫번째 원소인 경우
        return lcm(result, num)
    }
}

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 { return a }
    return gcd(b, a % b)
}

func lcm(_ a: Int, _ b: Int) -> Int {
    return (a * b) / gcd(a, b)
}