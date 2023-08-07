#include <stdio.h>
int main()
{
  char c = 32;
while (c < 127){
  printf("\n %d:%c", c, c);
  c++;
}
return 0;
}
