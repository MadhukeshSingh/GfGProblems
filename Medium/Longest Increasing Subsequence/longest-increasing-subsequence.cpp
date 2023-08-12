//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int binarySearch(vector<int>&v, int a, int left, int right) {
        while( right > left) {
            int mid = (left + right)/2;
            
            if(v[mid] >= a) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return right;
    } 
    int longestSubsequence(int size, int a[])
    {
       // your code here
        vector<int>v;
        v.push_back(a[0]);
        
        for(int i=1; i<size; i++) {
            int n = v.size();
            if(a[i] > v[n-1]) v.push_back(a[i]);
            else {
                int index = binarySearch(v, a[i], 0, n-1);
                v[index]=a[i];
            }
        }
        return v.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends