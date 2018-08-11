#include <iostream>

using namespace std;

const int maxn=100000+5;
int n, p[maxn], q[maxn];

int travel(int p[], int q[], int n) {
    int finish = 0;
    int ans = -1;
    for (int start=0; start<n; start=finish) {
        finish = start;
        int fuel = 0, sum = 0;
        while ((ans<0) && (fuel>=0)) {
            fuel+=p[finish]-q[finish];
            finish++;
            sum++;
            if ((sum==n) && (fuel>=0))
                ans=start;
        }

        if (ans>=0)
            return ans+1;   //因为下标从0开始算
    }

    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k=1; k<=T; k++) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &p[i]);
            p[i+n]=p[i];
        }
        for (int i=0; i<n; i++) {
            scanf("%d", &q[i]);
            q[i+n]=q[i];
        }

        int ans = travel(p,q,n);
        printf("Case %d: ", k);
        if(ans < 0)
            cout<<"Not possible"<<endl;
        else
            cout<<"Possible from station "<<ans<<endl;
    }
    return 0;
}

int travel2(int p[], int q[], int n) {

    int start = 0, finish =0, fuel = 0;
    while(1) {
        //重新开始
        finish = start+1;
        fuel = p[start] - q[start];
        while (finish != start) {   //no wrap，注意这里不可以用finish > start, 否则wrap后自动退出
            if ((fuel < 0))
                break;
            fuel += p[finish] - q[finish];
            finish = (finish + 1) % n;
        }

        if (finish > start)
            start = finish;
        else if (finish < start)
            return -1;
        else //finish == start, 走完一圈，但是还是要看fuel
            if (fuel >= 0)
                return finish + 1; //因为下标从0开始算
            else
                return -1;
    }
}