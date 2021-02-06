#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 100
int F, V;
int dp[MAX_N + 5][MAX_N + 5] = {0};
int val[MAX_N + 5][MAX_N + 5] = {0};
int pos[MAX_N + 5][MAX_N + 5];
int ans_pos[MAX_N + 5];


int main() {
   cin >> F >> V;
	for (int i = 1; i <= F; i++) {
		dp[i][0] = -0x3f3f3f3f;
		for (int j = 1; j <= V; j++) {
		   cin >> val[i][j];
			dp[i][j] = -0x3f3f3f3f; 
		}
	}
	
	for (int i = 1; i <= F; i++) {
		 for (int j = 1; j <= V; j++) {
		    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + val[i][j]);
			 if (dp[i - 1][j - 1] + val[i][j] > dp[i][j - 1]) {
			     pos[i][j] = j;
			 } else {
			     pos[i][j] = pos[i][j - 1];
			 }
		 }    
	}
   
	cout << dp[F][V] << endl;
	
	int flower_cnt = F, position = pos[F][V];
	while (flower_cnt) {
	   ans_pos[flower_cnt] = position;
		flower_cnt--;
		position = pos[flower_cnt][position - 1];
	}

	for (int i = 1; i <= F; i++) {
	   if (i != 1) cout <<" ";
		cout << ans_pos[i]; 
	}
	
   cout << endl;
   return 0;

}