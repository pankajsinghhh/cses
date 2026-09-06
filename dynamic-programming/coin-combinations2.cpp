#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n>> x;
    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    } 

    const int M = 1e9 + 7;

    vector<int> nextstate(x+1, 0);
    nextstate[0] = 1;

    for(int i = n-1; i >= 0; i--){
        vector<int> currstate(x+1, 0);
        currstate[0] = 1;
        for(int j = 1; j <= x; j++){
            int skip = nextstate[j];
            int pick = 0;
            if(coins[i] <= j) pick = currstate[j - coins[i]];
            currstate[j] = (pick + skip) % M;
        }   
        nextstate = currstate;
    }
    cout<< nextstate[x] << '\n';
    
    return 0;
}