import Foundation

func solution(_ arr:[Int], _ idx:Int) -> Int {
    return arr[idx...].firstIndex(of: 1) ?? -1
}