string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string result;
        
        int maxL = max(a.size(), b.size());
        
        int carry = 0;
        
        for(int i=0; i<maxL; ++i){
            int num1 = i<a.size() ? a[i]-'0' : 0;
            int num2 = i<b.size() ? b[i]-'0' : 0;
            int sum = num1+num2+carry;
            int reminder = sum % 2;
            result.insert(result.begin(), reminder+'0');
            carry = sum/2; //要弄清变量的scope，之前在carry前加了int，结果出错了
        }
        
        if(carry == 1)
            result.insert(result.begin(),carry+'0');
        
        return result;
    }//eof
