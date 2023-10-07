#include<bits/stdc++.h>
using namespace std;

void print(vector<int> array){
	for(int i:array)
		cout << i << " ";
}
int bestClosingTime(string customers) {
	int y = 0 , n = 0, min , save = 0;
	int len = customers.size();
	vector<int> hours(len+1);
	
	for(char c:customers)
		if(c == 'Y')
			y++;
			
		hours[0] = y;
		min = y;

	for(int i = 0 ; i < customers.size() ; i++){
		if(customers[i] == 'Y')
			y--;
		else
			n++;
			
		hours[i+1] = y+n;

		if(hours[i+1] < min){
			save = i+1;
			min = hours[i+1];
		}
	}
	  
	return save;
}
int main(){
	cout << bestClosingTime("YYNY") << endl;
	cout << bestClosingTime("NNNNN") << endl;
	cout << bestClosingTime("YYYY") << endl;
	
}