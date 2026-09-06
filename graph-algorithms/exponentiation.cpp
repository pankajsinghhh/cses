#include<bits/stdc++.h>
using namespace std;

int M = 1e9+7;

long long power(long long a, long long b){
    if(b == 0) return 1;

    long long half = power(a , b/2);
    long long result = (half * half) % M;
    if(b % 2 == 1) result = (result*a) % M;
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;
        cout<< power(a,b) << "\n";
    }
}