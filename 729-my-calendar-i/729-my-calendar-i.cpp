class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        map<pair<int,int> , int>::iterator itr = m.begin();
        if(m[{start , end}]){
            return false;
        }
        m.erase({start , end});
        while(itr != m.end()){
            int avg = (itr->first.first + itr->first.second )/2;
            if(start > itr->first.first && start < itr->first.second){
                if(start == 2 && end == 8)
                {
                    cout<<"spe "<<itr->first.first<<" "<<itr->first.second<<endl;
                }
                return false;
            }
            if(end >itr->first.first && end<itr->first.second){
                return false;
            }
            if(start <= avg && end > avg){
                return false;
            }
            itr++;
        }
        m[{start , end}] = 1;
        return true;
    }
    map< pair<int,int> , int>m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */