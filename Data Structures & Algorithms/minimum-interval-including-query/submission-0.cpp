class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        int n = queries.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return queries[a] < queries[b]; });
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        vector<int> ans(n, -1);
        int i = 0;
        
        for (int j : idx) {
            int q = queries[j];
            while (i < intervals.size() && intervals[i][0] <= q) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({len, intervals[i][1]});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < q)
                minHeap.pop();
            if (!minHeap.empty())
                ans[j] = minHeap.top().first;
        }
        return ans;
    }
};
