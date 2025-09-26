let a = readLine()!.split(separator: " ").map { Int($0)! }
let b = [1, 1, 2, 2, 2, 8]

for (i, j) in zip(a, b) {
    print(j - i, terminator: " ")
}