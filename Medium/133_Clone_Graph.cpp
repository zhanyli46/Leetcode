#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        /* Time O(VE), space O(V + E) */
        /* Runtime: 32ms */
        if (!node)
            return nullptr;
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *n = q.front();
            q.pop();
            UndirectedGraphNode *new_node;
            if (m.find(n) == m.end()) {
                new_node = new UndirectedGraphNode(n->label);
                m[n] = new_node;
            } else {
                new_node = m[n];
            }
            if (n->neighbors.size() == new_node->neighbors.size())
                continue;
            for (int i = 0; i < n->neighbors.size(); ++i) {
                UndirectedGraphNode *neighbor = n->neighbors[i];
                q.push(neighbor);
                if (m.find(neighbor) == m.end()) {
                    UndirectedGraphNode *new_neighbor = new UndirectedGraphNode(neighbor->label);
                    m[neighbor] = new_neighbor;
                    new_node->neighbors.push_back(new_neighbor);
                } else {
                    new_node->neighbors.push_back(m[neighbor]);
                }

            }
        }
        return m[node];
    }
};
