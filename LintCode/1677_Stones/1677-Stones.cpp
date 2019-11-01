struct Stone{
    int pos;
	int dist;
	int index;
	Stone(int p = 0, int d = 0, int id = 0) : pos(p), dist(d), index(id) {}; 
};

//min-heap
struct cmp {
    bool operator() (const Stone & a, const Stone & b) {
	    if (a.pos == b.pos) {
		    return a.dist > b.dist;
		   //return a.index > b.index;
		}
		else {
		    return a.pos > b.pos;
		}
	}
};


class Solution {
public:
    /**
     * @param p: the position of the i-th stone
     * @param d: how far the stones can be stone
     * @return: the distance from the start point to the farthest stone.
     */
    int getDistance(vector<int> &p, vector<int> &d) {
        int n = p.size();
		if (n == 0) return 0;
		int result = p[0];
        
		priority_queue<Stone, vector<Stone>, cmp> pq;
		
		for (int i = 0; i < n; ++i) {
		    pq.push(Stone(p[i], d[i], i));
		}
        
		int step = 1;
		while(!pq.empty()) {
		    if (step & 0x1) {
			    Stone curStone = pq.top();
				pq.pop();
				pq.push(Stone(curStone.pos + curStone.dist, curStone.dist, curStone.index));
			    //result = max(result, curStone.pos + curStone.dist);
			} else {
			    //result = max(result, pq.top().pos);
			    result = pq.top().pos;
			    //if step is even, just skip the stone with minimum index
				pq.pop();
				
			}
			
		    step++;
		    
		}
		
		return result;
    }
};