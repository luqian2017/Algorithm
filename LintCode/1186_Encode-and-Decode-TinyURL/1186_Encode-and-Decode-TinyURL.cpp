class Solution {
public:
    string encode(string &longUrl) {
       if (longUrl2id.find(longUrl) != longUrl2id.end()) {
           return "http://tiny.url/" + id2ShortKey(longUrl2id[longUrl]);
       }
       gId++;
       longUrl2id[longUrl] = gId;
       id2longUrl[gId] = longUrl;
       cout<<"http://tiny.url/" + id2ShortKey(gId)<<endl;
       return "http://tiny.url/" + id2ShortKey(gId);
    }

    
    string decode(string shortUrl) {
        const string tinyUrlHeader = "http://tiny.url/";
        int pos = tinyUrlHeader.size();

        long long id = shortKey2Id(shortUrl.substr(pos));
        return id2longUrl[id];
    }

private:
    map<string, long long> longUrl2id;
    map<long long, string> id2longUrl;
    
    long long gId = 0;
    long long shortKey2Id(string shortKey) {
        long long id = 0;

        for (int i = 0; i < min(6, (int)shortKey.size()); ++i) {
            if ('a' <= shortKey[i] && shortKey[i] <= 'z') {
                id = id * 62 + shortKey[i] - 'a';
            } else if ('A' <= shortKey[i] && shortKey[i] <= 'Z') {
                id = id * 62 + shortKey[i] - 'A' + 26;
            } else if ('0' <= shortKey[i] && shortKey[i] <= '9') {
                id = id * 62 + shortKey[i] - '0' + 52;
            }
        }
        cout<<"id="<<id<<endl;
        return id;
    }
    
    string id2ShortKey(long long id) {
        string shortKey;
        string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        while(id) {
            shortKey += charSet[id % 62];
            id = id / 62;
        }
        while(shortKey.size() < 6) {
            shortKey += 'a';
        }
        reverse(shortKey.begin(), shortKey.end());
        return shortKey;
    }

};
// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));