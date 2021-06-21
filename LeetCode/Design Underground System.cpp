class UndergroundSystem {
public:
    unordered_map <string,pair<int,int> > station_mp;
    unordered_map <int,pair<string,int> > cust_mp;
    
    UndergroundSystem() {
        // station_mp[{"a","a"}]={0,0};
        // cust_mp[0]={"a",0};
    }
    
    void checkIn(int id, string stationName, int t) {
        cust_mp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int diff=t-cust_mp[id].second;
        station_mp[{cust_mp[id].first+" "+stationName}].first+=diff;
        station_mp[{cust_mp[id].first+" "+stationName}].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return 
            (double)station_mp[{startStation+" "+endStation}].first 
            / 
            station_mp[{startStation+" "+endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */