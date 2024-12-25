#include <stdio.h>

int strlen(char *);
void replace(char *, char *, char *, char *);

int main() // Return type should be int for main
{
    char str[20] = "barqcd bastba";
    char pat[10] = "ba";
    char rep[10] = "BA";
    char fin[20];

    replace(str, pat, rep, fin);
    printf("%s\n", fin); // Added newline for better output formatting
    return 0; // Main should return 0
}

int strlen(char *s)
{
    int len;
    for(len = 0; s[len] != '\0'; len++);
    return len;
}

void replace(char *str, char *pat, char *rep, char *fin)
{
    int s = strlen(str), r = strlen(pat), k, e, q = 0, z; // Initialize q to 0

    for(k = 0; k < s;)
    {
        for(e = 0; e < r; e++) 
        {
            if(pat[e] != str[k + e])
                break;
        }

        if(e == r) 
        {
            printf("Pattern found at %d\n", k); // Added newline for better readability
            for(z = 0; z < strlen(rep); z++)
                fin[q++] = rep[z];
            k += r;
        } 
        else 
        {
            fin[q++] = str[k++];
        }
    }
    fin[q] = '\0';
}