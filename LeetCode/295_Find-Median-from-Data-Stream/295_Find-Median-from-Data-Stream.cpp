class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smallSet.size() <= largeSet.size()) { //add to smallSet
            if (largeSet.size() == 0 || num < *largeSet.begin()) {
                smallSet.insert(num);
            } else {
                largeSet.insert(num);
                smallSet.insert(*largeSet.begin());
                largeSet.erase(largeSet.begin());
            }
        } else {
            if (smallSet.size() == 0 || num > *smallSet.rbegin()) { //add to largeSet
                largeSet.insert(num);
            } else {
                smallSet.insert(num);
                largeSet.insert(*smallSet.rbegin());
                smallSet.erase(--smallSet.end());
            }
        }
    }
    
    double findMedian() {
        if (largeSet.size() > smallSet.size()) {
            return *largeSet.begin();
        } else if (largeSet.size() < smallSet.size()) {
            return *smallSet.rbegin();
        } else {
            return (*largeSet.begin() + *smallSet.rbegin()) / 2.0;
        }
    }
private:
    multiset<int> largeSet, smallSet;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */