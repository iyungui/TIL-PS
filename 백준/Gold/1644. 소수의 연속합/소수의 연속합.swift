import Foundation

func solve(_ n: Int) -> Int {
    if n < 2 { return 0 }

    var isPrime = Array(repeating: true, count: n + 1)
    isPrime[0] = false
    isPrime[1] = false

    var primes = [Int]()
    primes.reserveCapacity(n / 10)
    for i in 2...n {
        if isPrime[i] {
            primes.append(i)
            
            if i * i <= n {
                for j in stride(from: i * i, through: n, by: i) {
                    isPrime[j] = false
                }
            }
        }
    }

    if primes.isEmpty { return 0 }

    var count = 0
    var sum = 0
    var right = 0

    for left in 0..<primes.count {
        // 구간 합이 n보다 작으면 right 이동
        while right < primes.count && sum < n {
            sum += primes[right]
            right += 1
        }
        if sum == n {
            count += 1
        }

        sum -= primes[left]
    }

    return count
}

if let input = readLine(), let n = Int(input) {
    print(solve(n))
}