#include<string>
#include<iostream>

using namespace std;

string expand(string s, int left, int right)
{
    int left_bound = 0;
    int right_bound = s.size() - 1;
    bool flag = false;
    while(left >= left_bound && right <= right_bound && s[left] == s[right])
    {
        flag = true;
        left--;
        right++;
    }
    
    left++;
    right--;
    if (flag)
    {
        cout << left << ' ' << right << ' ' << endl;
        cout << s.substr(left, right + 1) << endl;
    }
    return flag && left <= right ? s.substr(left, right + 1) : "";
}

string longestPalindrome(string s) {
    int max_len = 1;
    string max_str = s.substr(0, 1);
    string cur;
    
    for(int i = 0; i < s.size(); i++)
    {
        cur = expand(s, i, i);
        if (cur.size() > max_len)
        {
            max_len = cur.size();
            max_str = cur;
        }
        cur = expand(s, i, i+1);
        if (cur.size() > max_len)
        {
            max_len = cur.size();
            max_str = cur;
        }
    }
    
    return max_str;
}

int main(){
    string ans = longestPalindrome("babad");
    string test = "babad";
    cout << test.substr(1, 3) << endl;
    cout << ans << endl;
    return 0;
}