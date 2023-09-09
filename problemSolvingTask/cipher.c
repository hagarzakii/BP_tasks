void extraLongFactorials(int n) {
    int result[200] ;
    result[0] = 1;
    int resultSize = 1 ;
    for (int i = 2 ; i <= n ; i++)
    {
       int carry = 0;
       for(int j = 0 ; j < resultSize ; j++)
       {
           int product = result[j]*i + carry;
           result[j]= product % 10 ;
           carry = product/ 10 ; 
       }
       while(carry > 0)
       {
           result[resultSize] = carry % 10;
           carry /= 10;
           resultSize++;
       }
    }
    for(int k = resultSize-1 ; k>=0 ; k--)
    {
        printf("%d", result[k]);
    }       
}