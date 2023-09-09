int designerPdfViewer(int h_count, int* h, char* word) {
    int size_of_word , height_of_letter;
    int max_height = 0 ; 
    size_of_word = strlen(word);;
    for(int i = 0 ; i < size_of_word ; i++)
    {
        height_of_letter = h[word[i]-'a'];
        if(height_of_letter > max_height)
        {
            max_height = height_of_letter;
        }
    }
    return max_height*size_of_word;
}