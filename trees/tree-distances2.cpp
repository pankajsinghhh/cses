#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> edges;
long long dfs(int node, int parent) {
    long long summ = edges[node].size();

    for (int adjnode : edges[node]) {
        if (adjnode != parent)
            summ += dfs(adjnode, node);
    }
    
    return summ;
}

int main(){
    int n; 
    cin >> n;
    edges.resize(n+1);

    for(int i = 1; i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<long long> summation;
    for(int i = 1; i <= n; i++){
        long long sum = dfs(i, -1);
        summation.push_back(sum);
    }
    for(int i = 0;i < summation.size(); i++){
        cout << summation[i] << ((i + 1 == summation.size()) ? '\n' : ' ');
    }
}