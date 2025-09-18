import Foundation

func solution(_ fees: [Int], _ records: [String]) -> [Int] {
    var timeDict = [String: Int]()
    var parkingLot = [String: Int]()

    func timeToMinutes(_ time: String) -> Int {
        time.components(separatedBy: ":").reduce(0) { $0 * 60 + Int($1)! }
    }

    func calculate(_ time: Int) -> Int {
        return time <= fees[0] ? fees[1] : fees[1] + Int(ceil(Double(time - fees[0]) / Double(fees[2])) * Double(fees[3]))
    }

    for record in records {
        let parts = record.components(separatedBy: " ")
        let time = timeToMinutes(parts[0])
        let carNumber = parts[1]
        let action = parts[2]

        // 입차
        if action == "IN" {
            parkingLot[carNumber, default: 0] = time
        }
        // 출차
        else if action == "OUT" {
            timeDict[carNumber, default: 0] += time - parkingLot[carNumber]!
            parkingLot.removeValue(forKey: carNumber)
        }
    }
    for (carNumber, time) in parkingLot {
        let lastOutTime = timeToMinutes("23:59")
        timeDict[carNumber, default: 0] += lastOutTime - time
    }
    
    let result = timeDict.map {
        ($0.key, calculate($0.value))
    }

    return result.sorted { $0.0 < $1.0 }.map { $0.1 }
}