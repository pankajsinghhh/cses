#include<bits/stdc++.h>

class segment_tree{
    int size; 
    std::vector<long long> segment;
    std::vector<long long> arr;

public:
    segment_tree(std::vector<long long>& input){
        arr = input;
        size = input.size();    
        segment.resize(4 * size);

        build(0, 0, size-1);
    }

    void build(int i, int left, int right){
        if(left == right){
            segment[i] = arr[left];
            return;
        }

        int mid = (left + right)/2;
        build(2 * i + 1, left, mid);
        build(2 * i + 2, mid+1, right);

        segment[i] = std::min(segment[2*i+1], segment[2*i+2]);
    }

    void update(int pos, long long val, int i, int left, int right){
        if(left == right){
            segment[i] = val;
            return;
        }
        int mid = (left + right)/2;
        if(pos <= mid){
            update(pos, val, 2*i+1, left, mid);
        }
        else{
            update(pos, val, 2*i+2, mid+1, right);
        }

        segment[i] = std::min(segment[2*i+1], segment[2*i+2]);
    }

    void update(int pos, long long val){
        update(pos, val, 0, 0, size-1);
    }
    
    long long query(int start, int end, int i, int left, int right){
        if(end < left || start > right) return LLONG_MAX;
        if(left >= start && right <= end){
            return segment[i];
        }
        int mid = (left + right)/2;
        long long l = query(start, end, 2*i+1, left, mid);
        long long r = query(start, end, 2*i+2, mid+1, right);

        return std::min(l, r);
    }

    long long query(int start, int end){
        return query(start, end, 0, 0, size-1);
    }

};

int main(){
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> arr(n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    segment_tree st(arr);

    while(q--){
        int type;
        std::cin >> type;
        if(type == 1){
            int k;
            long long u;
            std::cin >> k >> u;
            st.update(k-1 , u);
        }
        else{
            int a, b; 
            std::cin >> a >> b;
            std::cout << st.query(a-1, b-1)<< '\n';
        }
    }
}