    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string common = string();
        auto min_ = (*strs.begin()).length();
        for (string s:strs) min_ = min(min_, s.length());
        for (int i = 0; i < min_; i++)
        {
            char tmp = (*strs.begin())[i];
            for(string s:strs)
            {
                if (tmp != s[i]) 
                {
                    tmp = ' ';
                    break;
                }                    
            }
            if (tmp != ' ') common += tmp;
            else break;
        }
        return common;
    }
