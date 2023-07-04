//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fp(vector<vector<int>>&vis , int n , vector<vector<int>>&m,int x ,
    int y,int px , int py,string a){
        // cout<<x<<y<<endl;
        if(x < 0 or y < 0 or x>=n or y>=n or m[x][y] == 0 or vis[x][y] ==1 ){
            return;
        }
        if(x == n-1 and y == n-1){
            ans.push_back(a);
            return;
        }
        vis[x][y] = 1;
        if(x+1!=px ){
            fp(vis, n , m,x+1,y,x,y,a + 'D');
        }
        if(x-1!=px){
            fp(vis, n , m,x-1,y,x,y,a + 'U');
        }
        if(y-1!=py){
            fp(vis, n , m,x,y-1,x,y,a + 'L');
        }
        if(y+1!=py){
            fp(vis, n , m,x,y+1,x,y,a + 'R');
        }
        vis[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>vis(n+1, vector<int>(n+1,0));
        fp(vis, n , m,0,0,-1,-1 ,"");
        return ans;
    }
    vector<string>ans;
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends