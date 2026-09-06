#include<bits/stdc++.h>
using namespace std;

vector<long long> ans;
vector<long long> dp;
vector<vector<int>> edges;
int n;

long long dfs1(int u, int p){
    dp[u] = 0;
    for(int v: edges[u]){
        if(v != p){
            dp[u] = max(dp[u], 1 + dfs1(v, u));
        }
    }
    return dp[u];
}
void dfs2(int u, int p, long long up){
    ans[u] = max(up, dp[u]);

    long long best1 = 0, best2 = 0;
    for(int v: edges[u]){
        if(v != p){
            long long d = 1 + dp[v];
            if(d > best1){
                best2 = best1;
                best1 = d;
            }
            else if(d > best2) best2 = d;
        }
    }

    for(int v: edges[u]){
        if(v != p){
            long long d = 1 + dp[v];
            long long longestSibling = (d == best1)? best2: best1;
            long long new_up = 1 + max(up, longestSibling);
            dfs2(v, u, new_up);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    edges.resize(n+1);
    ans.resize(n+1);
    dp.resize(n+1);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0);

    for(int i = 1; i <= n; i++){
        cout<< ans[i] << (i == n? '\n': ' ');
    }
    return 0;
}