#include<iostream>
#include<vector>
using namespace std;

int M = 1e9+7;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        string a = to_string(i);
        for(char ch: a){
            int digit = ch - '0';
            if(digit != 0) dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }
    cout<< dp[n] << '\n';
}