import Foundation

func solution(_ letter:String) -> String {
    let morse: [String: String] = [
        ".-": "a",
        "-...": "b",
        "-.-.": "c",
        "-..": "d",
        ".": "e",
        "..-.": "f",
        "--.": "g",
        "....": "h",
        "..": "i",
        ".---": "j",
        "-.-": "k",
        ".-..": "l",
        "--": "m",
        "-.": "n",
        "---": "o",
        ".--.": "p",
        "--.-": "q",
        ".-.": "r",
        "...": "s",
        "-": "t",
        "..-": "u",
        "...-": "v",
        ".--": "w",
        "-..-": "x",
        "-.--": "y",
        "--..": "z"
    ]
    
    // let morseLetters = letter.split(separator: " ")
    // var result = ""
    // for morseCode in morseLetters {
    //     if let c = morse[String(morseCode)] {
    //         result += c
    //     }
    // }
    // return result
    
    return letter.components(separatedBy: " ").map { morse[$0] ?? "" }.reduce("", +) 
}