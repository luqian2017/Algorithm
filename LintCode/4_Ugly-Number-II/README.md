Each ugly number is determined by the minimum of among the 3 lists. If the minimum is chosen, the corresponding Id will increment by one. 

Note that **it is possible that 2 lists or 3 lists have the same minimum** (e.g., 5x2 and 2x5), **in this case the Ids among all lists will need to increment by one**.

(1) **1x2**, 2x2, **2x2**, 3x2, **3x2**, **4x2**, 5x2, **5x2**, 5x3 …
 
(2) 1x3, **1x3**, 2x3, 2x3, 2x3, 3x3, **3x3**, 3x4, **3x4**…
 
(3) 1x5, 1x5, 1x5, **1x5**, 2x5, 2x5, 2x5, **2x5**, 3x5…

In addition, below is the function that can be used to judge if a number if ugly number:

bool isUgly(int num) {
        
    if (num <= 0) {
        return false;
    }
        
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
        
    if (num == 1) {
        return true;
    } else {
        return false;
    }
}