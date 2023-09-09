int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    *result_count = 2;
    int *return_array = malloc(2 * sizeof(int));
    for(int j = 0 ; j<2 ; j++)
    {
        *(return_array+j)=0;
    }
    for(int i = 0 ; i<a_count ; i++)
    {
        if(a[i]>b[i])
        {
            return_array[0]+=1;
        }
        else if(a[i]<b[i])
        {
            return_array[1]+=1;
        }
    }
    return return_array;
}