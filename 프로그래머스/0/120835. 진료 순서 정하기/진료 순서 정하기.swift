import Foundation

func solution(_ emergency:[Int]) -> [Int] {
    var result: [Int] = []
    let sortedEmergency = emergency.sorted(by: >)
    for i in emergency {
        for (offset, element) in sortedEmergency.enumerated() {
            if element == i {
                result.append(offset + 1)
            }
        }
    }

    return result
}