void sortColors2(vector<int> &colors, int k) {
    vector<int> count(k+1);

    for (int i=0; i<colors.size(); ++i) {
        count[colors[i]]++;    
    }
    
	int pos=0;
    
	for (int i=1; i<=k; ++i) {
        for (int j=0; j<count[i]; ++j) {
            colors[pos++]=i;
        }
    }
}