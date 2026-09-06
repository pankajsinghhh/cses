#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<long long> arr(n+1, 0);
    for(int i = 1; i <= n; i++){
        int a; 
        cin >>a;
        arr[i] = a + arr[i-1];
    }
// we want (arr[j]-arr[i]) % n = 0;
// so arr[j]%n - arr[i]%n = 0; thus => { arr[j] % n = arr[i] % n; }
    vector<long long> freq(n, 0);
    long long ans = 0;

    for(int i = 0; i <= n; i++){
        long long rem = ((arr[i]%n) + n)%n;
        ans += freq[rem];
        freq[rem]++;
    }
    cout<< ans << "\n";
}