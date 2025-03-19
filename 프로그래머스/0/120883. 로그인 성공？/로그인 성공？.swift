import Foundation

func solution(_ id_pw:[String], _ db:[[String]]) -> String {
    if db.contains(id_pw) { return "login" }
    let ids: [String] = db.map { $0[0] }    //["rardss", "yyoom", ...]
    if ids.contains(id_pw[0]) { return "wrong pw" }
    return "fail"
}