class SeatManager {
public:
    priority_queue<int, vector<int> , greater<int>> pq; //min heap
    int seat;
    SeatManager(int n) {
       seat = 1;
    }
    
    int reserve() {
       
        if(!pq.empty()){
            int ret = pq.top();
            pq.pop();
            return ret;
        }
        
        int ret = seat;
        seat++;  
        return ret;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */