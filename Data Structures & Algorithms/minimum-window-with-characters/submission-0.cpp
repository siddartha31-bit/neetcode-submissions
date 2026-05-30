class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        
        unordered_map<char, int> need, window;
        
        for (char c : t) need[c]++;
        
        int left = 0, right = 0;
        int formed = 0;
        int required = need.size();
        
        int minLen = INT_MAX, minLeft = 0;
        
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            
            // Check if current char satisfies requirement
            if (need.count(c) && window[c] == need[c])
                formed++;
            
            // Try to shrink window from left
            while (formed == required) {
                // Update result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                // Remove leftmost char
                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar])
                    formed--;
                
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};