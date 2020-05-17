class Solution {
public:
    /**
     * @param S: An encoded string.
     * @param K: An index.
     * @return: Return the K-th letter (1 indexed) in the decoded string.
     */
    string decodeAtIndex(string &S, int K) {
        int n = S.size();
        long long len = 0;
        for (int i = 0; i < n; ++i) {
            cout<<"i="<<i<<" len="<<len<<endl;
            if (isalpha(S[i])) {
                len++;
                cout<<" len="<<len<<" "<<S[i]<<endl;
                if (len == K) return string(1, S[i]);
            } else {
                int num = S[i] - '0';
                if (len * num >= K) 
                {   
                    string newS = S.substr(0, i);
                    cout<<"   decode("<<newS<<", "<<(K - 1) % len + 1<<")"<<endl;
                    if (K % len == 0) {
                        return decodeAtIndex(newS, (K - 1) % len + 1);
                    } else {
                        return decodeAtIndex(newS, K % len);
                    }
                    //return decodeAtIndex(newS, (K - 1) % len + 1);
                }
                len *= num;
                cout<<"    len="<<len<<endl;
            }
        }
    }
};