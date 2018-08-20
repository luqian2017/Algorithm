参考的紫皮书上的例子，Unique snowflakes, Uva 11572。两个函数分别用set和map，代码与紫皮书上稍有差别。

set里面就是放的滑动窗口。map< key, value >里面key是 a[i], value是a[i]的上一个相同位置的下标。用set有点好处就是最后函数返回的时候, set里面就是滑动窗口的各个元素。用map则只能返回l,r的值。

这题也是学习set和map的好例子。

想了一下，其实第二种方法还有一点优化空间。在while的else分支里面，l可以直接跳到lastExist[r]+1，而不是逐一递增。因为我们已经知道else分支对应l<=lastExist[r]<=r, 在l到lastExist(r)之间我们不需要再试了(因为有重复a[r])，直接将l跳到lastExist[r]+1即可。不过这种优化后的复杂度仍然是o(nlogn)。

//using map
int unique_snowflakes_2(int a[], int len) {
    int maxLen = 0;
    map<int, int> m;

    int lastExist[len];
    for (int i=0; i<len; i++) {
        if (!m.count(a[i])) {
            lastExist[i] = -1;
        }
        else{
            lastExist[i] = m[a[i]];
        }

        m[a[i]] = i;
    }

    int l=0, r=0;
    while (r!=len) {
        if (lastExist[r]<l) { //lastExist(r)<l<=r
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        else{  //l<=lastExist(r)<=r
            // l++;
            l=lastExist[r]+1;
        }
    }

    return maxLen;

}

要注意的一点是：
1) set.count(x)和map.count(x)都只返回0或1。0表示集合中没有x，1表示有。注意这里即使x在set或map中出现多次，这两个count()也只返回1。切记！
在这道题中我们不需要记录x的出现次数。那么如果需要的话办呢？自己写个数组cnt[]，每一项对应每个元素出现的次数，然后insert()和erase()的时候加加减减就可以了。