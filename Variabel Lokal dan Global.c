Lingkup Variabel
Ruang lingkup variabel mengacu pada visibilitas variabel dalam suatu program.
Variabel yang dideklarasikan dalam suatu fungsi bersifat lokal untuk blok kode tersebut dan tidak dapat dirujuk ke luar fungsi.
Variabel yang dideklarasikan di luar semua fungsi bersifat global untuk keseluruhan program.
Misalnya, konstanta yang dideklarasikan dengan #define di bagian atas program dapat dilihat oleh seluruh program.
Program berikut menggunakan variabel lokal dan global:
#include <stdio.h>
int global1 = 0;
int main() {
   int lokal1, lokal2;
   lokal1 = 5;
   lokal2 = 10;
   global1 = lokal1 + lokal2;
   printf("%d\n",global1); /* 15 */
   return 0;
}
Ketika argumen diteruskan ke parameter fungsi, parameter bertindak sebagai variabel lokal. Saat keluar dari fungsi, parameter dan variabel lokal apa pun dalam fungsi tersebut akan dihancurkan.
Gunakan variabel global dengan hati-hati. Mereka harus diinisialisasi sebelum digunakan untuk menghindari hasil yang tidak terduga. Dan karena mereka dapat diubah di mana saja dalam suatu program, variabel global dapat menyebabkan kesalahan yang sulit dideteksi.


Variabel Statis
Variabel statis memiliki cakupan lokal tetapi tidak dihancurkan saat fungsi keluar. Oleh karena itu, variabel statis mempertahankan nilainya seumur hidup program dan dapat diakses setiap kali fungsi dimasukkan kembali.
Variabel statis diinisialisasi saat dideklarasikan dan membutuhkan awalan statis.
Program berikut menggunakan variabel statis:
#include <stdio.h>
void say_hello();
int main() {
   int i;
   for (i = 0; i < 5; i++) {
      
    // Deklarasi bayangan
    // static int num_calls = 1;
    // printf("Hello number %d\n", num_calls);
    // num_calls++;
   }
   return 0;
}
void say_hello() {
   static int num_calls = 1;
   printf("Hello number %d\n", num_calls);
   num_calls++;
}
Keluaran programnya adalah:
Hello number 1
Hello number 2
Hello number 3
Hello number 4
Hello number 5
