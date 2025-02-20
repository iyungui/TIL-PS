import Foundation

func solution(_ num_list:[Int]) -> Int {
    num_list.reduce(1, *) > Int(pow(Double(num_list.reduce(0, +)), 2)) ? 0 : 1
}