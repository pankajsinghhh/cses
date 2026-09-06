#include<bits/stdc++.h>
using namespace std;

vector<long long> arr;
vector<long long> seg;

void build(int ind, int low, int high){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void update(int ind, int low, int high, int index, long long value){
    if(low == high){
        seg[ind] = value;
        return;
    }

    int mid = (low+high)/2;
    if(index <= mid) update(2 * ind + 1, low, mid, index, value);
    else update(2 * ind + 2, mid + 1, high, index, value);

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

long long query(int ind, int low, int high, int l, int r){
    if(high < l || low > r){
        return 0;
    }
    if(low >= l && high <= r){
        return seg[ind];
    }
    int mid = (low + high)/2;
    long long left = query(2*ind+1, low, mid, l, r);
    long long right = query(2*ind + 2, mid + 1, high, l, r);

    return left + right;
}

int main(){
    int n , q;
    cin >> n >> q;
    arr.resize(n+1, 0);
    seg.resize(4*n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    build(0, 1, n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int k;
            long long u;
            cin >> k >> u;

            arr[k] = u;
            update(0, 1, n, k, u);
        }
        else{
            int a, b;
            cin >> a >> b;

            cout << query(0, 1, n, a, b) << "\n";
        }
    }
}