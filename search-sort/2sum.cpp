#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    int x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
       cin>>arr[i].first;
       arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    int sum, flag = 0;
    while(left < right){
        sum = arr[left].first + arr[right].first;
        if(sum == x) {
            int i1 = arr[left].second;
            int i2 = arr[right].second;
            if (i1 > i2) swap(i1, i2);

            cout << i1 << " " << i2 << endl;
            return 0;
        }
        else if(sum<x) left++;
        else{
            right--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}u