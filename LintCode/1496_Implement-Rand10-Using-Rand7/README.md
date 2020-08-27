1496. Implement Rand10() Using Rand7()
中文English
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

Example
Example 1:

Input：1
Output：[7]
Example 2:

Input：2
Output：[8,4]
Example 3:

Input：3
Output：[8,1,10]
Challenge
What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?
Notice
rand7` is predefined.
Each testcase has one argument: n, the number of times that rand10 is called.

这题不难但是很容易错！

解法1：

用两次rand7()，第1次先在0, 7, 14, ..., 42之间取，相当于取间隔。第2次在第一次的基础上加上rand7()。

这样生成的sum就是在1..49之间均匀分布的随机数。然后将其截取到1..40，返回(sum-1)/4+1，即1..4返回1， 5..8返回2，...，37..40返回10。

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution :public SolBase {
public:
    int rand10() {
        int a, b, sum;
        do
        {
            a = rand7() - 1;
            b = rand7();
            sum = a * 7 + b;
        } while(sum > 40);

        return (sum - 1) / 4 + 1;
    }
};


下面是我之前的做法。后来发现不对。
先调用1次rand7()，然后再调用1次rand7()，看其返回值是不是在1..4之间，若否则继续循环，否则将2次rand7()的返回值加起来。为什么第2次rand7()要看是不是在1..4之间而不是1..3之间呢，因为我们要把第2次rand7()的值减去1，对应到1..3，这样，sum1+sum2-1才对应到1..10。不然就是2..10了。

为什么不对呢？因为这是两个均匀随机变量rand1_7()和rand1_3()的和，结果会倾向于正态分布而不是均匀分布。比如说结果1只有(1,1)这一种可能性，结果6有(4,2),(3,3)这2种可能性，结果4有(1,3),(3,1)(2,2)这3种可能性。

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution :public SolBase {
public:
    int rand10() {
        int sum1 = 0, sum2 = 0;
        sum1 = rand7();
        while ((sum2 = rand7()) > 4) continue;
        return sum1 + sum2 - 1;
    }
};



网上看到几种解法，感觉不对。
1)

int rand10() {
return (rand7() + rand7() ) % 10 +1; 
}

这里的结果并不是在1..10上均匀分布。比如返回1的情况只有5+5这1种，概率p=1/49.
返回3的情况有1+1, 6+6这2种，概率p=2/49.
2)

    int rand10() {
         int num = rand7() * 10;
         return num / 7;
    }
这里的结果只会在1,3,4,5,7,8,10上分布。
3）

    int rand10() {
        while (true) {
            int x = rand7();
            int y = rand7();
            int prod = x * y;    
            if (prod > 40) continue;
            return (prod % 10) + 1;
        }
    }
这里的prod也不会在1..49上均匀分布。比如说31根本取不到，而12会取到很多次。12=3*4=4*3=2*6=6*2。
