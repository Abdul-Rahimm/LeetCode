#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
int search(vi nums,int num,int start,int end){
    if(num < nums[start] || num > nums[end])
        return -1;

    int mid = (start+end)/2;

    if(nums[mid] == num)
        return mid;
    else if(num > nums[mid])
        return search(nums,num,mid+1,end);
    else    
        return search(nums,num,start,mid-1);
    
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int first=0, second = matrix[0].size()-1;
    int len = matrix.size();

    for(int i = 0; i < len ; i++){
        if(target >= matrix[i][first] && target <= matrix[i][second])
            if(search(matrix[i],target,0,second) != -1)
                return true;
            else 
                return false;
        
        if(i < matrix.size() -1)
        if(target > matrix[i][second] && target < matrix[i+1][first])
            return false;

    }
    if(target > matrix[len-1][second])
        return false;
}


int main(){
   vii nums{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
   cout << searchMatrix(nums,3) << endl;

   vii nums2{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
   cout << searchMatrix(nums2,13) << endl;
  
}