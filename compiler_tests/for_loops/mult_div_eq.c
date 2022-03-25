int f()
{
    int x = 1;
    int y = 24;
    int z = 1;
    for(; x<4; x++){
       y /= x;
       z *= x;
    }
    return z*4/y;
}
