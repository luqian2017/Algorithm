//Recursive version

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const  int maxn=100000+5;
int n,T;
vector<int> sons[maxn];

int dp(int u) {
    if (sons[u].empty()) return 1;
    vector<int> d;

    for (int i=0; i<sons[u].size(); i++)
        d.push_back(dp(sons[u][i]));

    sort(d.begin(), d.end());
    int c = (sons[u].size()*T-1)/100 + 1;
    int ans = 0;

    for (int i=0; i<c; i++)
        ans+=d[i];

    return ans;
}


int main()
{
    int boss;
    while(scanf("%d%d", &n, &T)==2 && n) {
        for (int i=0; i<=n; i++) 
             sons[i].clear();
        for (int i=1; i<=n; i++) {
             scanf("%d", &boss);
             sons[boss].push_back(i);
        }
        cout<<dp(0)<<endl;
    }

    return 0;
}


//Non-recursive version

#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>

using namespace std;
const  int maxn=100000+5;
int n,T;
vector<int> sons[maxn];
int parent[maxn] = {0};

stack<int> s;
int ans[maxn] = {0};

int dp_non_recursion() {
    vector<int> d;

    //从老板开始,依次将儿子压栈
    s.push(0);

    for (int i=0; i<n; i++)
        for (int j=0; j<sons[i].size(); j++)
                s.push(sons[i][j]);

    while(!s.empty()) {
        d.clear();
        int t = s.top();
        s.pop();
        if (sons[t].size()==0)
            ans[t]=1;
        else{
            for (int i=0; i<sons[t].size(); i++) {
                d.push_back(ans[sons[t][i]]);
            }
            sort(d.begin(), d.end());
            int c = (sons[t].size()*T-1)/100 + 1;
            for (int i=0; i<c; i++)
                ans[t]+=d[i];
        }
    }

    return ans[0];
}


int main()
{
    int boss;
    while(scanf("%d%d", &n, &T)==2 && n) {
        for (int i=0; i<=n; i++) {
             sons[i].clear();
             ans[i]=0;
        }
        for (int i=1; i<=n; i++) {
            scanf("%d", &boss);
            parent[i]=boss;
            sons[boss].push_back(i);
        }
        cout<<dp_non_recursion()<<endl;
    }
    return 0;
}