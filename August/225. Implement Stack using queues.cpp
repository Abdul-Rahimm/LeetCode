#include<bits/stdc++.h>
using namespace std;

queue<int> q1;
queue<int> q2; 

MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int len = q1.size();    //2

        
        for(int i = 0 ; i < len-1 ; i++){
            q1.push(q1.front());
            q1.pop();
        }

    }
    
    int pop() {
        int x = q1.fornt();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }