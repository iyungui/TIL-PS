#include <bits/stdc++.h>

using namespace std;


bool isPrime(int n) {
   if(n < 2) return false;
   for(int i = 2; i * i <= n; i++) {
       if(n % i == 0) return false;
   }
   return true;
}

int solution(string numbers) {
    vector<int> v;
    sort(numbers.begin(), numbers.end());
    do {
        string temp = "";
        
        for(int i = 0; i < numbers.size(); i++) {
            temp += numbers[i];
            int num = stoi(temp);
            if(isPrime(num)) v.push_back(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return (int)v.size();
}