let n = Int(readLine()!)!
var arr = [(Int, Int)]()
for _ in 0..<n {
    let a = readLine()!.split(separator: " ").map { Int($0)! }
    arr.append((a[0], a[1]))
}
var (end, cnt) = (0, 0)
arr.sort { $0.1 == $1.1 ? $0.0 < $1.0 : $0.1 < $1.1 }
for m in arr where m.0 >= end { end = m.1; cnt += 1 }
print(cnt)