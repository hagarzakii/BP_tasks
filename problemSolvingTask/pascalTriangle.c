int* subsetArray(int **arrOfarr ,int *subArr , int sizeOfSub){
    subArr[0] =  1 ;
    subArr[sizeOfSub-1] = 1;
    for(int j = 1 ; j < sizeOfSub-1 ; j++)
    {
        subArr[j] = arrOfarr[sizeOfSub - 2][j-1] + arrOfarr[sizeOfSub - 2][j] ;
    }
    return subArr;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int *subArr = (int*)malloc(30*sizeof(int));
    int **arrOfarr = (int**)malloc(30*sizeof(int*));
    *returnColumnSizes = (int*)malloc(30*sizeof(int));

    for (int i = 0; i < numRows; i++) {
        arrOfarr[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
    }

    subArr[0] = 1;
    arrOfarr[0][0] = 1;
    *returnSize = numRows ;

    for (int i = 1 ; i < numRows ; i++)
    {
        subArr =subsetArray(arrOfarr , subArr , i+1);
        
        for(int k = 0 ; k < i + 1 ; k ++)
        {
            arrOfarr[i][k] = subArr[k];
            
        }
    }
    free(subArr);
    return arrOfarr;
}