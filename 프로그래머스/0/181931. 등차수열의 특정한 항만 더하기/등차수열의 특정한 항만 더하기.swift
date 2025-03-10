import Foundation

func solution(_ a:Int, _ d:Int, _ included:[Bool]) -> Int {
    
    // // S1
    // var ret = 0
    // for (index, isIncluded) in included.enumerated() {
    //     if(isIncluded) {
    //         ret += a + (d * index)
    //     }
    // }
    // return ret
    
    
    // S2

    included.indices
    .filter { included[$0] }
    .map { a + ($0 * d) }   // t,f,f,t,t -> a, a+(3*d), a+(4*d)
    .reduce(0, +)
}