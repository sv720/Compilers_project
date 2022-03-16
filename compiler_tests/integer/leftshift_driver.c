
int f(int x, int y);

int main()
{
    return !(f(0b0010,2)==0b1000) + !(f(0b0010,5)==0b1000000);
}
