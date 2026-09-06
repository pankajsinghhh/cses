#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <tuple>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n>> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    vector<vector<long long>> dist(n + 1, vector<long long>(2, LLONG_MAX));

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a>> b>> c;
        adj[a].push_back({b,c});
    }

    dist[1][0] = 0;

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0,1,0});

    while(!pq.empty()){
        auto[wt, node, used] = pq.top();
        pq.pop();

        if(wt > dist[node][used]) continue;

        for(const auto &it: adj[node]){
            int adjnode = it.first;
            long long adjwt = it.second;

            if(dist[node][used] + adjwt < dist[adjnode][used]){
                dist[adjnode][used] = dist[node][used] + adjwt;
                pq.push({dist[adjnode][used], adjnode, used});
            }
            if(used == 0){
                long long discount = adjwt/2;
                if(dist[node][0] + discount < dist[adjnode][1]){
                    dist[adjnode][1] = dist[node][0] + discount;
                    pq.push({dist[adjnode][1], adjnode, 1});
                }
            }
        }
    }

    cout << dist[n][1] << "\n";

    return 0;
}