//Finding LIS and LDS in two seprate array
//In which value at i th index tell that at max that much length's subsequence can be found till that index

int Solution::longestSubsequenceLength(const vector<int> &A) {
   int n = A.size();
    int inc[n];
    int dec[n];
    int ct = 0;
    //LIS
    inc[0] = 1;
    for(int i=1; i<n; i++)
    {
        inc[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(A[i] > A[j] && inc[i] < inc[j] + 1)
                inc[i] = inc[j] + 1;
        }
    }
    //LDS
    dec[n-1] = 1;
    for(int i=n-2; i>=0; i--)
    {
        dec[i] = 1;
        for(int j=i+1; j<n; j++)
        {
            if(A[i] > A[j] && dec[i] < dec[j] + 1)
                dec[i] = dec[j] + 1;
        }
    }
  //Logic for finding  find the length of longest subsequence which is first increasing then decreasing
    int mx = 0;
    for(int i=0; i<n; i++)
        mx = max(mx, inc[i] + dec[i] - 1);

    return mx;
}
