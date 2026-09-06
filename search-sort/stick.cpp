#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long mid = (int)n/2;
    long long j= arr[mid];
    long long cost = 0;
    for(int i=0; i<n; i++){
        cost+=abs(arr[i]-j);
    }
    cout<< cost <<endl;
}