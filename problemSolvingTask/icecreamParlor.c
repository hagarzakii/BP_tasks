int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) {
    *result_count = 2;
    int *result = malloc(2 * sizeof(int));
    for(int i = 0 ; i < arr_count ; i++)
    {
        for(int j = i +1 ; j < arr_count ; j++)
        {
            if(arr[i] + arr[j] == m)
            {
                result[0]=i+1;
                result[1]=j+1;
            }
        }
    }
    return result;
}