class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(nullptr));
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        
        if (mp.find(val) != mp.end()) return false;
        
        vec.push_back(val);
        mp[val] = vec.size();
        return true;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        
        int index = mp[val];
        //swap last element in the vec with the element in the vec that contains val
        int temp = vec[index];
        vec[index] = vec.back();    //vec.back() is the reference to the last element in the vec.
        vec.back() = temp;
        
        //remove the element in the mp and vec
        mp.erase(val);
        vec.pop_back();
        return true;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        if (vec.size() == 0) return 0;   //note: n % 0 is wrong as it will divide 0
        
        return vec[rand() % vec.size()];
    }

private:
    unordered_map<int, int> mp;    //value, index
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */