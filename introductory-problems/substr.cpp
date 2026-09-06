#include<iostream>
#include<vector>
#include<algorithm>


int main(){
    std::string s;
    std::cin>>s;
    int cnt = 1, maxlen = 1;
    int n = s.size();
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1])cnt++;
        else{
            maxlen = std::max(maxlen, cnt);
            cnt = 1;
        }
    }
    maxlen = std::max(maxlen, cnt);
    std::cout<<maxlen<<std::endl;
    return 0;
}