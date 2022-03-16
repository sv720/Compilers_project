
int f(int x, int y);

int main()
{
    return !(f(0b0100,2)==0b0001) + !(f(0b0100,4)==0b0000);
}
