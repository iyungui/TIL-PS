//
//  main.swift
//  codingTEST
//
//  Created by iyungui on 9/23/25.
//

import Foundation

func main() {
    let t = Int(readLine()!)!
    
    for _ in 0..<t {
        let p = readLine()!
        _ = Int(readLine()!)!
        let str = readLine()!
        
        var x = 0
        var arr = [Int]()
        
        for ch in str {
            if ch == "[" || ch == "]" { continue }
            if ch >= "0" && ch <= "9" {
                x = x * 10 + Int(String(ch))!
            } else {
                arr.append(x)
                x = 0
            }
        }
        if x > 0 { arr.append(x) }
        
        var rev = false
        var err = false
        var left = 0
        var right = arr.count - 1
        
        for ch in p {
            if ch == "R" { rev.toggle() }
            else {
                if left > right { err = true; break }
                if rev { right -= 1 }
                else { left += 1 }
            }
        }
        
        if err { print("error"); continue }
        
        var result = [Int]()
        if left <= right {
            for i in left...right {
                result.append(arr[i])
            }
            if rev { result.reverse() }
        }
        
        if result.isEmpty { print("[]"); continue }
        print("[", terminator: "")
        
        for i in 0..<result.count {
            if i == result.count - 1 {
                print(result[i], terminator: "]\n")
            } else {
                print(result[i], terminator: ",")
            }
        }
    }
}

main()