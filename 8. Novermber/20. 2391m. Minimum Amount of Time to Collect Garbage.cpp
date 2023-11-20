class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        // int m = travel.size();
       
        int lm = 0, lp = 0, lg = 0;
       
        for (int i = 0 ; i < n ; i++){
            string sentence = garbage[i];
           
            for(char x: sentence){
                if(x == 'G')
                    lg = i;
                else if(x == 'P')
                    lp = i;
                else
                    lm = i;
            }
        }
       
        int p = 0, m = 0, g = 0;
       
        for(int i = 0 ; i < n ; i++){
            string sentence = garbage[i];
           
            for(char x: sentence){
                if(x == 'G')
                    g++;
                else if(x == 'P')
                    p++;
                else
                    m++;
            }
           
            if(i == n-1)
                break;
           
            if(i != lg)
                g += travel[i];
            if(i != lp)
                p += travel[i];
            if(i != lm)
                m += travel[i];
        }
       
       
        return g+p+m;
    }
};