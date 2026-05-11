#include <string>
#include <vector>

class Solution {
public:
    // Machine 1
    std::string encode(std::vector<std::string>& strs) {
        std::string encoded;
        for (const std::string& s : strs) {
            encoded += std::to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    // Machine 2
    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> result;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') j++;

            int len = std::stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return result;
    }
};