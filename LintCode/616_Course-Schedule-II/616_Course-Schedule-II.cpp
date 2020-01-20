class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        int n = prerequisites.size();
        vector<int> result;
        
        if (n == 0) {
            for (int i = 0; i < numCourses; ++i) result.push_back(i);
            return result;
        }
        
        vector<int> degrees(numCourses); //this course depends on how many courses
        map<int, multiset<int>> edges; //course, dependencies on this course

        for (int i = 0; i < n; ++i) {
            degrees[prerequisites[i].first]++;
            edges[prerequisites[i].second].insert(prerequisites[i].first);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) q.push(i);
        }
        
        if (q.empty()) return {};
        
        while(!q.empty()) {
            int curCourse = q.front();
            q.pop();
            result.push_back(curCourse);
            
            for (auto dep : edges[curCourse]) {
                degrees[dep]--;
                if (degrees[dep] == 0) {
                    q.push(dep);
                }
            }
        }
        
        if (result.size() == numCourses) return result;
        return {};
        
    }
};