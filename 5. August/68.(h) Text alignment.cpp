#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int width;

string findline(int i, int j, int eachgap, int eachextragap, vector<string>& words){
    //this function makes a line. and returns it to be added
    //to the vector<string> result
    string line = "";

    for(int k = i ; k < j ; k++){
        line += words[k];

        if(k == j-1){   //last word of line
            continue;
        }

        for(int z = 0 ; z < eachgap ; z++)
            line += " ";

        if(eachextragap > 0){
            line += " ";
            eachextragap--;
        }
    }

    while(line.length() < width){
        line += " ";
    }

    return line;

}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    width = maxWidth;   //used in another func

    int i = 0;

    while(i < n){
        int letters = words[i].length();
        int j = i+1;
        int spaces = 0;

        while(j < n && words[j].length() + 1 + spaces + letters <= maxWidth){
            letters += words[j].length;
            spaces++;   //keeps track of spaces bw words
            j++;
        }

        //spaces shouldnt be 0
        int remainingslots = maxWidth - letters;    //total blank slots
        int eachgap = spaces == 0 ? 0 : remainingslots/spaces;        //each ultimate gap
        int eachextragap = spaces == 0 ? 0 : remainingslots%spaces;   //extra space on left
    
        if(j == n){//last line.. n comes after last word
            eachgap = 1;
            eachextragap = 0;
        }

        result.push_back(findline(i , j , eachgap, eachextragap, words));

        i = j;
    
    }
    return result;
}

int main(){
    
    
}

