此题不难，但要注意：
1）与最大直方图面积问题区分: 如果输入是a[3]={2,1,2}, 直方图面积会是3=1*3，而该蓄水池问题的答案是4=2*2。因为直方图问题主要考虑区间中最低的那个，而该蓄水池问题会忽略掉中间低的部分。
2）不需要考虑挡板，也就是说a[3]={1,2,1}的结果是2。

解法为用两个指针，一前一后扫描。如果前面的高，则移后面的指针，反之移前面的指针。然后每次都记录两指针值之间的面积，最后返回最大值即可。