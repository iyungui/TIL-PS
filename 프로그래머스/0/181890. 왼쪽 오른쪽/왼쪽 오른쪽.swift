import Foundation

func solution(_ str_list:[String]) -> [String] {
    for (offset, element) in str_list.enumerated() {
        if element == "l" {
            return Array(str_list[..<offset])
        } else if element == "r" {
            return Array(str_list[(offset + 1)...])
        }
    }
    return []
}