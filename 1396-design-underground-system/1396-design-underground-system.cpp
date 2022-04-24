class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> entry;  //id,<stationName,intime>
    unordered_map<string,pair<int,int>> db;    //start-end,<sumoftime,count>
    
    UndergroundSystem() {  }
    
    void checkIn(int id, string stationName, int t) {
        entry[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s=entry[id].first+"-"+stationName;
        db[s]={db[s].first+t-entry[id].second,db[s].second+1};
        entry.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s=startStation+"-"+endStation;
        return (double)db[s].first/db[s].second;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */