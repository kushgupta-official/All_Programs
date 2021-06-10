class MyCalendar {
public:
    set <int> s;
    unordered_map <int,int> mp;
    // MyCalendar() {
    //     // s.insert(0);
    //     // mp[0]=0;
    // }
    /*
        previous start value-->
            check p_end if < start
        next start value-->
            end<n_start
            
    */
    bool book(int start, int end) {
        if (s.empty()){
            s.insert(start);
            mp[start]=end-1;
            return true;
        }
        auto ite=s.lower_bound(start);
        
        if ((ite==s.end() and mp[*(--ite)]<start) or (*ite!=start and *ite>end-1 and (ite==s.begin() or                                                                                                 mp[*(--ite)]<start) ) ){
            s.insert(start);
            mp[start]=end-1;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */