#include<iostream>
#include<vector>
using namespace std;

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
    // unsolved problem
}