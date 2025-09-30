import Foundation

func solve() {
    var totalScore = 0.0  // (학점 × 과목평점)의 합
    var totalCredit = 0.0  // 학점의 총합
    
    // 등급별 과목평점 매핑
    let gradePoints: [String: Double] = [
        "A+": 4.5,
        "A0": 4.0,
        "B+": 3.5,
        "B0": 3.0,
        "C+": 2.5,
        "C0": 2.0,
        "D+": 1.5,
        "D0": 1.0,
        "F": 0.0
    ]
    
    for _ in 0..<20 {
        let a = readLine()!.split(separator: " ")
        let (_, credit, grade) = (a[0], Double(a[1])!, String(a[2]))
        
        // P 등급은 계산에서 제외
        if grade == "P" {
            continue
        }
        
        // 학점 × 과목평점을 누적
        if let gradePoint = gradePoints[grade] {
            totalScore += credit * gradePoint
            totalCredit += credit
        }
    }
    
    // 전공평점 = (학점 × 과목평점)의 합 / 학점의 총합
    let gpa = totalScore / totalCredit
    print(String(format: "%.6f", gpa))
}

solve()