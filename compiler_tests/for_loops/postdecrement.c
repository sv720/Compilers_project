int f()
{
    int x;
    int y = 0;
    int z = 1;
    for(x=10; x>7; x--){
       y += x;
       z *= x;
    }
    return 2+y--;
}
