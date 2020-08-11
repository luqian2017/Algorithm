class Solution {
public:
    /**
     * @param x: an array of integers, the x coordinates of each city[i]
     * @param y: an array of integers, the y coordinates of each city[i]
     * @param c: an array of strings that represent the names of each city[i]
     * @param q: an array of strings that represent the names of query locations
     * @return: the closest city for each query
     */
    vector<string> NearestNeighbor(vector<int> &x, vector<int> &y, vector<string> &c, vector<string> &q) {
        int n = x.size();
        vector<string> result;
        unordered_map<int, vector<pair<int, string>>> x_cities;  //x->list of (y, city)
        unordered_map<int, vector<pair<int, string>>> y_cities;  //y->list of (x, city)
        
        unordered_map<string, int> city_x; //city->x
        unordered_map<string, int> city_y; //city->y
        
        for (int i = 0; i < n; ++i) {
            x_cities[x[i]].push_back({y[i], c[i]});
            city_x[c[i]] = x[i];
        }
        
        for (int i = 0; i < n; ++i) {
            y_cities[y[i]].push_back({x[i], c[i]});
            city_y[c[i]] = y[i];
        }
        
        for (auto &elem : x_cities) { //注意加引用
            sort(elem.second.begin(), elem.second.end()); //sort y values under the same x
        }

        for (auto &elem : y_cities) { //注意加引用
            sort(elem.second.begin(), elem.second.end()); //sort x values under the same y
        }

        for (int i = 0; i < q.size(); ++i) {
           int min_dist = INT_MAX;
            string closest_city = "NONE";
            int target_x = city_x[q[i]];
            int target_y = city_y[q[i]];
            int dist = 0;
            if (x_cities[target_x].size() > 1) {
                int find_y_index = binary_search(x_cities[target_x], target_y);
                if (find_y_index != -1) { //one city does not need to search
                    if (find_y_index > 0) {
                        dist = x_cities[target_x][find_y_index].first - x_cities[target_x][find_y_index - 1].first;
                        if (min_dist > dist || (min_dist == dist && x_cities[target_x][find_y_index - 1].second < closest_city)) {
                            min_dist = dist;
                            closest_city = x_cities[target_x][find_y_index - 1].second;
                        }
                    }
                    if (find_y_index < x_cities[target_x].size() - 1) {
                        dist = x_cities[target_x][find_y_index + 1].first - x_cities[target_x][find_y_index].first;
                        if (min_dist > dist || (min_dist == dist && x_cities[target_x][find_y_index + 1].second < closest_city)) {
                            min_dist = dist;
                            closest_city = x_cities[target_x][find_y_index + 1].second;
                        }
                    }
                }
            }
            
            if (y_cities[target_y].size() > 1) { //one city does not need to search
                int find_x_index = binary_search(y_cities[target_y], target_x);
                if (find_x_index != -1) {    
                    if (find_x_index > 0) {
                        dist = y_cities[target_y][find_x_index].first - y_cities[target_y][find_x_index - 1].first;
                        if (min_dist > dist || (min_dist == dist && y_cities[target_y][find_x_index - 1].second < closest_city)) {
                            min_dist = dist;
                            closest_city = y_cities[target_y][find_x_index - 1].second;
                        }
                    }
                    if (find_x_index < y_cities[target_y].size() - 1) {
                        dist = y_cities[target_y][find_x_index + 1].first - y_cities[target_y][find_x_index].first;
                        if (min_dist > dist || min_dist == dist && y_cities[target_y][find_x_index + 1].second < closest_city) {
                            min_dist = dist;
                            closest_city = y_cities[target_y][find_x_index + 1].second;
                        }
                    }
                }
            }
            result.push_back(closest_city);
        }
        
        return result;
    }
    
private:
    int binary_search(vector<pair<int, string>> arr, int target) {
        int start = 0, end = arr.size() - 1;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid].first < target) {
                start = mid;
            } else if (arr[mid].first > target) {
                end = mid;
            } else {
                return mid;
            }
        }
        
        if (arr[end].first == target) return end;
        if (arr[start].first == target) return start;
        return -1;
    }
};