class TwoSum {
public:
    void add(int number) {
        unordered_multimap<int, int>::iterator it = dict.find(number);
        if (it == dict.end()) {
            dict.insert(pair<int, int>(number, 1));
        } else {
            it->second++;
        }
    }

 bool find(int value) {
        for (auto h : dict) { //or unordered_multimap<int,int>::iterator it; for (it=dict.begin(); it!=m.end(); it++)
            auto it=dict.find(value-h.first);  //note: h is not pointer, it is a pointer!!!
            if (it != dict.end()) {
                if ((value==(it->first << 1)) && (it->second==1)) continue; //8=4+4 but there is only one 4, then continue. Note: not return false here!
                return true;
            }
        }
        return false;
    }

private:
    unordered_multimap<int, int> dict;    
};