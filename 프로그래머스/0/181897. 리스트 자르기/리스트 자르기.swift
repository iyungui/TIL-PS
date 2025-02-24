import Foundation

func solution(_ n:Int, _ slicer:[Int], _ num_list:[Int]) -> [Int] {
    switch(n) {
        case 1: return stride(from: 0, through: slicer[1], by: 1).map { num_list[$0] }
        case 2: return stride(from: slicer[0], to: num_list.count, by: 1).map { num_list[$0] }
        case 3: return stride(from: slicer[0], through: slicer[1], by: 1).map { num_list[$0] }
        default: return stride(from: slicer[0], through: slicer[1], by: slicer[2]).map { num_list[$0] }
    }
}