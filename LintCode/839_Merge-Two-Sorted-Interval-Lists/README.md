My solution is using p1 and p2 points to the current elements in list1 and list2.

In the beginning, itv is the one pointed by p1 or p2 (depending on which left side is smaller), then continuously judge if itv is overlapping with p1 or p2's element.

If so, then merge and update p1 or p2 accordingly. 

If not, then push_back itv to result, and update itv as the new element pointed by p1 or p2 (depending on which left side is smaller), and continue the loop, until both p1 and p2 reach the end.

Do remember to push_back the last itv after the loop ends.