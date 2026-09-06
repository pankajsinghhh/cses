#include<iostream>
#include<vector>
using namespace std;

int M = 1e9+7;

int main(){
    int n; 
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    vector<int> nextrow(n);
    if(grid[n-1][n-1] == '.') nextrow[n-1] = 1;
    else nextrow[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        if(grid[n-1][i] == '.') nextrow[i] = nextrow[i+1];
        else nextrow[i] = 0;
    }
     for(int i = n-2; i >= 0; i--){
        vector<int> currrow(n);
        for(int j = n-1; j>=0; j--){
            if(grid[i][j] == '*') currrow[j] = 0;
            else{
                int ans1 = i < n-1? nextrow[j] : 0;
                int ans2 = j < n-1? currrow[j+1] : 0;
                currrow[j] = (ans1 + ans2) % M;
            }
        }
        nextrow = currrow;
    }

    cout<< nextrow[0] << '\n';
}