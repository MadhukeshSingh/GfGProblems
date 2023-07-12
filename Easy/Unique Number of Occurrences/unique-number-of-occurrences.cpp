//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
         unordered_map<int, int> mp1;
        vector<bool> exist(n+1, false);
        
        for(int i = 0; i < n; i++) {
            mp1[arr[i]]++;
        }
        
        for(auto el : mp1) {
            if(exist[el.second]) {
                return false;
            }
            
            exist[el.second] = true;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends