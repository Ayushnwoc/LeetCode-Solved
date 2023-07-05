//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>& p) {
	    vector<vector<int>>adj(N);
	    vector<int>indeg(N,0), vis(N,0);
	    for(auto i : p){
	        adj[i.first].push_back(i.second);
	        indeg[i.second]++;
	    }
	    queue<int>q;
	    for(int i = 0;i<N;i++){
	        if(!indeg[i]){
	            q.push(i);
	            vis[i] = 1;
	        }
	    }
	    while(!q.empty()){
	        int f = q.front();q.pop();
	        for(auto i : adj[f]){
                indeg[i]--;
                if(indeg[i] == 0){
                    q.push(i);
                    vis[i] = 1;
                }
	        }
	    }
	    for(int i = 0;i<N;i++){
	        if(!vis[i]){
	            return false;
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends