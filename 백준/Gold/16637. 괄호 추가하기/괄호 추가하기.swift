import Foundation

func solution() {
    let _ = Int(readLine()!)!
    let line = readLine()!
    var operList: [Character] = []
    var numList: [Int] = []

    for (idx, ch) in line.enumerated() {
        if idx % 2 == 0 {
            numList.append(Int(String(ch))!)
        } else {
            operList.append(ch)
        }
    }
    var ret = Int.min

    func calculate(_ oper: Character, _ num1: Int, _ num2: Int) -> Int {
        if oper == "+" { return num1 + num2 }
        else if oper == "-" { return num1 - num2 }
        else { return num1 * num2 }
    }

    func go(_ idx: Int, _ sum: Int) {
        if idx == numList.count - 1 {
            ret = max(ret, sum)
            return
        }
        go(idx + 1, calculate(operList[idx], sum, numList[idx + 1]))

        if (idx + 2) < numList.count {
            let s = calculate(operList[idx + 1], numList[idx + 1], numList[idx + 2])
            go(idx + 2, calculate(operList[idx], sum, s))
        }
    }

    go(0, numList[0])

    print(ret)
}

_ = solution()