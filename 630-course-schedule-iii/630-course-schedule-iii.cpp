class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end(), [](
        vector<int>&a , vector<int>&b){
                return a[1] < b[1];
        });
        int time = 0;
        priority_queue<int>q;
        for(int i = 0;i<courses.size();i++){
            if(time + courses[i][0] <= courses[i][1]){
                q.push(courses[i][0]);
                time += courses[i][0];
            }
            else{
                if(!q.empty() && courses[i][0] < q.top()){
                    
                    time -= q.top();q.pop();
                    q.push(courses[i][0]);
                    time += courses[i][0];
                }
            }
        }
        return q.size();
    }
};