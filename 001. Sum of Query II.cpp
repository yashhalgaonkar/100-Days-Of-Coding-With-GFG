class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + arr[i];
        
        vector<int> res;
        for(int i = 0; i < 2*q; i+=2)
        {
            int left = queries[i]-1;
            int right = queries[i+1]-1;
            
            res.push_back(prefix[right] - prefix[left] + arr[left]);
        }
        
        return res;
    }
};