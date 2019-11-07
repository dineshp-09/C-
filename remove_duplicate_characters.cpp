/* 
Function to removes duplicate characters from a string
*/

# include <iostream>
# define NO_OF_CHARS 256

using namespace std;

// This function work in-place and fills null characters in the extra space left
char *RemoveDuplicate(char *str)
{
  int str_hash[NO_OF_CHARS] = {0};
  int i = 0, j = 0;
  char temp;

  // In place removal of duplicate characters
  while (*(str + i))
  {
    temp = *(str + i);
    if (str_hash[temp] == 0)
    {
        str_hash[temp] = 1;
        *(str + j) = *(str + i);
        j++;
    }
    i++;
  }

  // Removing duplicate characters after string
  *(str + j) = '\0';

  return str;
}

int main()
{
    char str[] = "HELLO_CPP";
    cout << RemoveDuplicate(str) << endl;
    return 0;
}

// Output: HELO_CP
