class Solution {
public:
    /**
     * @param year: a number year
     * @param month: a number month
     * @return: Given the year and the month, return the number of days of the month.
     */
    int getTheMonthDays(int year, int month) {
        vector<int> normal_years = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return normal_years[month] + ((month == 2) ? 1 : 0);
        } else {
            return normal_years[month];
        }
    }
};