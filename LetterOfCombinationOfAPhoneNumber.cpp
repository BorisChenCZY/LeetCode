#include<vector>
#include<string>
#include<iostream>

using namespace std;

string corresponding[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> gen(int digit, vector<string> current)
{
    vector<string> rnt = vector<string>();
    string to_add = corresponding[digit];

    if(current.size() == 0)
    {
        for(char r:to_add)
        {
            rnt.push_back(string(1, r));    
        }
    }
    else
    {
        for(string s:current)
        {
            for(char r:to_add)
            {
                rnt.push_back(s + r);
            }
        }
    }
    
    for (string tmp: rnt)
    {
        cout<<tmp<<endl;
    }
    return rnt;
}

vector<string> letterCombinations(string digits) {
    vector<string> ans = vector<string>();
    for(char c:digits)
    {
        ans = gen(c - '0', ans);
    }
    return ans;
}

int main(){
    
    vector<string> ans = letterCombinations("23");
    return 0;
}