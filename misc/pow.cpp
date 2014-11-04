double pow(double x, int n) {
    if(n == 0) {
        return 1.0;
    }
    if(n == 1) {
        return x;
    }
    double tmp = pow(x, n/2);
    if(n % 2 == 0) {
        return tmp * tmp;
    } else {
        if(n >= 0) {
            return tmp * tmp;
        } else {
            return tmp * tmp / x;
        }
    }
}
