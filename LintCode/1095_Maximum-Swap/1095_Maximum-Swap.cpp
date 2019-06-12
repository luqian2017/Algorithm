class Solution {
public:
    /**
     * @param num: a non-negative intege
     * @return: the maximum valued number
     */
    int maximumSwap(int num) {
        if (num < 10) return num;
        
        vector<int> numbers;
        
        while(num) {
            numbers.push_back(num % 10);
            num /= 10;
        }
        
        int len = numbers.size();
        
        int maxDigit = 0, maxDigitIndex = 0, secondMaxDigit = 0, secondMaxDigitIndex = 0;
        for (int i = 0; i < len; ++i) {
            if (secondMaxDigitIndex < numbers[i]) {
                secondMaxDigit = numbers[i]; 
                secondMaxDigitIndex = i;
                if (secondMaxDigit > maxDigit) {
                    swap(maxDigit, secondMaxDigit);
                    swap(maxDigitIndex, secondMaxDigitIndex);
                }
            }
        }

        if (maxDigitIndex == len - 1) {
            if (numbers[len - 2] == secondMaxDigit && len > 3) {
                for (int i = len - 3; i >= 0; --i) {
                    if (numbers[i] != secondMaxDigit) {
                        swap(numbers[secondMaxDigitIndex], numbers[i]);
                        break;
                    }
                }
            } else {
                swap(numbers[secondMaxDigitIndex], numbers[len - 2]);
            }
        } else {
            swap(numbers[maxDigitIndex], numbers[len - 1]);
        }

        num = 0;
        for (int i = len - 1; i >= 0; --i) {
            num = num * 10 + numbers[i];
        }
        
        return num;
    }
};