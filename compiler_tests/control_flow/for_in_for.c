int f()
{
    int x;
    int y;
    int z;
    y=0;
    for(x=0; x<10; x=x+1){
        y=y-1;
        for( z=0; z<0; z--){
            y=z;
        }
    }
    return y;
}
