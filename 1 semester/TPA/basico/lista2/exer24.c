#include <stdio.h>

int main() {

int m,n,x;
n = 4000000000;
m = 300000000;
x = m + n;

// vai dar overflow, pois o valor x vai passar do valor máximo que um dado do tipo
// unsigned int pode ter
printf("%i", x);
  

    

    return 0;
}
  
