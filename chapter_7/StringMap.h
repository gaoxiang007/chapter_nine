

//
//  StringMap.h
//  StringMap
//
//  Created by Peter Liu on 9/30/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#ifndef __StringMap__StringMap__
#define __StringMap__StringMap__

#include <iostream>
#include <string>


class StringMap {

 public:
    StringMap();
    ~StringMap();
    std::string get(const std::string & key) const;
    void put(const std::string& key, const std::string & value);
    
    

 private:
    struct Cell {
        std::string key;
        std::string value;
        Cell* link;
    };
    
    static const int INITIAL_BUCKET_COUNT = 13;
    
    Cell** buckets;
    int nBuckets;
    
    Cell* findCell(int bucket, const std::string & key);
    
    
    // make copying illegal
    StringMap(const StringMap& src);
    StringMap & operator=(const std::string & src);
    
};


StringMap::StringMap() {
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell*[nBuckets];
    for(int i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }
}

StringMap::~StringMap() {
    for(int i = 0; i < nBuckets; ++i) {
        Cell* cp = buckets[i];
        while(cp != NULL) {
            Cell* oldCell = cp;
            cp = cp->link;
            delete oldCell;
        }
    }
}

std::string StringMap::get(const std::string & key) const {
    int bucket = hashfunc(key) % nBuckets;
    Cell* cp = findCell(bucket, key);
    return cp == NULL ? "" : cp->value;
}

void StringMap::put(const std::string& key, const std::string & value) {
    int bucket = hashfunc(key) % nBuckets;
    Cell* cp = findCell(bucket, value);
    if(cp == NULL) {
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
    }
    cp->value = value;
}

Cell* StringMap::findCell(int bucket, const std::string & key) {
    Cell* cp = buckets[bucket];
    while(cp != NULL && key != cp->key) {
        cp = cp->link;
    }
    return cp;
}


#endif /* defined(__StringMap__StringMap__) */

