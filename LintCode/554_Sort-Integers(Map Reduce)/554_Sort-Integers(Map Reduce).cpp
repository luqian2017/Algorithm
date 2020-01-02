/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
//
struct Node {
    int r, c, v;
    Node(int row, int col, int val) : r(row), c(col), v(val) {};
    //minHeap
    bool operator < (const Node & n) const {
        return v > n.v;
    }
};
 
class SortIntegersMapper: public Mapper {
public:
    void Map(int _, Input<vector<int>>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<int>& value);
        while(!input->done()) {
            vector<int> value = input->value();
            sort(value.begin(), value.end());
            string temp = "dummy_key";
            output(temp, value);
            input->next();
        }
    }
};

class SortIntegersReducer: public Reducer {
public:
    void Reduce(string &key, vector<vector<int>>& input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<int>& value);
        vector<int> results;
        
        int n = input.size();
        if (n == 0) {
            output(key, results);
            return;
        }
        
        priority_queue<Node> q; //minHeap
        
        for (int i = 0; i < n; ++i) {
            if (input[i].size() > 0) {
                q.push(Node(i, 0, input[i][0]));
            }
        }
        
        while(!q.empty()) {
            Node temp = q.top();
            q.pop();
            int row = temp.r;
            int col = temp.c;
            int val = temp.v;
            results.push_back(val);
            if (col == input[row].size() - 1) continue;
            q.push(Node(row, col + 1, input[row][col + 1]));
        }
        
        output(key, results);
    }
};