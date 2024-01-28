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

Saat Anda ingin tetap berada di loop, tetapi langsung beralih ke iterasi berikutnya, Anda menggunakan pernyataan continue.
Sebagai contoh:
#include <stdio.h>
int main()
{
    int num = 5;
    while (num > 0) {
      num--; //Iterasi pertama num = 4
      if (num == 3)
          continue; // continue = Keluar dari loop, while lanjut dieksekusi tanpa kondisi yang membuat loop berhenti
      //num--; num akan selalu = 3 
      printf("%d\n", num); //Iterasi pertama num = 4
      //num--; Jika num-- ada pada setelah printf, num akan selalu = 3 ketika mengeksekusi pernyataan continue (Looping tak terbatas dengan output tidak ada)
    }
}
Dalam kode di atas, jika num dikurangi setelah pernyataan continue, loop tak terbatas akan dibuat.
