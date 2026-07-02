class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(nei));
        }
        return clone;
    }
private:
    unordered_map<Node*, Node*> visited;
};