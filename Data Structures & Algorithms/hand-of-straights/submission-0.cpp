class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> cnt;
        for (int c : hand) cnt[c]++;
        for (auto& [k, v] : cnt) {
            if (v == 0) continue;
            for (int i = 1; i < groupSize; i++) {
                if (cnt[k + i] < v) return false;
                cnt[k + i] -= v;
            }
        }
        return true;
    }
};