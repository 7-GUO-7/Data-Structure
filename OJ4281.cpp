#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool Judge(string str){
    int end = str.size()-1;
    int start = 0;
    while(start < end){
        if(str[start] == str[end]){
            start++;
            end--;
        }else{
            return 0;
        }
    }
    return 1;
}

int Solution(string input) {
    int len = input.length();
    vector<int> part(len,0);
    for(int i=0; i<len; i++){
        part[i] = Judge(input.substr(0, i+1)) ? 0 : i;
        if(part[i] == 0)
            continue;
        else{
            for(int j=1; j<=i; j++){
                if(Judge(input.substr(j,i-j+1)))
                    part[i] = min(part[i], part[j-1]+1);
                else{
                    part[i] = min(part[i], part[j-1]+i-j+1);
                }
            }
        }
    }
    return part[len-1];
}


int main(){
    string input;
    cin>>input;
    cout<<Solution(input)<<endl;
}