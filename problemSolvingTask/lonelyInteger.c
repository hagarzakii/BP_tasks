int lonelyinteger(int a_count, int* a) {
int count=0;
int found;
for (int i = 0 ; i < a_count ; i++)
{
    for(int j = 0 ; j < a_count ; j++)
    {
        if(a[i]==a[j])
        {
           count++; 
        }
    }
    if (count==1)
    {
        found=a[i];
    }
    else
    {
        count=0;
    }
}
return found;
}