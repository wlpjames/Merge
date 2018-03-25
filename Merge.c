#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void merge (int* a, int h)
{

    if (h < 2)
    {
        return;
    }
    int hh = h/2;
    if (h % 2 != 0)
    {
        hh++;
    }
    int left[hh];
    int right[h];
    for (int i = 0; i < hh; i++) //puts first half of string n into string left
    {
        left[i] = a[i];
    }
    merge(left, hh); //sorts left half


     //fings string right from string a
    for (int i = 0; i < h/2; i++)
    {
        right[i] = a[i + hh];
    }
    merge(right, h/2); // sorts left half
    int l = 0;
    int r = 0;

    for (int t = 0; t < h; t++)
    {
        if (r == h/2 || (l < hh &&((left[l] < right[r]) || (left[l] == right[r]))))
        {
            a[t] = left[l];
            if (l < hh)
            {
            l++;
            }
        }
        else /*if (l == h/2 || left[l] > right[r])*/
        {


            a[t] = right[r];
            if (r < h/2)
            {
            r++;
            }
        }
    }

       return;
}

int main (int argc,char *argv[])
{
    if (argc != 2)
    {
        printf ("input: ./merge unsorted_array");
        return 1;
    }
    int len = strlen(argv[1])/sizeof(char);
    int *p;
    int input[len];
    p = input;
    for (int i = 0; i < len; i++)
    {
        input[i] = argv[1][i] - '0';
    }
    merge (p, len);
    //prints result
    for (int i = 0; i < len; i++)
    {
        printf("%d", input[i]);
    }
    return 0;
}