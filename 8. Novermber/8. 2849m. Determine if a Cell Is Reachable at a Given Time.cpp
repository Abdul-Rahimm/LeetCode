class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
     
        if(fx == sx && sy == fy && t == 1)
            return false;
        
        int dx = abs(fx - sx);
        int dy = abs(fy - sy);
        
        int d = max(dx,dy);
        
        if(t < d)
            return false;
        else
            return true;
        
    }
};