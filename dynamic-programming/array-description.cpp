#include<iostream>
#include<vector>
using namespace std;

int M = 1e9+7;

bool valid(int a, int m){
    return a >= 1 && a <= m;
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 1;i <= m; i++){
        if(arr[0] == i || arr[0] == 0) dp[1][i] = 1; 
    }
    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(arr[i-1] != k && arr[i-1] != 0){
                dp[i][k] = 0;
                continue;
            }
            for(int prev = k-1; prev <= k+1; prev++){
                if(!valid(prev, m)) continue;
                dp[i][k] = (dp[i][k] + dp[i-1][prev]) % M;
            }
        }   
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n][i]) % M;
    }
    cout<< ans << '\n';
}
