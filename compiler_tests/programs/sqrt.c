int bsqrt(int lo, int hi, int val)
{
    int x_mid;
    while(lo+1 < hi){
        int mid=(lo+hi)>>1;
        int sqr=mid;
        x_mid = mid;
        if(sqr < val){
            lo=mid;
        }else{
            hi=mid;
        }
    }
    return x_mid;
    if( lo >= val ) {
        return hi;
    }else{
        return lo;
    }
}
