#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void check_circle(char* source, int max)
{
    char check_s[]={'c','i','r','c','l','e','('};
    int is_equal = 0;
    int i,g,k,j;

    //check circle
    for(i = 0; i<7; ++i)
    {
        if(tolower(source[i]) != check_s[i])
        {
            is_equal = 1;
        }
    }
    if (is_equal != 0)
    {
    printf("^");
    printf("\nError: expected 'circle'");
    exit(0);
    }
    //check for smth after ')'
    for (i = 0; i < max; i++) 
    {
        if (source[i] == ')') 
        {
            if (source[i+1] == '\0'){
            }
            else{
                for (g = 0; g != (i+1); g++)
                {
                    printf(" ");
                }
                printf("^");
                printf("\nError: unexpected token");
                exit(0);
            }
        }   
    }
    //check x
    for (i = 0; i < max; i++) 
    {
        if (source[i] == '(') 
        {
            for (g = i; source[g + 1] != ' '; g++) 
            {
                if (((source[g+1]<='9') && (source[g+1]>='1')) || (source[g+1] =='.'))
                {
                }
                else{
                    for (k = 0; k != (g+1); k++)
                    {
                        printf(" ");
                    }
                    printf("^");
                    printf("\nError: expected '<double>'");
                    exit(0);
                }
            }
        }
    }
    //check y
    for (i = 0; i < max; i++) 
    {
        if (source[i] == ' ') 
        {   
            for (j = i; j < max; j++)
            {
                if (source[j] == ',')
                {
                    for (g = i; source[g + 1] != ','; g++) 
                    {
                        if (((source[g+1]<='9') && (source[g+1]>='1')) || (source[g+1] =='.')){
                        }
                        else
                        {
                            for (k = 0; k != (g+1); k++){
                                printf(" ");
                            }
                            printf("^");
                            printf("\nError: expected '<double>'");
                    
                            exit(0);
                        }
                    }        
                } 
            }       
        }
    }
    //check radius
    for (i = 0; i < max; i++) 
    {
        if ((source[i] == ',') && (source[i + 1] == ' ')) 
        {
            for (g = (i+1); source[g + 1] != ')'; g++) 
            {
                if (((source[g+1]<='9') && (source[g+1]>='1')) || (source[g+1] =='.')){

                }
                else{
                    for (k = 0; k != (g+1); k++){
                        printf(" ");
                    }
                    printf("^");
                    printf("\nError: expected '<double>'");
                    exit(0);
                }
            }
        }
    }

}

void out(char* source,int max)
{   
    for (int i = 0; i < max; i++){
        source[i]=tolower(source[i]);
    }
    printf("\n%s",source);
}

void counter_p_and_a(char* source, int max)
{
    int i, g;
    char rad[max];
    float perimeter, area, r;
    r = 0;

    for (i = 0; i < max; i++) 
    {
        if ((source[i] == ',') && (source[i + 1] == ' ')) 
        {
            for (g = i; source[g + 1] != ')'; g++) 
            {
                rad[g - i] = source[g + 1];
            }
        }
    }
    r = atof(rad);
    area = M_PI * r * r;
    perimeter = 2 * M_PI * r;
    printf("\nperimeter = %.4f\narea = %.4f\n", perimeter, area);
}

int main()
{
    int max = 50;
    char source[max];

    printf("Enter the shape in WKT-like format:\n");
    scanf("%[^\n]s",source);
    check_circle(source, max);
    out(source, max);
    counter_p_and_a(source, max);
}