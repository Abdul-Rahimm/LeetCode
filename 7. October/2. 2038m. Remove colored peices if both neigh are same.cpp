class Solution {
public:
    bool winnerOfGame(string colors) {
        unordered_map<int,vector<int>> mp;
        int n = colors.size(), i = 0 ;
        int total_a = 0, total_b = 0,a,b;
        
        while(i < n){
            a = 0;b = 0;
            
            while(colors[i] == 'A'){
                a++;
                i++;
            }
            total_a += max(0,a-2);
            
            while(colors[i] == 'B'){
                b++;
                i++;
            }
            total_b += max(0,b-2);
        }
        
        if(total_b >= total_a)
            return false;
        else 
            return true;
    }
};