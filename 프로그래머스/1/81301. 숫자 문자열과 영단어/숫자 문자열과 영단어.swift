import Foundation

func solution(_ s:String) -> Int {
    let arr = ["zero","one","two","three","four","five","six","seven","eight","nine"]
    
    var ret = s
    for i in 0..<arr.count {
        ret = ret.replacingOccurrences(of: arr[i], with: String(i))
    }
    
    return Int(ret)!
}