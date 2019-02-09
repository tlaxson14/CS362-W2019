#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    char charArr[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};

    /* Get random number */
    int randNum = rand() % 9;

    /* Return char at randNum index from charArr */
    return charArr[randNum];
}


char *inputString()
{
    // TODO: rewrite this function
    char stringArr[5] = {'r', 'e', 's', 'e', 't'};
    char* pString = (char *)malloc(sizeof(char) * strlen(stringArr));
    int i, randNum;

    for (i=0; i < sizeof(stringArr); i++) {
      /* Get random number */
      randNum = rand() % sizeof(stringArr);

      /* Assign char from string array to i-th index of char pointer */
      pString[i] = stringArr[randNum];
    }

    /* Assign last char to null terminator */
    pString[i] = '\0';

    return pString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;

  while (1) {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9) {
         printf("error ");
         exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
