#include<bits/stdc++.h>
using namespace std;

const int LOG = 31;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; 
    cin >> n >> q;

    vector<vector<int>> up(n+1, vector<int>(LOG, 0));

    for(int i = 2; i <= n; i++){
        cin >> up[i][0];
    }

    for(int j = 1; j < LOG; j++){
        for(int i = 1; i <= n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int x; long long k;
        cin >> x >> k;

        for(int j = 0; j < LOG; j++){
            if(k & (1LL<<j)){
                x = up[x][j];
                 if (x == 0) break;
            }
        }
        cout << (x == 0 ? -1 : x) << '\n';
    }
}