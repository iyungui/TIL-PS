import Foundation

func solution(_ strArr:[String]) -> [String] {
    var ret: [String] = []
    for (index, element) in strArr.enumerated() {
        if(index % 2 == 0) {
            ret.append(element.lowercased())
        } else {
            ret.append(element.uppercased())
        }
    }
    return ret
}