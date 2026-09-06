#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> wt(n);
    for(int i=0; i<n; i++){
        cin>> wt[i];
    }
    sort(wt.begin(), wt.end());
    int i=0, j=n-1, gondolas = 0;
    while(i<=j){
        if(wt[i]+wt[j]<=x){
            i++;
            j--;
        }
        else{
            j--;
        }
        gondolas++;
    }
    cout<< gondolas<< endl;
    return 0;
}
