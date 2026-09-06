#include<iostream>
#include<vector>
int main(){
    long long n ; 
    std::cin>>n;
    long long total = n*(n+1)/2;
    long long sum = 0;
    std::vector<int> arr(n);
    for(int i=0; i<n-1; i++){
        std::cin>> arr[i];
    }
    for(int i=0; i<n-1; i++){
        sum += arr[i];
    }

    long long missed = total-sum;
    std::cout<< missed <<std::endl;
    return 0;
}