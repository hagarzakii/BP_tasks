char* timeInWords(int h, int m) {
    char* s = malloc(100 * sizeof(char));
    
    char *hours[] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen" , "fourteen" , "quarter" , "sixteen" , "siventeen" , "eighteen" , "nineteen"};
    char *expressions[] = {"minutes" , "past" , "to"};
    char *tens[]={"twenty" , "half"} ;
    
    if(m == 00)
    {
        strcpy(s ,hours[h-1]);
        strcat(s , " ");
        strcat(s , "o' clock");
        // s = hours[h-1] + "o' clock";
    }
    else if(m == 01)
    {
        strcpy(s , hours[0]);
        strcat(s , " ");
        strcat(s , "minute");
        strcat(s , " ");
        strcat(s , expressions[1]);
        strcat(s , " ");
        strcat(s , hours[h-1]);
        // s = hours[0] + "minute" + expressions[2] + hours[h-1];
    }
    else if(m > 01 && m < 20)
    {
        if(m == 15)
        {
        strcpy(s , hours[m-1]);
        strcat(s , " ");
        strcat(s , expressions[1]);
        strcat(s , " ");
        strcat(s , hours[h-1]);
            // s = hours[m-1] + expressions[1] + hours[h-1];
        }
        else
        {
        strcpy(s , hours[m-1]);
        strcat(s , " ");
        strcat(s , expressions[0]);
        strcat(s , " ");
        strcat(s , expressions[1]);
        strcat(s , " ");
        strcat(s , hours[h-1]);
            // s = hours[m-1] + expressions[0] + expressions[1] + hours[h-1];
        }
    }
    else if ( m  >= 20 && m <= 30 )
        {
            if (m == 30)
            {
                strcpy(s , tens[1]);
                strcat(s , " ");
                strcat(s , expressions[1]);
                strcat(s , " ");
                strcat(s , hours[h-1]);
                // s = tens[1] + expressions[1] + hours[h-1];   
            }
            else if ( m == 20)
            {
                strcpy(s , tens[0]);
                strcat(s , " ");
                strcat(s , expressions[0]);
                strcat(s , " ");
                strcat(s , expressions[1]);
                strcat(s , " ");
                strcat(s , hours[h-1]);
                // s = tens[0] + expressions[0] + expressions[1] + hours[h-1];
            }
            else
            {
                int ten ;
                ten = m % 10;
                strcpy(s , tens[0]);
                strcat(s , " ");
                strcat(s , hours[ten-1]);
                strcat(s , " ");
                strcat(s , expressions[0]);
                strcat(s , " ");
                strcat(s , expressions[1]);
                strcat(s , " ");
                strcat(s , hours[h-1]);
                // s = tens[0] + hours[ten-1] + expressions[0] + expressions[1] + hours[h-1];
            }
        }
    else if ( m > 30 )
    {
        int reminder = 60 - m ;
        int ten = reminder % 10;
        if ( reminder < 20)
        {
            if(reminder == 15)
            {
                strcpy(s , hours[reminder - 1]);
                strcat(s , " ");
                strcat(s , expressions[2]);
                strcat(s , " ");
                strcat(s , hours[h]);
                // s = hours[reminder - 1] + expressions[2] + hours[h - 1];
            }
            else
            {
                strcpy(s , hours[reminder - 1]);
                strcat(s , " ");
                strcat(s , expressions[0]);
                strcat(s , " ");
                strcat(s , expressions[2]);
                strcat(s , " ");
                strcat(s , hours[h]);
                // s = hours[reminder-1] + expressions[0] + expressions[2] + hours[h-1];
            }    
        }
        else
        {
           if(reminder == 20)
           {
                strcpy(s , tens[0]);
                strcat(s , " ");
                strcat(s , expressions[0]);
                strcat(s , " ");
                strcat(s , expressions[2]);
                strcat(s , " ");
                strcat(s , hours[h]);
            // s = tens[0] + expressions[0] + expressions[2] + hours[h-1];
           }
           else
           {
                strcpy(s , tens[0]);
                strcat(s , " ");
                strcat(s , hours[ten -1]);
                strcat(s , " ");
                strcat(s , expressions[0]);
                strcat(s , " ");
                strcat(s , expressions[2]);
                strcat(s , " ");
                strcat(s , hours[h]);
            // s = tens[0] + hours[reminder -1] + expressions[2] + hours[h-1];
           } 
        }
    }
    
    return s;
}