#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    cin>>n;
    multiset<int> ms;
    vector<int> arr;
    int a; 
    int b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        ms.insert(a);
        arr.push_back(b);
    }
    int cnt=1;
}