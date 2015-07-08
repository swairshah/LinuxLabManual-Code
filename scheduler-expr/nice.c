#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>

void primes(int n) {
    int i = 3, count, c;
    for ( count = 2 ; count <= n ; ) {
        for ( c = 2 ; c <= i - 1 ; c++ ) {
            if ( i%c == 0 )
            break;
        }
        if ( c == i ) {
            //printf("%d\n",i);
            count++;
        }
        i++;
    } 
}

int main() {
    int i;
    int my_pid = getpid();
    nice(15);
    for (i = 0; i < 100 ; i++) {
        int j = 10000;
        while(j > 0) {
            int k = 10000;
            while(k > 0) {
                k--;
            }
            j--;
        }
        primes(i);
    }
    printf("end!");
}
