import Foundation

struct MinHeap {
    private var heap = [Int]()

    var size: Int { heap.count }
    var isEmpty: Bool { heap.isEmpty }

    mutating func push(_ value: Int) {
        heap.append(value)
        var index = size - 1
        while index > 0 {
            let parent = (index - 1) / 2
            if heap[parent] <= heap[index] { break }
            heap.swapAt(parent, index)
            index = parent
        }
    }

    mutating func pop() -> Int? {
        guard !isEmpty else { return nil }
        if size == 1 { return heap.removeLast() }

        let ret = heap[0]
        heap[0] = heap.removeLast()
        var index = 0

        while true {
            let left = index * 2 + 1
            let right = index * 2 + 2
            var smallest = index

            if left < heap.count && heap[left] < heap[smallest] {
                smallest = left
            }
            if right < heap.count && heap[right] < heap[smallest] {
                smallest = right
            }
            if smallest == index { break }

            heap.swapAt(index, smallest)
            index = smallest
        }

        return ret
    }
}

func main() {
    let n = Int(readLine()!)!
    var works = [(deadLine: Int, count: Int)]()
    
    for _ in 0..<n {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        works.append((deadLine: line[0], count: line[1]))
    }

    works.sort { $0.deadLine < $1.deadLine }

    var minHeap = MinHeap()
    
    for work in works {
        minHeap.push(work.count)

        if minHeap.size > work.deadLine {
            minHeap.pop()
        }
    }
    
    var ret = 0

    while !minHeap.isEmpty {
        ret += minHeap.pop()!
    }

    print(ret)
}

main()