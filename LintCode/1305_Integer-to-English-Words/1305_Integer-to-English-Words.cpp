class Solution {
public:
    /**
     * @param num: a non-negative integer
     * @return: english words representation
     */
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = helper(num);
        
        return result.substr(1); //skip the beginning " "
    }
    
private:
    vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string helper(int num) {
        if (num >= 1000000000) { //Billion 
            return helper(num / 1000000000) + " Billion" + helper(num % 1000000000);
        } else if (num >= 1000000) { //Million
            return helper(num / 1000000) + " Million" + helper(num % 1000000);
        } else if (num >= 1000) { //Thousand
            return helper(num / 1000) + " Thousand" + helper(num % 1000);
        } else if (num >= 100) { //Hundred
            return helper(num / 100) + " Hundred" + helper(num % 100);
        } else if (num >= 20) {
            return " " + tens[num / 10] + helper(num % 10);
        } else if (num >= 1) {
            return " "+ digits[num];
        } else {
            return "";
        }
    }
};