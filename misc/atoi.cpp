int atoi(const char *str) {
        if(!*str) return 0;
    
        int result = 0;
        int sign = 1;
        const char* p = str;
        
        while(*p ==' ') ++p;  // TO DO: Leave out *p to see what would happen
        
        if(*p=='+'){
            p++;
        }
        if(*p=='-') {
            p++;
            sign=-1;
        }
        
        for(; *p; p++){
            if(*p<'0' || *p>'9')
                break;
            int num = *p - '0';
            
            if(result>INT_MAX/10 || ((result==INT_MAX/10)&&(num>INT_MAX%10)) )
                return sign==1 ? INT_MAX : INT_MIN;
            
            result = result*10 + num;
            
        }
        
        return sign*result;
    }
