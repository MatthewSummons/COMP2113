// CSort.c
// Sort Words in C
// Created by Shaheer Ziya

#include <stdio.h>
#include <string.h>

void swap(char arr1[], char arr2[])
// Swap two C-strings
{
  char temp[100];
  strcpy(temp, arr1);

  strcpy(arr1, arr2);
  strcpy(arr2, temp);
}

int main()
{
  // Declare a 2D char array to stores inputs words
  // Maximum 100 input words and each word maximum 10 chars
  char words[100][10];
  char temp[10];
  int n;

  // Obtain number of words to sort
  scanf("%d", &n);
  // Scan each of the provided words
  for (int i = 0; i < n; i++)
  {
    scanf("%s", words[i]);
  }

  // Add codes here to sort words
  //

  for (int i = 0; i < n; i++)
  // Iterate over all the strings
  {
    for (int j = 0; j < n-i-1; j++)
    // Iterate over the (n - i) remaining strings
    {
      if (strcmp(words[j], words[j+1]) > 0)
      {
        swap(words[j], words[j+1]);
      }
    }
  }

  //



  for (int i = 0; i < n; i++)
  {
    printf("%s\n", words[i]);
  }

  return 0;
}
