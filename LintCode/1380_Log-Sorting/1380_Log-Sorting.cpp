enum Type {
    LETTERS,
    DIGITS,
};

struct Entry {
    string id;
    string content;
    int index;
    Type tp;
    
    friend bool operator < (const Entry &a, const Entry &b);
};

bool operator < (const Entry &a, const Entry &b) {
    if ((a.tp == DIGITS) && (b.tp == DIGITS)) {
        return a.index < b.index;
    }
    if ((a.tp == LETTERS) && (b.tp == LETTERS)) {
         if (a.content == b.content) {
             if (a.id == b.id) {
                 return a.index < b.index;
             } else {
                 return a.id < b.id;
             }
         } else {
             return a.content < b.content;
         }   
    }
    
    return a.tp < b.tp;
}

class Solution {
public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        vector<string> result;
        int logCount = logs.size();
        vector<Entry> entries(logCount);
        for (int i = 0; i < logCount; ++i) {
            int pos = logs[i].find_first_of(' ');   
            entries[i].id = logs[i].substr(0, pos);
            entries[i].content = logs[i].substr(pos + 1);
            entries[i].index = i;
            entries[i].tp = (entries[i].content[0] >= '0') && (entries[i].content[0] <= '9') ? DIGITS : LETTERS;
        }    
        
        sort(entries.begin(), entries.end());    
        for (auto entry : entries) {
            result.push_back(entry.id + ' ' + entry.content);
        }
        
        return result;
    }
};
