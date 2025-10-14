import Foundation

struct Song {
    let number: Int
    let playCount: Int
}

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var dict = [String: [Song]]()
    var cntDict = [String: Int]()
    
    for (idx, (g, p)) in zip(genres, plays).enumerated() {
        cntDict[g, default: 0] += p
        dict[g, default: []].append(Song(number: idx, playCount: p))
    }
    
    var ret = [Int]()
    
    let sortedCnt = cntDict.sorted { $0.value > $1.value }.map { $0.key }
    
    for genre in sortedCnt {
        let sorted = dict[genre]!.sorted { $0.playCount == $1.playCount ? $0.number < $1.number : $0.playCount > $1.playCount }.prefix(2)
        for song in sorted {
            ret.append(song.number)
        }
    }
    
    return ret
}