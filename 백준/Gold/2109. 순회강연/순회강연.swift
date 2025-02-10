struct PriorityQueue<T> {
    // The array that stores the heap
    private var heap: [T] = []
    // The comparison function
    private let comparator: (T, T) -> Bool
    
    // Initialize with a comparison function
    init(comparator: @escaping (T, T) -> Bool) {
        self.comparator = comparator
    }
    
    // Check if the queue is empty
    var isEmpty: Bool {
        return heap.isEmpty
    }
    
    // Get the count of elements
    var count: Int {
        return heap.count
    }
    
    // Peek at the top element without removing it
    var peek: T? {
        return heap.first
    }
    
    // Add a new element to the queue
    mutating func enqueue(_ element: T) {
        heap.append(element)
        siftUp(from: heap.count - 1)
    }
    
    // Remove and return the highest priority element
    mutating func dequeue() -> T? {
        guard !heap.isEmpty else { return nil }
        
        if heap.count == 1 {
            return heap.removeLast()
        }
        
        let result = heap[0]
        heap[0] = heap.removeLast()
        siftDown(from: 0)
        
        return result
    }
    
    // Helper function to maintain heap property while inserting
    private mutating func siftUp(from index: Int) {
        var child = index
        var parent = parentIndex(of: child)
        
        while child > 0 && comparator(heap[child], heap[parent]) {
            heap.swapAt(child, parent)
            child = parent
            parent = parentIndex(of: child)
        }
    }
    
    // Helper function to maintain heap property while removing
    private mutating func siftDown(from index: Int) {
        var parent = index
        
        while true {
            let leftChild = leftChildIndex(of: parent)
            let rightChild = rightChildIndex(of: parent)
            var candidate = parent
            
            if leftChild < heap.count && comparator(heap[leftChild], heap[candidate]) {
                candidate = leftChild
            }
            
            if rightChild < heap.count && comparator(heap[rightChild], heap[candidate]) {
                candidate = rightChild
            }
            
            if candidate == parent {
                return
            }
            
            heap.swapAt(parent, candidate)
            parent = candidate
        }
    }
    
    // Helper function to get parent index
    private func parentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    // Helper function to get left child index
    private func leftChildIndex(of index: Int) -> Int {
        return 2 * index + 1
    }
    
    // Helper function to get right child index
    private func rightChildIndex(of index: Int) -> Int {
        return 2 * index + 2
    }
}

struct Lecture {
    let pay: Int
    let deadline: Int
}

// 최소 힙(Min Heap)으로 PriorityQueue 생성
var pq = PriorityQueue<Int> { $0 < $1 }
var result = 0
var lectures: [Lecture] = []

// 입력 받기
if let n = Int(readLine() ?? "0") {
    for _ in 0..<n {
        let input = readLine()?.split(separator: " ").map { Int($0) ?? 0 }
        if let input = input {
            lectures.append(Lecture(pay: input[0], deadline: input[1]))
        }
    }
}

// 마감일 기준으로 정렬
lectures.sort { $0.deadline < $1.deadline }

// 핵심 로직
for lecture in lectures {
    pq.enqueue(lecture.pay)
    if pq.count > lecture.deadline {
        pq.dequeue()
    }
}

// 결과 계산
while let pay = pq.dequeue() {
    result += pay
}

print(result)