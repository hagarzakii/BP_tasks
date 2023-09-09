long flippingBits(long n) {
    for(long i = 0 ; i < 32 ; i++)
    {
        n = (n^(1L<<i));
    }
return n ;
}