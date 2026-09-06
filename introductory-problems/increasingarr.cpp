#include <iostream>
#include <vector>

long long cntmoves(std::vector<long long> &arr, int n) {
    long long cnt = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            cnt += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    return cnt;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << cntmoves(arr, n);
}