//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&Knightpos,vector<int>&TargetPos,int N)
	{
	    queue<pair<int,pair<int,int>> > q;
	    q.push({Knightpos[0] ,{ Knightpos[1] , 0}});
	    vector<vector<int>>vis(N+1 , vector<int>(N+1 , 0));
	    vis[Knightpos[0]][Knightpos[1]] = 1;
	    int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
        int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
	    while(!q.empty()){
	        int fx = q.front().first;
	        int fy = q.front().second.first;
	        int t = q.front().second.second;
	        q.pop();
	        for(int i=0;i<8;i++){
               int newx=fx+dx[i];
               int newy=fy+dy[i];
               if(newx>=0 and newx<N and newy>=0 and newy<N and vis[newx][newy]==0){
                   vis[newx][newy]=1;
                   q.push({newx,{newy,t+1}});
               }
               if(TargetPos[0]==newx and TargetPos[1]==newy) return t+1;
           }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends