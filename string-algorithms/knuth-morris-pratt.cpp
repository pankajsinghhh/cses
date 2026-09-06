#include<bits/stdc++.h>
using namespace std;

vector<int> build_lps(string pat){
    int n = pat.size();
    vector<int> lps(n);
    int i = 1, len = 0;
    while(i < n){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> KMP(string text, string pat){
    vector<int> lps = build_lps(pat);
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < text.size()){
        if(text[i] == pat[j]){
            i++;
            j++;
        }
        if(j == pat.size()){
            ans.push_back(i-j);
            j = lps[j-1];
        }
        else if(i < text.size() && text[i] != pat[j]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return ans;
}

int main(){
  string text; 
  cin>> text;
  string pattern;
  cin >> pattern;
  int n = text.size(), m = pattern.size();

  vector<int> patpos = KMP(text, pattern);

  cout<< patpos.size()<< "\n";
}