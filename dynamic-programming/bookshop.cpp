#include<iostream>
#include<vector>
using namespace std;

int M = 1e9+7;

int main(){
    int n, x; 
    cin >> n >> x;
    vector<int> h(n);
    vector<int> s(n);

    for(int i = 0;i < n; i++){
        cin >> h[i];
    }
    for(int i = 0;i < n; i++){
        cin >> s[i];
    }

    vector<int> prev(x+1, 0);
    // our dp[i][j] -> dp[i-1][j] && dp[i-1]dp[j(money we have)-price of picked item]
    for(int i = 1;i <= n; i++){
        vector<int> curr(x+1);
        for(int j = x;j >= 0; j--){
            int price = h[i-1];
            int pages = h[i-1];

            int pick = (j >= prices? prev[j-price] + pages:0);
            int skip = prev[j];
            curr[j] = pick + skip;
        }
        prev = curr;
    }
    cout<< prev[x] << '\n';
    return 0;
}   