// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        vector<int> arr(pow(2,n),-1);
        
        for(string binary: nums){
            int num = 0;
            int power = n-1;
            
            for(char i: binary){
                num += (int(i) - 48)*pow(2,power);
                power--;
            }
            arr[num] = 0;
            cout << num << endl;
        }

        string ans ;
        for(int i = 0 ; i < pow(2,n) ; i++){
            if(arr[i] == -1){
                int num = i;

                for(int j = n-1 ; j >= 0 ; j--){
                    int power = pow(2,j); // 4 2 1

                    if(i >= power){
                        ans.push_back('1');
                        i -= power;
                    }
                    else{
                        ans.push_back('0');
                    }
                }
                break;
            }
        }
        return ans;
    }

int main(){
    vector<string> nums{"01","00"};
    cout << findDifferentBinaryString(nums) << endl;

}