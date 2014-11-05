string getNext(string old) {
        int n = old.size();
        string new_string;
        for(int i = 0; i < n; ++i) {
            int count = 1;
            while(i < n-1 && old[i] == old[i+1]) {
                count++;
                ++i;
            }
            new_string += to_string(count).c_str();
            new_string += old[i];
        }
        return new_string;
    }
    
    string countAndSay(int n) {
        if(n <= 0) {
            return NULL;
        }
        string old("1");
        //string new_string;
        for(int i = 0; i < n - 1; ++i) {
            string new_string = getNext(old);
            old = new_string;
        }
        return old;
    }
