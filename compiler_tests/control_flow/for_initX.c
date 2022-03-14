int f()
{
    
    int y;
    int z;
    y=0;

    //C89 or C90 do not have definition and init in the for loop
    for(int x=0; x<10; x=x+1){
        y=y-1;
        for( z=0; z<0; z--){
            y=z;
        }
    }
    return y;
}
