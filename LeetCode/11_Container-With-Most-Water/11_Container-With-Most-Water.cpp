int maxArea(vector<int>& height) {
    int p1=0, p2=height.size()-1;
    int volume=0, maxVolume=0;

    while(p1<p2) {
       int volume;
       if (height[p2]>height[p1]) {
           volume=(p2-p1)*height[p1];
           p1++;
       }else{
           volume=(p2-p1)*height[p2];
           p2--;
       }
       maxVolume=max(maxVolume, volume);
    }
    return maxVolume;
}
