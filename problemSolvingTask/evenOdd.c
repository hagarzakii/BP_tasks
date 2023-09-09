int find(int x, int y, int *A) {
    if (x < y && A[x + 1] == 0)
        return 1;
    return A[x] % 2;
}

char** solve(int arr_count, int* arr, int queries_rows, int queries_columns, int** queries, int* result_count) {
    char** results = (char**)malloc(queries_rows * sizeof(char*));
    *result_count = queries_rows;

    for (int i = 0; i < queries_rows; i++) {
        int x = queries[i][0];
        int y = queries[i][1];
        int query_result = find(x-1, y-1, arr);
        results[i] = (char*)malloc(5 * sizeof(char));

        if (query_result == 0) {
            sprintf(results[i], "Even");
        } else {
            sprintf(results[i], "Odd");
        }
    }
    return results;
}