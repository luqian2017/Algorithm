class Solution {
public:
    /**
     * @param elements: A list of recommended elements.
     * @param n: [picture P] can appear at most 1 in every n
     * @return: Return the scattered result.
     */
    vector<string> scatter(vector<string> &elements, int n) {
        int len = elements.size();
        vector<string> pics, videos;
        vector<string> result;
        
        int index = 0;
        while(elements[index][0] == 'V') {
            result.push_back(elements[index]);
            index++;
        }
            
        while(index < len) {
            if (elements[index][0] == 'V') {
                videos.push_back(elements[index]);
            } else {
                pics.push_back(elements[index]);
            }
            index++;
        }
        
        int pics_len = pics.size(), videos_len = videos.size();

        for (int i = 0; i < pics_len; ++i) {
            result.push_back(pics[i]);
            for (int j = 2 * i; j < 2 * i + n - 1; ++j) {
                if (j >= videos_len) return result; 
                result.push_back(videos[j]);
            }
            
        }

        return result;
    }
};