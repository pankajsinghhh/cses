#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            int c = coins[j];
            if(c <= i) 
            dp[i] = (dp[i] + dp[i - c]) % M;
        }
    }

    cout<< dp[x] << '\n';
}