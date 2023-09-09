long sumXor(long n) {
int result = 0;
int zeros = 0;
int bit;
if(n == 0)
{
    return 1;
}
while(n != 0)
{
    bit = n & 1 ;
    if( bit == 0)
    {
        zeros ++;
    }
    n = n>>1;
}
return pow(2 , zeros);
}