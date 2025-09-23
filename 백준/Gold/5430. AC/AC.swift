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
        _ = readLine()!
        
        let str = readLine()!
        var arr = [Int]()
        var cur = 0
        for ch in str {
            if ch == "[" || ch == "]" { continue }
            if ch >= "0" && ch <= "9" {
                cur = cur * 10 + Int(String(ch))!
            }
            else {  // ","
                arr.append(cur)
                cur = 0
            }
        }
        if cur > 0 { arr.append(cur) }
        
        var left = 0
        var right = arr.count - 1
        var rev = false
        var err = false
        
        for ch in p {
            if ch == "R" { rev.toggle() }
            else {
                if left > right { err = true; break }
                if rev { right -= 1 }
                else { left += 1 }
            }
        }
        
        if err {
            print("error")
            continue
        }
        
        var result = [Int]()
        
        if left <= right {
            for i in left...right {
                result.append(arr[i])
            }
            if rev { result.reverse() }
        }
        
        if result.isEmpty {
            print("[]")
            continue
        }
        
        print("[", terminator: "")
        for i in 0..<result.count {
            if i == result.count - 1 { print(result[i], terminator: "]\n") }
            else { print(result[i], terminator: ",") }
        }
    }
}

main()