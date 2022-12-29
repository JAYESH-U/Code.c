/*
Problem Statement 4: Given string, you need to find frequency of every character
present in the string and display character along with its count in a tabulated form.

Example 2:
Input:
Str= Belagavi
Output:
a : 2
b : 1
e : 1
g : 1
i : 1
l : 1
v : 1
Explanation:
    characters present in the input string are to be displayed in the output
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int val[26] = {0}, i;
    char s[100];

    printf("Enter the string: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z')      // checking wheather the charecter falls between 'a' to 'z'
            val[s[i] - 'a']++;               // incrementing the occourance value of i-th alphabet
        else if (s[i] >= 'A' && s[i] <= 'Z') // checking wheather the charecter falls between 'A' to 'Z'
            val[s[i] - 'A']++;               // incrementing the occourance value of i-th alphabet
    for (i = 0; i < 26; i++)
        if (val[i]) // check if occourance value is not 0
            printf("%c : %d\n", i + 'a', val[i]);
}

// void main()
// {
//     int n, arr[26]={0}, i, j,a=97,A=65;
//     char s[30];
//     printf("Str : ");
//     scanf("%s", &s);

//     n = strlen(s);  //length of a string

//     for(i=0;i<n;i++)
//         for(j=0;j<26;j++)   //checking 26 alphabets
//             if(s[i]==a+j || s[i]==A+j)  //if charecter matches with the string charecter
//                 arr[j]++;   //increment occourance value of j th alphabet

//     for(i=0;i<26;i++)
//         if(arr[i]!=0)   //if occourance of i th charecter not zero then print ocurrance value of that alphabet
//         {
//             //char c = a+i;   //increment alphabet charecter
//             printf("%c : %d\n", a+i, arr[i]);
//         }

// }