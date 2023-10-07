#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void print(queue<int> q,stack<int> s){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
}
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    stack<int> s;
    int len = students.size();

    for(int i = 0 ; i < len ; i++){
        q.push(students[i]);
        s.push(sandwiches[len - i - 1]);
    }      

    int counter = 0;
    while(!s.empty()){
        int qf = q.front(), sf = s.top();
        q.pop();           

        if(qf == sf){
            s.pop();
            counter = 0;
            //cout << qf << " gets sandwich " << endl;
        }
        else{
            counter++;
            q.push(qf);
            //cout << qf << " doesnt get sandwich bec sf = " << sf << endl;
        }

        if(counter == s.size())     return s.size();
    }

    return 0;
}

int main(){
    vector<int> students{1,1,0,0},  sandwiches{0,1,0,1};
    cout << countStudents(students,sandwiches) << endl;
}