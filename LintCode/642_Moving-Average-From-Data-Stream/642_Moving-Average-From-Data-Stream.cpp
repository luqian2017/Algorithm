//Version 1: using deque

class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) : sum(0), _size(size) {
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {

        if (wind_rt.size() == _size) {
            sum -= wind_rt.front();
            wind_rt.pop_front();
            wind_rt.push_back(val);
            sum += val;
            return sum/_size;
        } else {
            wind_rt.push_back(val);
            sum += val;
            return sum/wind_rt.size();
        }    
    }
private:
    deque<int> wind_rt;
    int _size;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
 
 
 