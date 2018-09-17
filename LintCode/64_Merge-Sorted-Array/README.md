We can start from the tail of the two arrays: put the min of A and B's tail into A's final element, and adjust A or B's index accordingly.

Finally, 
if A list used out, then just move B's rest elements into A; 
if B list used out, we don't need to care as A's rest elements are in the expected place.
