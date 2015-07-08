#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int i;
    int my_pid = getpid();
    nice(-20);
    for (i = 0; i < 1000 ; i++) {
        int j = 10000;
        while(j > 0) {
            int k = 10000;
            while(k > 0) {
                k--;
            }
            j--;
        }
    }
}
