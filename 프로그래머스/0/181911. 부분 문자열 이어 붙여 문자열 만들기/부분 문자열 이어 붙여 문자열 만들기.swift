import Foundation

func solution(_ my_strings:[String], _ parts:[[Int]]) -> String {
    return zip(my_strings, parts).map {
        String($0.0.prefix($0.1[1] + 1).suffix($0.1[1] - $0.1[0] + 1))
    }.joined()
}