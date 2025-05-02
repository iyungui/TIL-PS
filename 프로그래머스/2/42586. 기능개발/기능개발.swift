import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var dates: [Int] = []
    for (pro, s) in zip(progresses, speeds) {
        var pro = pro, cnt = 0
        while pro < 100 {
            pro += s
            cnt += 1
        }
        dates.append(cnt)
    }
    print("dates: \(dates)")
    var stk: [Int] = []
    var res: [Int] = []
    for i in dates {
        if stk.isEmpty { stk.append(i) }
        else {
            if stk.first! < i {
                print("\(stk.first)가 \(i)보다 더 작은 경우:", terminator: "")
                res.append(stk.count)
                stk = []
                stk.append(i)
                print(stk)
            } else if stk.first! >= i {
                print("\(stk.first)가 \(i)보다 더 크거나 같은 경우:", terminator: "")
                stk.append(i)
                print(stk)
            }
        }
    }
    if !stk.isEmpty { res.append(stk.count) }
    return res
}