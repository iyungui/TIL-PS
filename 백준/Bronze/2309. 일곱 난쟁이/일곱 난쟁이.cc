#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int main() {
    int total_sum = 0;
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    for(int i = 0; i < 8; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(total_sum - arr[i] - arr[j] == 100) {
                arr[i] = arr[j] = 0;
                sort(arr, arr + 9);
                for(int k = 2; k < 9; k++) {
                    cout << arr[k] << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}