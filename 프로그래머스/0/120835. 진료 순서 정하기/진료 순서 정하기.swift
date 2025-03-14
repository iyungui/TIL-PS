import Foundation

func solution(_ emergency:[Int]) -> [Int] {
//     var result: [Int] = []
//     let sortedEmergency = emergency.sorted(by: >)
//     for i in emergency {
//         for (offset, element) in sortedEmergency.enumerated() {
//             if element == i {
//                 result.append(offset + 1)
//             }
//         }
//     }

//     return result
    let sortedEmergency = emergency.sorted(by: >)
    let rankDict = Dictionary(uniqueKeysWithValues: sortedEmergency.enumerated().map { (offset, element) in 
        (element, offset + 1)
    })
    
    return emergency.map { rankDict[$0]! }
}

/*

func solution(_ emergency:[Int]) -> [Int] {
    var answer: [Int] = []

    for tmp in emergency {
        answer.append(emergency.filter { $0 > tmp }.count + 1)
    }

    return answer
}
*/