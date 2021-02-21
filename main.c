#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void check_spell(char* source, int max)
{
    char check_s[]={'c','i','r','c','l','e','('};
    char check_x1[max];
    char check_x2[max];
    char check_r[max];
    
    int is_equal = 0;
    int i;

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
    check_spell(source, max);
    out(source, max);
    counter_p_and_a(source, max);
}