char * longestPalindrome(char * s){
    int n = strlen(s);
    int start = 0 ;
    int end = 1;
    int low, hi;
    for (int i = 0; i < n; i++) {
 
        low = i - 1;
        hi = i;

        while (low >= 0 && hi < n && s[low] == s[hi]) {
 
            if (hi - low + 1 > end) {
                start = low;
                end = hi - low + 1;
            }
            low--;
            hi++;
        }
 
        low = i - 1;
        hi = i + 1;

        while (low >= 0 && hi < n && s[low] == s[hi]) {
 
            if (hi - low + 1 > end) {
                start = low;
                end = hi - low + 1;
            }
            low--;
            hi++;
        }
    }
    char *substring = (char *)malloc(end + 1);
    for (int i = 0; i < end; i++) {
        substring[i] = s[start + i];
    }
    substring[end] = '\0'; 
    return substring;
}