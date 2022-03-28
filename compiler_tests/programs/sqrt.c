int bsqrt(int lo, int hi, int val)
{
    int mid;
    int sqr;
    while(lo+1 < hi){
        mid=(lo+hi)>>1;
        sqr=mid*mid;
        if(sqr <= val){
            lo=mid;
        }else{
            hi=mid;
        }
    }
    if( lo*lo < val ) {
        return hi;
    }else{
        return lo;
    }
}
