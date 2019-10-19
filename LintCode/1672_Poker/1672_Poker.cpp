1672. Poker
cat-only-icon
CAT Only
中文English
Given an integer array cards representing poker cards in your hand. The points of each card will be in range of [1, 9]. There are three ways to discard cards:

Discard any single card
Discard two or more cards with the same points
Discard at least 5 consecutive and distinct cards (for example 2, 3, 4, 5, 6)
How many times at least to discard all cards?

Example
Example 1:

Input: cards = [2, 2, 2, 3, 4, 5, 7, 1]
Output: 3
Explanation: 
  1. Discard 1, 2, 3, 4, 5
  2. Discard 2, 2
  3. Discard 7
Example 2:

Input: cards = [1, 2, 3, 4, 5, 5, 6, 7, 8, 9]
Output: 2
Explanation: 
  1. Discard 1, 2, 3, 4, 5
  2. Discard 5, 6, 7, 8, 9
Notice
The size of cards will not exceed 30.


class Solution {
public:
    /**
     * @param cards: 
     * @return: the minimal times to discard all cards
     */
    int getAns(vector<int> &cards) {
        int n = cards.size();
        if (n == 0) return 0;
      //  sort(cards.begin(), cards.end());
        int count = 0;
        map<int, int> mp; //num, count
        
        for (int i = 0; i < n; ++i) {
            if (mp.find(cards[i]) == mp.end()) {
                mp[cards[i]] = 1;
            } else {
                mp[cards[i]]++;
            }
        }
        
        //check >=5 consequtives
        for (int i = 1; i <= 5; ++i) {
            cout<<"i="<<i<<endl;
            while(1) {
              //  int conseqNum = 0;
                int index = i;
                if (mp[index] == 0) break;
                cout<<"index="<<index<<" count="<<count<<endl;
                while(index <= 9 && mp[index] > 0) {
                    index++;
                   // conseqNum++;
                }

                if (index - i >= 5) {
                    for (int j = i; j < index; ++j) {
                        mp[j]--;
                    }
                    count++;
                } else {
                    break;
                }
                // cout<<" i="<<i<<" not meet!"<<endl;
            }
        }
        
        //check two  or more cards with the same points
        for (int i = 1; i <= 9; ++i) {
            if (mp[i] > 1) {
                mp[i] = 0;
                cout<<"step2: i="<<i<<" count="<<count<<endl;
                count++;
            }
        }
        
        //check single cards
        for (int i = 1; i <= 9; ++i) {
            if (mp[i] == 1) {
                mp[i] = 0;
                count++;
                cout<<"step3: i="<<i<<" count="<<count<<endl;
            }
        }
        
        return count;
    }
};
[2, 2, 2, 3, 4, 5, 7, 1]
[1, 2, 3, 4, 5, 5, 6, 7, 8, 9]
[1,2,3,4,5,6,7,8,9,2]  
[6,4,8,3,6,5,8,7,4,2,5,5,4,6,1,1,4,7,5,9,6,8,6,6,4,7,4,5,2,7]    //8