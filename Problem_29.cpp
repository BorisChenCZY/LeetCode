class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = abs((long)dividend);
        long b = abs((long)divisor);
        bool less = (long)dividend * divisor < 0;
        long long cnt = 0;
        int adder = 0;
        
        if ( a < b ) return 0;

        while (a > b) 
        {
            b = b << 1;
            adder++;
        }

        while (a >= abs((long)divisor))
        {
            while (a - b >= 0)
            {
                cnt += (long)1 << adder;
                a -= b;
            }

            while (a < b  && adder >= 0)
            {
                adder--;
                b = b >> 1;
            }
        }

        // cout << less << ' ' << cnt << endl;
        if (!less && cnt >= INT_MAX) return INT_MAX;
        if (less && cnt >= -(long)INT_MIN) return INT_MIN;
        return less? -cnt: cnt;
    }
};