#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    vector<int> apa(m);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    for(int i=0; i<m; i++){
        cin>> apa[i];
    }
    int i=0, j=0, cnt=0;
    sort(arr.begin(),arr.end());
    sort(apa.begin(),apa.end());
    while(i<n && j<m){
        if(apa[j]-k <= arr[i] && arr[i] <= apa[j]+k){
            cnt++;
            i++;
            j++;
        }
        else if(arr[i] < apa[j] - k){
            i++;
        }
        else{
            j++;
        }
    }

    cout<< cnt<< endl;
    return 0;
}