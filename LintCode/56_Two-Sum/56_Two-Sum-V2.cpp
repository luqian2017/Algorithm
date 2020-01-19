class Node {
public:
    int value;
    int index;
    Node(int v = 0, int id = 0) : value(v), index(id) {}
    bool operator < (const Node & node) const {
        return value < node.value;
    }
};

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> & numbers, int target) {
        int n = numbers.size();
        if (n == 0) return {};
        vector<Node> nodes(n);
        
        for (int i = 0; i < n; ++i) {
            nodes[i] = Node(numbers[i], i);
        }
        
        sort(nodes.begin(), nodes.end());
        
        int p1 = 0, p2 = n - 1;
        while(p1 < p2) {
            int sum = nodes[p1].value + nodes[p2].value;
            if (sum == target) 
            {
                return {min(nodes[p1].index, nodes[p2].index), max(nodes[p1].index, nodes[p2].index)};
            } else if (sum < target) {
                p1++;
            } else {
                p2--;
            }
        }
        
        return {};
    }
};