424. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Example
Example 1:

Input: ["2", "1", "+", "3", "*"] 
Output: 9
Explanation: ["2", "1", "+", "3", "*"] -> (2 + 1) * 3 -> 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: ["4", "13", "5", "/", "+"] -> 4 + 13 / 5 -> 6

解法1：用栈。
注意：
1) 只用一个栈保存数字(不能用另一个栈保存操作符)。操作符按顺序来就可以了。
2) 每次如果是数字，栈pop两次，然后将两个数字按操作符类型处理，将处理的结果再放入栈中。最后返回栈顶即可。
3) 数字可能为负数。
4) 可用下面的函数来判断一个token是否为Operator(+-*/)
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }

解法2：DFS。
逆波兰表达式的末尾必定是操作符，所以可从末尾开始处理:
1) 遇到数字直接返回;
2) 遇到操作符，向前两个位置调用递归函数，找出前面两个数字，然后进行操作将结果返回，
注意：
1) 一个大坑：helper()的入口参数的index必须是指针或引用。
以input=["4", "13", "5", "/", "+"]为例：
如果index不加&，则index打印顺序为4,3,2,1,2
如果index加&，则index打印顺序为4,3,2,1,0
从trace开始分析，index不加&的情情形：
一开始index=4，调用num1=helper(tokens, 3)。
     helper() //index=4
         //opt = "+"
         =>num1 = helper(--index); //index=4-1=3
             //opt = “/”
             =>num1 = helper(--index)； //index = 3-1=2
             =>num2 = helper(--index;     //index=2-1=1
             //num1 = 13/5=2
         =>num2 = helper(--index); //此时仍然为index=3-1=2 出错
index加了&后，最下面的num2的index为1，所以num2=helper(0)直接返回tokens[0]，结果正确。