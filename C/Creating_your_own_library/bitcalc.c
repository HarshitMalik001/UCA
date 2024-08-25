
int add(int a, int b)
{
        while(b > 0 )
        {
            unsigned int c = (a & b);
            a = (a ^ b);
            b = (c << 1);

        }
        return a;
}

int subtract(int a, int b)
{
    // 2's complement of b will be -b
    return add(a, ((~b) + 1));
}

int multiply(int a, int b)
{
    int c = 0;
    while(a > 0)
    {
        if(a & 1)
        {
            c += b;
        }

        b = b<<1;
        c = c>>1;
    }
    return c;
}

int divide(int a, int b)
{
        return a/b;
}
