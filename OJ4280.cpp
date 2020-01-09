#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> solution (string input)
{
    int len = input.size();
    vector <int> array1;
    vector<int> sol;
    for (int i=0; i < len; i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*')
        {
            vector<int> left = solution(input.substr(0, i));
            vector<int> right = solution(input.substr(i + 1, len));
            for(auto n1 : left)
            {
                for(auto n2 : right)
                {
                    if(input[i] == '+') sol.push_back(n1 + n2);
                    else if(input[i] == '-') sol.push_back(n1 - n2);
                    else sol.push_back(n1 * n2);
                }
            }

        }
    }
    if(sol.empty())
    {

        int n = 0;
        sscanf(input.c_str(), "%d", &n);
        sol.push_back(n);
    }
    return sol;


}


int main() {

    string input;
    cin >> input;
    vector<int> answer;
    answer = solution(input);
    sort(answer.begin(),answer.end());
    for (int i=0; i<answer.size(); ++i)
        cout<<answer[i]<<endl;



}