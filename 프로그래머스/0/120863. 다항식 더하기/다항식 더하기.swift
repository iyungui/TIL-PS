import Foundation

func solution(_ polynomial:String) -> String {
    var arr: [String] = polynomial.components(separatedBy: " ")
    var result: String = ""
    var num = arr
    .filter { !$0.contains("x") }
    .filter { !$0.contains("+") }
    .reduce(0) { $0 + Int($1)! }
    
    var xCount = arr
    .filter { $0.contains("x") }
    .map { (str: String) -> String in str == "x" ? "1x" : str }
    .map { $0.replacingOccurrences(of: "x", with: "") }
    .reduce(0) { $0 + Int($1)! }
    
    

    
    if num > 0 {
        switch xCount {
            case 0:
                result = String(num)
            case 1:
                result = "x + \(num)"
            default: result = "\(xCount)x + \(num)"
        }
    } else {
        switch xCount {
            case 0:
                result = ""
            case 1:
                result = "x"
            default: result = "\(xCount)x"
        }
    }
    
    return result
}