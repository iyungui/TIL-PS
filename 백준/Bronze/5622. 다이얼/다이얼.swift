
import Foundation

func main() {
    let str = readLine()!
    
    let dict: [Int: [Character]] = [
        1: [],
        2: ["A", "B", "C"],
        3: ["D", "E", "F"],
        4: ["G", "H", "I"],
        5: ["J", "K", "L"],
        6: ["M", "N", "O"],
        7: ["P", "Q", "R", "S"],
        8: ["T", "U", "V"],
        9: ["W","X", "Y", "Z"],
        0: []
    ]
    
    var time = 0
    
    for ch in str {
        for i in 0..<10 {
            if dict[i]!.contains(ch) {
                time += (i + 1)
            }
        }
    }
    
    print(time)
}

main()