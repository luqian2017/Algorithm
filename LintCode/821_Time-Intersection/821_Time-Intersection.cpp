/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

struct Node {
    int eventTime;
    int eventFlag;
    Node(int et = -1, int ef = -1) : eventTime(et), eventFlag(ef) {}
    bool operator < (const Node & node) {
        if (this->eventTime == node.eventTime) {
            return this->eventFlag < node.eventFlag;
        }
        return this->eventTime < node.eventTime;
    }
};

class Solution {
public:
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        int nA = seqA.size();
        if (nA == 0) return {};
        int nB = seqB.size();
        if (nB == 0) return {};

        vector<Node> nodes;
        for (auto s : seqA) {
            nodes.push_back(Node(s.start, 0));
            nodes.push_back(Node(s.end, 1));
        }
            
        for (auto s : seqB) {
            nodes.push_back(Node(s.start, 0)); 
            nodes.push_back(Node(s.end, 1));
        }
        
        sort(nodes.begin(), nodes.end());
        
        int n = nodes.size();
        vector<Interval> intervals;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (nodes[i].eventFlag == 0) count++;
            else if (nodes[i].eventFlag == 1) count--;
            
            if (count == 2) {
                intervals.push_back(Interval(nodes[i].eventTime, nodes[i + 1].eventTime));
            }
        }
        
        return intervals;
    }
};