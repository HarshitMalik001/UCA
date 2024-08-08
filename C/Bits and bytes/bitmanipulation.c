#include <stdio.h>
#include <assert.h>

int bitAnd(int x, int y)
{
        // return x&y using ~, |
        return ~(~x | ~y);
}

int conditional(int x, int y, int z)
{
        //return z if x = 0 else return y
        return ((((!(!x))<<31)>>31)&y | (((!x)<<31)>>31)&z );
}

int bang(int  x)
{
        //implement ! without using !

        return ((x | -x)>>31)+1;
}

void test_sample()
{

        assert(bitAnd(3,6)==(3&6));
        assert(bitAnd(321,451)==(321&451));
        assert(conditional(0,3,6)==6);
        assert(conditional(4,3,6)==3);
        assert(conditional(-7,3,6)==3);
        assert(bang(0)==1);
        assert(bang(-24)==0);
        assert(bang(423)==0);
}

int main()
{
        test_sample();
        return 0;
}
