class Solution {
public:

    int MOD = 1337;
    
    // my O(N^2) method
    int superPow(int a, vector<int>& b) {
        int res = 1, len = b.size();
        for (int i = 0; i < len; i++) {
            if (b[i] < 0) return 0;
            int base = quick_exp(a, b[i]);
            int j = len-1-i;
            while (j--) 
                base = quick_exp(base, 10);
            res = (res*base) % 1337;
        }
        return res;
    }
    
    
    // O(N*log10) Method for this problem
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = 0; i < b.size(); i++) 
            res = (quick_exp(res, 10) * quick_exp(a, b[i])) % MOD;
        return res;
    }
    
    int quick_exp(int a, int b) {
        a %= MOD;
        int prod = 1;
        while (b) {
            if (b&1) {
                prod = (prod * a) % MOD;
                b -= 1;
            } else {
                a = (a*a) % MOD;
                b >>= 1;
            }
        }
        return prod;
    }
};
