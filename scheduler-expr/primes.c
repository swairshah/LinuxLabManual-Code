#include <stdio.h>

void primes(int n) {
    int i = 3, count, c;
    for ( count = 2 ; count <= n ; ) {
        for ( c = 2 ; c <= i - 1 ; c++ ) {
            if ( i%c == 0 )
            break;
        }
        if ( c == i ) {
            printf("%d\n",i);
            count++;
        }
        i++;
    } 
}
