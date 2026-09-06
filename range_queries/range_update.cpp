#include<bits/stdc++.h>
using namespace std;

vector<long long> arr;
vector<long long> seg;
vector<long long> lazy;

void build(int ind, int low, int high){
    lazy[ind] = 0;
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}
void push_down(int ind, int low, int high){
    if(lazy[ind] == 0|| low == high) return;

    int mid = (low+high)/2;

    seg[2*ind + 1] += (mid-low+1)*lazy[ind];
    lazy[2*ind+1] += lazy[ind];

    seg[2*ind+2] += (high - mid)*lazy[ind];
    lazy[2*ind+2] += lazy[ind];

    lazy[ind] = 0;
}

void update(int ind, int low, int high,int l , int r, long long value){
    if(l > high || r < low) return;

    if(low >= l && high <= r){
        seg[ind] += value * (high - low + 1);
        lazy[ind] += value;
        return;
    }

    push_down(ind, low, high);
    int mid = (low + high)/2;
    update(2*ind+1, low, mid, l, r, value);
    update(2*ind+2, mid+1, high, l, r, value);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}
long long point_query(int ind, int low, int high , int k){
    if(low == high) return seg[ind];

    push_down(ind, low, high);
    int mid = (low + high)/2;
    if(k <= mid){
        return point_query(2*ind+1, low, mid, k);
    }
    else return point_query(2*ind+2, mid+1, high, k);
}
int main(){
    int n , q;
    cin >> n >> q;
    arr.resize(n+1, 0);
    seg.resize(4*n + 4, 0);
    lazy.resize(4*n + 4, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    build(0, 1, n);

    while(q--){
        int type; 
        cin >> type; 
        if(type == 1){
            int a , b; 
            long long u;
            cin >> a >> b >> u;
            update(0, 1, n, a, b, u);
        }
        else if(type == 2){
            int k; 
            cin >> k;
            cout<< point_query(0, 1, n, k) << '\n';
        }
    }
}