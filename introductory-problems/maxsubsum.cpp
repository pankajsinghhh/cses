#include <iostream>
#include <vector>
#include <algorithm>

long long cntmax(std::vector<long long>& arr, int n) {
    long long sum = arr[0];
    long long summ = arr[0];
    for (int i = 1; i < n; i++) {
        sum = std::max(arr[i], sum + arr[i]);
        summ = std::max(summ, sum);
    }
    return summ;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << cntmax(arr, n) << "\n";
    return 0;
}