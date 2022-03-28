int bsqrt(int lo, int hi, int val)
{
    int i = 0;
    while(lo+1 < hi && i < 2){
        int mid=(lo+hi)>>1;
        int sqr=mid*mid;
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
