int f()
{
    int w = 0;
    int x;
    int m;
    x=5678;
    {
        int y = 67;
        int x; 
        x=1234;
        w = w+1;
        return w;
    }
    return x;

}
