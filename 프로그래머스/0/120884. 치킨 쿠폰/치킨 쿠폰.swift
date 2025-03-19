import Foundation

func solution(_ chicken:Int) -> Int {
    // 받을 수 있는 "최대 서비스 치킨의 수"
    var answer: Int = 0
    
    // *: 서비스치킨, (): 남은 현재 쿠폰 수
    // 처음 1081마리 주문 -> 쿠폰 1081장
    // 서비스치킨 108마리 주문 (남은 쿠폰 1장) -> 쿠폰 108 + 1 = 109장
    // 서비스치킨 10마리 주문 (남은 쿠폰 9장) -> 쿠폰 10 + 9 = 19장
    // 서비스치킨 1마리 주문 (남은 쿠폰 9장) -> 쿠폰 1 + 9 = 10장
    // 서비스치킨 1마리 주문 (남은 쿠폰 0장) -> 쿠폰 1 + 0 = 1장
    
    var coupon: Int = chicken   // 처음 1081마리 주문 -> 쿠폰 1081장
    print(coupon)
    
    while coupon >= 10 {
        var service = coupon / 10   // 이번 서비스치킨 마리 수
        answer += service
        print(answer, coupon)
        coupon %= 10
        coupon += service
    }
    
    return answer
}