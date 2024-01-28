Break and continue
Pernyataan break diperkenalkan untuk digunakan dalam pernyataan switch. Ini juga berguna untuk segera keluar dari loop.
Sebagai contoh, program berikut menggunakan break untuk keluar dari while loop:
#include <stdio.h>
int main()
{
    int num = 5;
    while (num > 0) {
    if (num == 3)
        break; //Keluar dari loop, while tidak dieksekusi lagi.
    printf("%d\n", num);
    num--;
    }
}
