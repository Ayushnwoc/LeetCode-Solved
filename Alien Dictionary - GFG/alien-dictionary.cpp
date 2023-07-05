//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        map<char ,vector<char>>m ;
        unordered_map<char , int >indeg;
        for(int i = 1;i<N;i++){
            string a = dict[i-1], b = dict[i];
            for(int j = 0;j<min(a.length(),b.length());j++){
                if(a[j] != b[j]){
                    m[a[j]].push_back(b[j]);
                    indeg[b[j]]++;
                    if(indeg.find(a[j]) == indeg.end()){
                       indeg[a[j]]  = 0 ;
                    }
                    break;
                }
            }
        }
        queue<char>q;
        // unordered_map<char , int >vis(k , 0);
        for(auto i : indeg){
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.second == 0){
                q.push(i.first);
                // vis[i.first] = 1;
            }
        }
        string ans = "";
        while(!q.empty()){
            char f = q.front();q.pop();
            ans += f;
            for(auto i : m[f]){
                indeg[i]--;
                if(indeg[i] == 0){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends