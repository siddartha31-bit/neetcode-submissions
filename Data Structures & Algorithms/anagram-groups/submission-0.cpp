class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string word : strs) {

            string sortedWord = word;

            sort(sortedWord.begin(), sortedWord.end());

            groups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;

        for (auto group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};