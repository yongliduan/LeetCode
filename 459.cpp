/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/


class Solution {
public:

    /*
    * O(N)
    */
    bool repeatedSubstringPattern(string str) {
        vector<int> next(str.length()+1, 0);
        int j = 1, k = 0;
        while (j < str.length()) {
            if (str[j] == str[k]) next[++j] = ++k;
            else if (k == 0) next[++j] = 0;
            else k = next[k];
        }
        return (next[str.length()] != 0) && (str.length() % (str.length() - next[str.length()]) == 0);
    }
    
    /*
    * O(K*N)
    */
    /*bool repeatedSubstringPattern(string str) {
        int length = str.length(), k = length;
        for (k = length-1; k >= 1; k--) {
            if (length%k != 0) continue;
            if (check(str, k)) return true;
        }
        return false;
    }
    
    bool check(string str, int k) {
        int i = 0, j = 0;
        while (j < str.length()) {
            if (i >= k) i = 0;
            // cout << i << " " << j << endl;
            if (str[i] != str[j]) return false;
            i++; j++;
        }
        return true;
    }*/
};
