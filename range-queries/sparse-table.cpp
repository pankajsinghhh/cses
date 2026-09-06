#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; 
    cin >> n >> q;
    
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

   int LOG = 1;
   while((1<<LOG) <= n){
    LOG++;
   }

   vector<vector<int>> sparse(LOG+1, vector<int>(n+1));

   for(int i = 1; i <= n; i++){
    sparse[0][i] = arr[i];
   }
   for(int k = 1; k <= LOG; k++){
        for(int i = 1; i + (1<<k) - 1 <= n; i++){
            sparse[k][i] = min(sparse[k-1][i], sparse[k-1][i+(1<<(k-1))]);
        }
   }
   while(q--){
    int a, b;
    cin >> a >> b;

    int range = b - a + 1;
    int k = log2(range);

    int result = min(sparse[k][a], sparse[k][b - (1<<k) + 1]);
    cout<< result<< "\n";
   }
   
return 0;
}