#include <stdio.h>
#include "deposit.h"

int main()
{
    int s, t;
    printf("enter time to deposit: \n");
    scanf("%i", &t);
    printf("enter sum to deposit: \n");
    scanf("%i", &s);
    if (dataent(t, s) == 0)
        return 0;
    else {
        printf("result: ");
        printf("%.0f", profit(s, t));
        printf("\n");
    }
    printf("Doxod: ");
    printf("%0.2f", profit(s, t) - s);
}
       


