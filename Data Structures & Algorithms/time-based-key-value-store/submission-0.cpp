class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        
        auto& vec = store[key];
        int lo = 0, hi = (int)vec.size() - 1;
        string result = "";

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vec[mid].first <= timestamp) {
                result = vec[mid].second;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }
};