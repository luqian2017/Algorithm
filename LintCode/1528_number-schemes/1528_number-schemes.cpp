public class Solution {
    /**
     * @param position:  a  int array 
     * @param m: selected number
     * @param distance: the max distance
     * @return: return the number of schemes
     */
    public int getnumberschemes(int[] position, int m, int distance) {
        // write your code here
        int n = position.length, mod = 99997867;
        int[][] dp = new int[n + 1][m + 1];
        dp[0][0] = 1;
        long res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= Math.min(m, i); j++) {
                dp[i][j] = dp[i - 1][j];
                if (j == 1) dp[i][j] = (dp[i][j] + 1) % mod;
                else {
                    int idx = Arrays.binarySearch(position, position[i - 1] - distance);
                    if (idx < 0) idx = -idx - 1;
                    dp[i][j] = (int)(((long)dp[i][j] + dp[i - 1][j - 1] - dp[idx][j - 1]) % mod);
                }
                
                if (dp[i][j] < 0) dp[i][j] += mod;
                
                if (j == m) res = (res + dp[i][m] - dp[i - 1][m]) % mod;
            }
        }
        
        return (int)res;
    }
}

public class Solution {
    /**
     * @param position:  a  int array 
     * @param m: selected number
     * @param distance: the max distance
     * @return: return the number of schemes
     */
    public int getnumberschemes(int[] position, int m, int distance) {
        // write your code here
        int mod = 99997867;
        int n = position.length;
        int[][] dp = new int[2][n+1]; //前面的是新旧区别，后面是位置
        Queue<Integer>q = new LinkedList<Integer>();
        int now = 0, last = 1; //更新下标，一直用dp[last]去更新dp[now]
        //dp数组边界条件
        for (int i = 0; i < n; i++) {
            dp[now][i] = 1;
        }
        //交换now last，一直用dp[last]去更新dp[now]
        now = now ^ 1;
        last = last ^ 1;
        for(int i = 1; i < m; i++) {
            //清空本次被更新的 dp[now] 避免之前的值的影响
            for(int j = 0; j < n; j++) {
                dp[now][j] = 0;
            }
            //清空队列，避免上次循环留在队列的元素的影响
            while(!q.isEmpty()) {
                q.poll();
            }
            //队列里元素的和
            int tmp = 0;
            //将0到i-1压入队列
            for(int j = 0; j < i; j++) {
                tmp = (tmp + dp[last][j]) % mod;
                q.add(j);
            }
            //j从i开始，因为j>=i 才能选出i个元素来
            for(int j = i; j < n; j++) {
                //判断队列头部是否能更新j
                while(!q.isEmpty() && position[j] - position[q.peek()] > distance) {
                    //弹出队首 更新tmp
                    tmp -= dp[last][q.peek()];
                    tmp = (tmp + mod) % mod;
                    q.poll();
                }
                //更新dp[i][j]
                dp[now][j] = tmp;
                //更新tmp，压入j
                tmp = (tmp + dp[last][j]) % mod;
                q.add(j);
            }
            //交换now last，这样下次就是dp[last]去更新dp[now]
            now = now ^ 1;
            last = last ^ 1;
        }
        //最终答案要枚举最后一个元素从哪里选的
        int ans = 0;
        for(int i = m - 1; i < n; i++) {
            //now last 最后交换，所以dp[M-1]应该是dp[last]
            ans = (ans + dp[last][i]) % mod;
        }
        return ans;
    }
}