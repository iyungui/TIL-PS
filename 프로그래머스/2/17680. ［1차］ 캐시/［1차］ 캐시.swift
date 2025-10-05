func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    guard cacheSize > 0 else { return cities.count * 5 }
    var cities = cities.map { $0.lowercased() }
    var cache = [String]()
    var totalTime = 0
    
    for city in cities {
        // cache hit
        if let index = cache.firstIndex(of: city) {
            cache.remove(at: index)
            cache.append(city)
            totalTime += 1
        }
        // cache miss
        else {
            if cache.count >= cacheSize {
                _ = cache.removeFirst()
            }
            cache.append(city)
            totalTime += 5
        }
    }
    
    return totalTime
}