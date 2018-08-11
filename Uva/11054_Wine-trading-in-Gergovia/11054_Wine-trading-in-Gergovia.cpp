long long WineLabor(long long a[], int len) {
     long long last, ans;

     for (int i=0; i<len; i++) {
         ans += abs(last);
         last += a[i];
     }
     return ans;
}