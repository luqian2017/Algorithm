class Solution {
   public:
    /**
     * @param elements: A list of recommended elements.
     * @param n: [picture P] can appear at most 1 in every n
     * @return: Return the scattered result.
     */
    vector<string> scatter(vector<string> &elements, int n) {
        // 定义双队列，分别存储图片元素 P, 视频元素 V
        queue<string> queueP, queueV;

        // 第 1 个图片 P 出现的位置
        int firstP = -1;
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i][0] == 'P') {
                // 第 1 个图片 P
                if (firstP == -1) {
                    firstP = i;
                }
                // 该元素加入 P 队列
                queueP.push(elements[i]);
            } else {
                // 该元素加入 V 队列
                queueV.push(elements[i]);
            }
        }
        //定义打散后的结果序列
        vector<string> result;

        //将出现第 1 个 P 前的 V 元素存入结果序列
        while (firstP--) {
            result.push_back(queueV.front());
            queueV.pop();
        }

        //辅助变量
        int step;
        while (!queueP.empty()) {
            // 每 n 个元素中需要恰好有 1 个 P
            result.push_back(queueP.front());
            queueP.pop();
            step = n;

            //将 n-1 个 V 元素存入结果序列
            while (!queueV.empty() && step > 1) {
                result.push_back(queueV.front());
                queueV.pop();
                step--;
            }

            //若当前已经无法满足打散要求，直接结束
            if (step > 1) {
                break;
            }
        }
        return result;
    }
};