    inline char oppo(char c)
    {
        switch(c){
            case '(': return ')';
            case ')': return '(';
            case '[': return ']';
            case ']': return '[';
            case '{': return '}';
            case '}': return '{';
            default: break;
        }
        return ' ';
    }
    
    inline bool isLeft(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }
    
    
    bool isValid(string s) {
        stack<char> line;
        bool flag = true;
        for (char c:s)
        {
            if (isLeft(c)) line.push(c);
            else if (!line.empty() && line.top() == oppo(c)) line.pop();
            else {flag = false; break;}
        }
        
        flag &= line.empty();
        return flag;
    }
