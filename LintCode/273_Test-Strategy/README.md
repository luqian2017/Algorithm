273. Test Strategy

You have an exam, which lasts 120 minutes. There are multiple questions on the exam, and your answer order is not limited. There are three different strategies you can choose from for the question i:

Skip this question and get 0 points for no time.
Just do part of the problem. You would spend p[i] minutes and get part[i] points.
Do the whole problem. You would spend f[i] minutes and get full[i] points.
Given four arrays in turn: p, part, f, full, calculate the maximum number of points you can get.

Example
Sample 1:
Input sample: p=[20,50,100,5], part=[20,30,60,3], f=[100,80,110,10], full=[60,55,88,6]
Output sample: 94
Sample explanation: Of all the choices, choosing to complete the whole question 3 and the whole question 4 has the highest score. The whole of question 3 took 110 minutes to get 88 points, and the whole of question 4 took 10 minutes to get 6 points, so it took 120 minutes to get 94 points altogether.

Sample 2:
Input sample: p=[60,60], part=[30,30], f=[100,120], full=[40,60]
Output sample: 60
Sample explanation: You can choose doing part of the problem 1 and 2 or doing the whole of question 2. Either way you can get a maximum of 60 points in 120 minutes .

Clarification
We will run your code for 20times,. please ensure that you don't change the param in your function.

Notice
The number of examination questions is no more than 200 and at least 1.
Time spent on each question: 1 ≤ p[i] ≤ f[i] ≤ 120
Score of each question: 1 ≤ part[i] ≤ full[i] ≤ 100

