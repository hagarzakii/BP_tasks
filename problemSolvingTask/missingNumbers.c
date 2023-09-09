int* missingNumbers(int arr_count, int* arr, int brr_count, int* brr, int* result_count) {
    *result_count = 0;
    int *result = (int*)calloc(10000, sizeof(int));
    int *countArr = (int*)calloc(10000 , sizeof(int));
    int *countBrr = (int*)calloc(10000 , sizeof(int));
    
    for(int i = 0 ; i < arr_count ; i++)
    {
        countArr[arr[i]]++;
    }
    for(int j = 0 ; j < brr_count ; j++)
    {
        countBrr[brr[j]]++;
    }
    for(int k = 0 ; k < 10000 ; k++)
    {
        if(countBrr[k]>countArr[k])
        {
            result[(*result_count)]= k ;
            (*result_count) +=1;
        }
    }
    free(countArr);
    free(countBrr);
    return result;
}