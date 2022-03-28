int f()
{
    int lo = 1;
    int hi = 10;
    int val = 8;
    int x_mid;
    int mid;
    int sqr;
    while(lo+1 < hi){
        mid=(lo+hi)>>1;
        sqr=mid;
        x_mid = mid;
        lo = mid;
    }
    return x_mid;
    if( lo >= val ) {
        return hi;
    }else{
        return lo;
    }
}