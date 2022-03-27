int bsqrt(int lo, int hi, int val)
{
    int mid;
    int sqr;
    int i = 0;
    while(lo+1 < hi){
        mid=(lo+hi)>>1;
        sqr=mid*mid;
        if(sqr <= val){
            lo=mid;
        }else{
            hi=mid;
        }
        i++;
    }
    if( lo*lo < val ) {
        return hi;
    }else{
        return lo;
    }
}
