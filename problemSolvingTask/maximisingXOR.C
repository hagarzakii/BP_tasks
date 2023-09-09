int maximizingXor(int l, int r) {
int max = 0;
int xor_result;
for (int i = l ; i <= r ; i++)
{
    for(int j = i ; j <= r ; j++)
    {
        xor_result = (~i&j)|(~j&i);
        if(xor_result> max)
        {
            max = xor_result;
        }
    }
}
return max;
}