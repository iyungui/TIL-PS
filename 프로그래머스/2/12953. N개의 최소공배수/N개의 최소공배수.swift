func solution(_ arr:[Int]) -> Int {
    var temp = arr[0]
    
    for num in arr {
        print(num, temp)
        temp = lcm(temp, num)
    }
    
    return temp
}

func lcm(_ a: Int, _ b: Int) -> Int {
    (a * b) / gcd(a, b)
}

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 { return a }
    return gcd(b, a % b)
}