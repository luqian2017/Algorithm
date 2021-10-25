struct Node {
    int id, t;
    double p;
    Node(int index = 0, int time = 0, double prob = 0) : id(index), t(time), p(prob) {}
};

struct compare {
    bool operator() (const Node & a, const Node & b) {
        if (abs(a.p * b.t - b.p * a.t) < 1e-5) return a.id < b.id;
        return a.p * b.t > b.p * a.t;
    }
} cmp;

class Solution {
public:
    /**
     * @param n: The number of tasks
     * @param t: The time array t
     * @param p: The probability array p
     * @return: Return the order
     */
    vector<int> getOrder(int n, vector<int> &t, vector<double> &p) {
        vector<int> res;
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
           nodes[i] = Node(i, t[i], p[i]);
        }
        sort(nodes.begin(), nodes.end(), cmp);
        for (int i = 0; i < n; ++i) {
            res.push_back(nodes[i].id + 1);
        }
        return res;
    }
};