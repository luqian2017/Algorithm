275. Moving Shed
中文English
There are some cars parked. Given an array of integers 'stops', represents where each car stops. Given an integer 'k', now you're going to build a moving shed. When the shed is required to move between these cars (the front end of the shed does not exceed the car in front, and the back end of the shed does not exceed the car in the back), it can successfully cover 'k' cars in any time. Ask for the minimum length of the shed that meets the requirements.

Example
Sample 1:
Input: stops=[7,3,6,1,8], k=3
Output: 6
Explanation: these 5 cars are in positions 1,3,6,7,8 respectively.The shed needs to cover at least 3 cars, with a minimum length of 6, as it can cover 3 or more cars in [1,6], [2,7], [3,8]. If the length is 5, it only covers 1 car when built in [1,5] and [2,6] , which does not meet the conditions.

Sample 2:
Input: stops=[7,3,6,1,8], k=2
Output: 5
Explanation: these 5 cars are in positions 1,3,6,7,8 respectively.The shed needs to cover at least 2 cars with a minimum length of 5, as it can cover 2 or more cars in [1,5], [2,6], [3,7], [4,8]. If the length is 4, it only covers 1 car when built in [2,5], which does not meet the conditions.

Notice
The length of stops : [2,1000].
The size of the element in 'stops' : [1,10000].
2 ≤ 'k' ≤ the length of stops.
Ensure that the elements in 'stops' are not repeated.

