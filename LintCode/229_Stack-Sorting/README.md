229. Stack Sorting
中文English
Sort a stack in ascending order (with biggest terms on top).

You may use at most one additional stack to hold items, but you may not copy the elements into any other data structure (e.g. array).

You don't need to return a new stack, just sort elements in the given parameter stack.

Example
Given stack =

| |
|3|
|1|
|2|
|4|
 -
After sort, the stack should become:

| |
|4|
|3|
|2|
|1|
 -
The data will be serialized to [4,2,1,3]. The last element is the element on the top of the stack.

Notice
O(n^2) time is acceptable.

解法1：
用另一个栈tmpStack。先把stk里面的元素都pop到tmpStack。然后从tmpStack的顶部元素开始:
1) 如果该元素>stk的顶部元素，则pop该元素并将其push到stk;
2) 如果该元素<=stk的顶部元素，则pop该元素，将stk的顶部元素push到tmpStack，如此反复，直到该元素>stk的顶部元素。然后再将该元素push到stk。
3) 重复1)和2)直到tmpStack为空。

举例：stk={1,3,4,2}，2为top。
Step1: 将stk的元素都pop出并push到tmpStack。此时stk={}, tmpStack={2,4,3,1}
Step2: pop tmpStack的top元素2，并将其push到stk中。此时stk为空，故直接push。此时stk={2}, tmpStack={4,3,1}，4为top。
Step3: pop tmpStack的top元素4，将其与stk的top元素2比较，因为4>2，故将其push到stk。此时stk={4,2}, tmpStack={3,1}。
Step4: pop tmpStack的top元素3，将其与stk的top元素4比较，因为3<=4，故将4push到tmpStack。然后3继续与stk的top元素2比较，因为3>2，将3push到stk。此时stk={3,2}, tmpStack={4,1}。
Step5: pop tmpStack的top元素4，将其与stk的top元素3比较，因为4>3，故将4push到stk。此时stk={4,3,2}, tmpStack={1}。
Step6: pop tmpStack的top元素1，将其与stk的top元素4比较，因为1<=4，故将4push到tmpStack。然后将1与stk的top元素3比较，因为1<=3，故将3push到tmpStack。然后将1与stk的top元素2比较，因为1<=2，故将2push到tmpStack。此时stk已空，将1push到stk。
此时stk={1}, tmpStack={2,3,4}。
Step7: pop tmpStack的top元素2，将其与stk的top元素1比较，因为2>1，故将2push到stk。
Step8: pop tmpStack的top元素3，将其与stk的top元素2比较，因为3>2，故将3push到stk。
Step9: pop tmpStack的top元素4，将其与stk的top元素3比较，因为4>3，故将4push到stk。
此时stk = {4,3,2,1}, tmpStack={}。
Step10: 函数结束，stk就是所求内容。
