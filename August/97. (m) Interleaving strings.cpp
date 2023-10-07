#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isInterleave_83(string s1, string s2, string s3) {
    int first=0,    second=0;
    int i = 0;
    while(i < s3.size()){
        bool status = true;
        while(s1[first] == s3[i] && first < s1.size()){
            //cout << s1[first] << " " << s2[second] << " " << s3[i] << endl;
            first++;    i++;
            status = false;
        }

        while(s2[second] == s3[i] && second < s2.size()){
            // cout << s1[first] << " " << s2[second] << " " << s3[i] << endl;
            second++;   i++;
            status = false;
        }

        if(status) 
            return false;
    }

    if(first == s1.size() && second == s2.size())
        return true;
    else
        return false;
}

int m, n, N;
int t[101][101][201];

bool solve(int i, int j , int k,string &s1, string &s2, string &s3){
    if(i == m && j == n && k == N)
        return true;
    if(k >= N)  
        return false;

    if(t[i][j][k] != -1)
        return t[i][j][k];

    bool result = false;

    if(s1[i] == s3[k] && i < m)
        result = solve(i+1,j,k+1,s1,s2,s3);
    
    if(result)  return t[i][j][k] = true;

    if(s2[j] == s3[k] && j < n)
        result = solve(i,j+1,k+1,s1,s2,s3);

    return t[i][j][k] = result;

}
bool isInterleave(string s1, string s2, string s3) {
    m=s1.length(), n = s2.length() , N = s3.length();

    memset(t,-1,sizeof(t));

    return solve(0, 0, 0, s1, s2, s3);
}
int main(){
    cout << isInterleave("a","b","a") << endl;
    
    
}

