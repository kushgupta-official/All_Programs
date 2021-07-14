class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset <int> sl,sr;
    int n;
    int p,q;
    MedianFinder() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sl.clear();
        sr.clear();
        n=p=q=0;
    }
    
    void addNum(int num) {
        // cout<<n<<" ";
        if (!sl.empty() and num>*sl.rbegin()){
            sr.insert(num);
        }
        else{
            sl.insert(num);
        }
        n++;
        p=ceil(n/2.0);
        q=n/2;
        while (sl.size()>p){
            sr.insert(*sl.rbegin());
            sl.erase(sl.find(*sl.rbegin()));
        }
        while (sr.size()>q){
            sl.insert(*sr.begin());
            sr.erase(sr.begin());
        }
    }
    
    double findMedian() {
        if (n%2){
            return (double)*sl.rbegin();
        }
        else{
            return (*sl.rbegin() + *sr.begin())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */