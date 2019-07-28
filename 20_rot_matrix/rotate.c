#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(char matrix[10][10]){
int n = 10;
int x = (n/ 2);
int y = n - 1;
char k;
for (int i = 0; i < x; i++) {
  for (int j = i; j < y - i; j++) {
    k = *(*(matrix+i)+j);
    *(*(matrix+i)+j) = *(*(matrix+(y - j))+i);
    *(*(matrix+(y - j))+i) = *(*(matrix+(y - i))+(y - j));
    *(*(matrix+(y - i))+(y - j)) = *(*(matrix+j)+(y - i));
    *(*(matrix+j)+(y - i)) = k;
  }
 }
}
