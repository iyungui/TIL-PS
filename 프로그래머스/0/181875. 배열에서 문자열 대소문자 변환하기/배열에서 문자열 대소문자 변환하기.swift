import Foundation

func solution(_ strArr:[String]) -> [String] {
    return strArr.enumerated().map { offset, element in
        if offset % 2 == 1 {
            return element.uppercased()
        } else {
            return element.lowercased()
        }
    }
}