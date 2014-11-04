struct Meeting {
    int start;
    int end;
    Meeting(int s, int e) : start(s), end(e) {}
};

struct comp {
    bool operator() (const Meeting& a , const Meeting& b) {
        return a.start < b.start;
    }
} comp;

int minNumOfRooms(vector<Meeting>& meetings) {
    if(meetings.size() == 0) {
        return 0;
    }
    vector<vector<Meeting> > room;
    sort(meetings.begin(), meetings.end(), comp);
    

    for(int i  = 0; i < meetings.size(); ++i) {
        bool flag = false;
        for(int j = 0; j < room.size(); ++j) {
            if(meetings[i].start >= room[j].back().end) {
                room[j].push_back(meetings[i]);
                flag = true;
            }
        }
        
        if(!flag) {
            vector<Meeting> tmp;
            tmp.push_back(meetings[i]);
            room.push_back(tmp);
        }
    }
    return room.size();
}
