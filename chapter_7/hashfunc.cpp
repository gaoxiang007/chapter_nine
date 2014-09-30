// option 1
int hashfunc(string key) {
    return md5(key) % HASH_TABLE_SIZE;
}




// option 2
int hashfunc(string key) {
    int sum = 0;
    for(int i = 0; i < key.size(); ++i) {
        sum = sum * 33 + (int)(key[i]);
        sum = sum % HASH_TABLE_SIZE;
    }
    return sum;
}
