class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& i : intervals) {
            if (!minHeap.empty() && minHeap.top() <= i.start)
                minHeap.pop();
            minHeap.push(i.end);
        }
        return minHeap.size();
    }
};