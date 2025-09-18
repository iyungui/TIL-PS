import Foundation

func solution(_ fees: [Int], _ records: [String]) -> [Int] {
    var timeDict: Dictionary<String, Int> = [:]
    var parkingLot: Dictionary<String, String> = [:]

    records.forEach {
        let mp = $0.split(separator: " ").map { String($0) }
        if parkingLot[mp[1]] == nil {
            // key: carNumber, value: time
            parkingLot.updateValue(mp[0], forKey: mp[1])
        } else {
            timeDict[mp[1], default: 0] += parkTime(in: parkingLot[mp[1]]!, out: mp[0])
            parkingLot[mp[1]] = nil
        }
    }
    parkingLot.forEach {
        timeDict[$0.key, default: 0] += parkTime(in: $0.value, out: "23:59")
    }
    var cars: [String] = []
    records.forEach {
        let carNumber = $0.components(separatedBy: " ")[1]
        if !cars.contains(carNumber) {
            cars.append(carNumber)
        }
    }
    return cars.sorted(by: <).map { 
        fee(time: timeDict[$0]!, fees: fees)
    }
}

private func parkTime(in entrance: String, out exit: String) -> Int {
    let inTime = entrance.components(separatedBy: ":").reduce(0) { $0 * 60 + Int($1)! }
    let outTime = exit.components(separatedBy: ":").reduce(0) { $0 * 60 + Int($1)! }
    return outTime - inTime
}

private func fee(time: Int, fees: [Int]) -> Int {
    return time <= fees[0] ? fees[1] : fees[1] + Int(ceil(Double(time - fees[0]) / Double(fees[2])) * Double(fees[3]))
}