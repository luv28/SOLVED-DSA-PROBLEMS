class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        m.clear();
    }
    
    bool book(int start, int end) {
        bool flag=true;
        for(auto const &[low,high]:m){
            if((start>=low && start<high) || (end>low && end<high) || (low>=start && low<end) || (high>start && high<end)){
                flag=false;
                break;
            }
        }
        if(!flag) return false;
        else{
            m[start]=end;
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */