#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;

    long long total = 1 << n ;
    for(long long i = 0; i < total; i++){
        int gray = i ^ (i >> 1);

        for(int b = n-1; b >= 0; b--){
            cout<< ((gray >> b) & 1);
        }
        cout<<'\n';
    }
}