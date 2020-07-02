class Solution {
public:
    /**
     * @param cards: A list of cards.
     * @return: A list of feasible solution.
     */
    vector<int> getTheNumber(vector<int> &cards) {
        int len = cards.size();
        vector<int> res;
        
        for (int i = 1; i <= 9; ++i) {
            vector<int> nums = cards;
            nums.push_back(i);
            if (count(nums.begin(), nums.end(), i) > 4) continue;
            sort(nums.begin(), nums.end());
            
            if (is_hu(nums, false)) {
                res.push_back(i);
            }
        }
        
        if (res.size() == 0) return {0};
        else return res;
    }

private:
    bool is_hu(vector<int> & nums, bool has_sparrow) {
        int len = nums.size();
        if (len == 0) return true;
        int head_repeat_num = 1;
        
        for (int i = 1; i < len; ++i) {
            if (nums[i] == nums[i - 1]) head_repeat_num++;
            else break;
        }

        //如果没有雀头，但起始重复数字>=2，可做雀头，
        if (!has_sparrow) {
            if (head_repeat_num >= 2) {
                vector<int> new_nums(nums.begin() + 2, nums.end());
                if (is_hu(new_nums, true)) return true;
            }
        }
        
        //如果起始重复元素>=3，可做刻子，去掉刻子
        if (head_repeat_num >= 3) {
            vector<int> new_nums(nums.begin() + 3, nums.end());
            if (is_hu(new_nums, false)) return true;
        }
        
        //如果第1个元素跟后面某2个元素是顺子, 去掉顺子，注意顺子不一定紧挨着
        if (count(nums.begin(), nums.end(), nums[0] + 1) > 0 &&
            count(nums.begin(), nums.end(), nums[0] + 2) > 0) {
        //        vector<int> new_nums(nums.begin() + 3, nums.end());
        //        if (is_hu(new_nums, false)) return true;
        	vector<int> new_num(nums.begin() + 1, nums.end());         
		    new_num.erase(find(new_num.begin(), new_num.end(), nums[0] + 1));
		    new_num.erase(find(new_num.begin(), new_num.end(), nums[0] + 2));
		    if (is_hu(new_num, false))             
			    return true;  
            }
        
        return false;
    }
};