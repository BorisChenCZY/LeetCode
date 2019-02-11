class Solution {
public:
    const char base = 'A' - 1;
    
    inline bool posb_two(string& s, int idx, int length)
    {
        return (s[idx] == '1' or s[idx] == '2' && s[idx + 1] < '7') && (idx + 1 < length) ;
    }
    
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        
        int nums[s.length() + 1];
        nums[s.length()] = 1;
        nums[s.length() - 1] = s[s.length() - 1] == '0' ? 0 : 1;
        for (int i = s.length() - 2; i >= 0; i--)
        {
            if (posb_two(s, i, s.length()))
            {
                nums[i] = nums[i + 1] + nums[i + 2];
            }
            else if (s[i] == '0')
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = nums[i + 1];
            }
        }
        return nums[0];
    }
};