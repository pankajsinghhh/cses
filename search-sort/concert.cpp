#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;
    
    multiset<int> ms;
    for(int i=0; i<n; i++ ){
        int x;
        cin>>x;
        ms.insert(x);
    }
    for(int i=0; i<m; i++){
        int maxp;
        cin>> maxp;
        auto it = ms.upper_bound(maxp);
        if(it == ms.begin()){
            cout<< -1 << endl;
        }
        else{
            --it;
            cout<< *it<< endl;
            ms.erase(it);
        }
    }
    return 0;
}
