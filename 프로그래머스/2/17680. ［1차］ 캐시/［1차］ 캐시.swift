func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    guard cacheSize > 0 else { return cities.count * 5 }
    var cache = [String]()
    let cities = cities.map { $0.lowercased() }
    var total = 0
    for city in cities {
        if let index = cache.firstIndex(of: city) {
            cache.remove(at: index)
            cache.append(city)
            total += 1
        }
        else {
            if cache.count >= cacheSize {
                cache.removeFirst()
            }
            cache.append(city)
            total += 5
        }
    }
    
    return total
}