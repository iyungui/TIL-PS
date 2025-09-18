import Foundation

func solution(_ fees: [Int], _ records: [String]) -> [Int] {
    var parkingInfo: [String: Int] = [:] // 차량 번호별 입차 시간
    var totalTimes: [String: Int] = [:] // 차량 번호별 총 주차 시간

    func convertToMinutes(_ time: String) -> Int {
        let parts = time.split(separator: ":").map { Int($0)! }
        return parts[0] * 60 + parts[1]
    }

    for record in records {
        let parts = record.components(separatedBy: " ")
        let time = parts[0]
        let carNumber = parts[1]
        let action = parts[2]
        let timeInMinutes = convertToMinutes(time)

        if action == "IN" {
            parkingInfo[carNumber] = timeInMinutes
        } else if action == "OUT" {
            if let inTime = parkingInfo[carNumber] {
                let duration = timeInMinutes - inTime
                totalTimes[carNumber, default: 0] += duration
                parkingInfo.removeValue(forKey: carNumber)
            }
        }
    }
    // 23:59에 출차 처리
    let endOfDay = convertToMinutes("23:59")
    for (carNumber, inTime) in parkingInfo {
        let duration = endOfDay - inTime
        totalTimes[carNumber, default: 0] += duration
    }
    // 요금 계산
    var feesByCar: [(String, Int)] = []
    for (carNumber, totalTime) in totalTimes {
        var fee = fees[1] // 기본 요금
        if totalTime > fees[0] {
            // 기본 시간을 초과한 경우 추가 요금 계산
            let extraTime = totalTime - fees[0]
            let extraUnits = Int(ceil(Double(extraTime) / Double(fees[2])))
            fee += extraUnits * fees[3]
        }
        feesByCar.append((carNumber, fee))
    }
    // 차량 번호 오른차순 정렬 후 요금만 추출
    feesByCar.sort { $0.0 < $1.0 }
    return feesByCar.map { $0.1 }
}
