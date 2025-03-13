import Foundation

func solution(_ num:Int, _ k:Int) -> Int {
    for (offset, element) in String(num).enumerated() {
        if Int(String(element))! == k { 
            return offset + 1 
        }
    }
    return -1
}