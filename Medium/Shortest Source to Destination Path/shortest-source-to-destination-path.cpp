//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
         if(A[0][0]==0) return -1;
        int minDis=INT_MAX;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(N,vector<bool>(M));
        q.push({{0,0},0});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<pair<int,int>,int> temp=q.front();
                q.pop();
                if(temp.first.first==X && temp.first.second==Y){
                    minDis=min(minDis,temp.second);
                    continue;
                }
                if(temp.first.first-1>=0 && A[temp.first.first-1][temp.first.second]==1 && !vis[temp.first.first-1][temp.first.second]){
                    q.push({{temp.first.first-1,temp.first.second},temp.second+1});
                    vis[temp.first.first-1][temp.first.second]=true;
                }
                if(temp.first.first+1<N && A[temp.first.first+1][temp.first.second]==1 && !vis[temp.first.first+1][temp.first.second]){
                    q.push({{temp.first.first+1,temp.first.second},temp.second+1});
                    vis[temp.first.first+1][temp.first.second]=true;
                }
                if(temp.first.second-1>=0 && A[temp.first.first][temp.first.second-1]==1 && !vis[temp.first.first][temp.first.second-1]){
                    q.push({{temp.first.first,temp.first.second-1},temp.second+1});
                    vis[temp.first.first][temp.first.second-1]=true;
                }
                if(temp.first.second+1<M && A[temp.first.first][temp.first.second+1]==1 && !vis[temp.first.first][temp.first.second+1]){
                    q.push({{temp.first.first,temp.first.second+1},temp.second+1});
                    vis[temp.first.first][temp.first.second+1]=true;
                }
            }
        }
        return minDis==INT_MAX?-1:minDis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends