#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

enum Errors {
    UnExpToken = 1,
    ExpBracket,
    ExpDouble,
    ExpCircle
};

void print_error(int i, int err){
    for (int g = 0; g != (i+1); g++){
        printf(" ");
    }
    printf("^");
    if (err == 1){
        printf("\nError: unexpected token");
    }
    if (err == 2){
        printf("\nError: expected ')'");
    }
    if (err == 3){
        printf("\nError: expected '<double>'");
    }
    if (err == 4){
        printf("\nError: expected 'circle'");
    }
}

void check_circle(char* source, int max)
{
    char check_s[]={'c','i','r','c','l','e','('};
    int i,g,j;

    //check circle
    for(i = 0; i<7; ++i)
    {
        if(tolower(source[i]) != check_s[i])
        {
            print_error(-1, ExpCircle);
            exit(0);
        }
    }

    //check for smth after ')'
    for (i = 0; i < max; i++) 
    {
        if (source[i] == ')') 
        {   
            if (source[i+1] == '\0'){
            }
            else{
            print_error(i, UnExpToken);
            exit(0);
            }
        }   
    }

    //check ')'
    for (i = 0; i < max; i++) 
    {
        if (source[i] == '\0') 
        {
            if (source[i-1] == ')')
            {
                break;
            }
            else{
                print_error(i-2, ExpBracket);
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
                if (((source[g+1]<='9') && (source[g+1]>='0')) || (source[g+1] =='.')){
                }
                else{
                    print_error(g, ExpDouble);
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
                        if (((source[g+1]<='9') && (source[g+1]>='0')) || (source[g+1] =='.')){
                        }
                        else
                        {
                            print_error(g, ExpDouble);
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
                if (((source[g+1]<='9') && (source[g+1]>='0')) || (source[g+1] =='.')){
                }
                else{
                    print_error(g, ExpDouble);
                    exit(0);
                }
            }
        }
    }
}

void out(char* source, int max)
{   
    for (int i = 0; i < max; i++)
    {
        source[i]=tolower(source[i]);
    }
    printf("\n%s",source);
}

void p_and_a_circle(char* source, int max)
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
    printf("\n perimeter = %.4f\n area = %.4f\n", perimeter, area);
}

int main()
{
    int max = 50;
    char source[max];

    printf("Enter the shape in WKT-like format:\n");
    scanf("%[^\n]s",source);
    check_circle(source, max);
    out(source, max);
    p_and_a_circle(source, max);
}