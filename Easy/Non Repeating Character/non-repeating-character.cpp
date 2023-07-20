//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
        int n= S.size();
    
   
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(S[i]==S[j]){
                flag=false;
                break;
            }
        }
        
        if(flag==true){
            return S[i];
        }
    }
    
    return (char)36;
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends