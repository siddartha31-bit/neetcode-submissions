class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;
        for (auto node : lists)
            if (node) pq.push({node->val, node});
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            auto [val, node] = pq.top(); pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) pq.push({node->next->val, node->next});
        }
        return dummy.next;
    }
};