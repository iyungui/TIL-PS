func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    guard cacheSize > 0 else { return cities.count * 5 }
    
    var cache = [String]()
    var totalTime = 0
    let cities = cities.map { $0.lowercased() }
    
    for city in cities {
        if let index = cache.firstIndex(of: city) {
            // Cache Hit
            cache.remove(at: index)
            cache.append(city)
            totalTime += 1
        } else {
            // Cache Miss
            if cache.count >= cacheSize {
                cache.removeFirst()
            }
            cache.append(city)
            totalTime += 5
        }
    }
    
    return totalTime
}