class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int,int>m1;map<int,int>m2;
        if(node1 == node2)
        {
            return node1;
        }
        map<int , int >ind;
        for(int i = 0;i<edges.size();i++)
        {
            ind[edges[i]] = i;
        }
        dfs(node1 , edges , m1 );
        dfs(node2 , edges , m2 );
        m1[node1] = 0;
        m2[node2] = 0;
        int ans = INT_MAX;
        int node = -1;
        map<int,int>::iterator itr = m1.begin();
        while(itr != m1.end())
        {
            //cout<<itr->first<<" "<<itr->second<<" "<<m2[itr->first]<<endl;
            if(m2[itr->first] || itr->first == node2){
                if(ans > max(m2[itr->first],itr->second) ){
                    node = itr->first;
                    ans = max(m2[itr->first],itr->second);
                }
                else if(ans == max(m2[itr->first],itr->second) )
                {
                    //cout<<ind[itr->first]<<" "<<ind[node];
                    if(ind[itr->first] > ind[node])
                    {
                        node = itr->first;
                    }
                }
                
            }
            itr++;
        }
        return node;
    }
    void dfs(int node , vector<int>&edges , map<int,int>&m){
        int count = 0;
        while(node != -1 && !m[node] ){
            m[node] = count;
            count++;
            node = edges[node];
        }
        return;
    }
};