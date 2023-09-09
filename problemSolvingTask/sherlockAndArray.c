char* balancedSums(int arr_count, int* arr) {
    static char result[4];
    int left_sum = 0 ;
    int total_sum = 0 ;
    for(int i = 0 ; i < arr_count ; i++)
        {
            total_sum += arr[i];
        } 
    for(int j = 0 ; j < arr_count ; j++)
    {
        if(left_sum == total_sum - left_sum - arr[j])
        {
            strcpy(result, "YES");
            return result;
        }
        left_sum +=arr[j];
    }
    strcpy(result, "NO");
    return result;
}