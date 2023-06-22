//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int k = pat.length();

    // Create an unordered map to store character frequencies in the pattern
        unordered_map<char, int> mp;
    
        // Count the frequency of characters in the pattern and store in the map
        for (int i = 0; i < k; i++) {
            mp[pat[i]]++;
        }
    
        // Count the number of unique characters in the pattern
        int count = mp.size();
    
        // Initialize variables for counting pattern occurrences and window indices
        int ans = 0;
        int i = 0;
        int j = 0;
    
        while (j < txt.length()) {
            // Include txt[j] for calculations
            if (mp.find(txt[j]) != mp.end()) {
                // Decrement the frequency of txt[j] in the map
                mp[txt[j]]--;
    
                // If the frequency becomes zero, decrement the count of unique characters
                if (mp[txt[j]] == 0) {
                    count--;
                }
            }
    
            // If the window size is less than k, expand the window
            if (j - i + 1 < k) {
                j++;
            }
            // If the window size is equal to k, slide the window and check for pattern match
            else if (j - i + 1 == k) {
                // If all unique characters in the pattern are matched, increment the answer
                if (count == 0) {
                    ans++;
                }
    
                // Exclude txt[i] from calculations
                if (mp.find(txt[i]) != mp.end()) {
                    // Increment the frequency of txt[i] in the map
                    mp[txt[i]]++;
    
                    // If the frequency becomes 1, increment the count of unique characters
                    if (mp[txt[i]] == 1) {
                        count++;
                    }
                }
    
                // Slide the window by incrementing i and j
                i++;
                j++;
            }
        }
    
        // Return the count of pattern occurrences
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends