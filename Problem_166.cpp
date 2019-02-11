class Solution {
public:
    inline int indexOf(vector<int> v, int to_find)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == to_find) return i;
        }
        return -1;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        long a = abs((long)numerator);
        long b = abs((long)denominator);
        bool less_than_zero = ((numerator < 0) ^ (denominator < 0)) && a != 0;
        
        long integer = a / b;
        long rmd = a % b;
        vector<int> past_rmd = vector<int>();
        
        string ans = less_than_zero ? "-" : "";
        ans += to_string(integer);
        if (rmd) ans += ".";
        
        while(rmd)
        {
            int idx = indexOf(past_rmd, rmd);
            if (idx != -1)
            {
                ans.insert(ans.length() - (past_rmd.size() - idx), "(");
                ans += ")";
                return ans;
            }
            past_rmd.push_back(rmd);
            ans += to_string(abs(rmd * 10 / b));
            rmd = rmd * 10 % b;
        }
        return ans;
    }
};