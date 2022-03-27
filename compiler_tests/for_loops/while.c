int f()
{
    int lo = 1;
    int hi = 10;
    int val = 8;
    int x_mid;
    while(lo+1 < hi){
        int mid=(lo+hi)>>1;
        int sqr=mid;
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