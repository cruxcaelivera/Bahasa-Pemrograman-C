Library string.h
Pustaka string.h berisi banyak fungsi string.

Pernyataan #include <string.h> di bagian atas program Anda memberi Anda akses ke yang berikut:
strlen(str) Mengembalikan panjang string yang disimpan dalam str, tidak termasuk karakter NULL.
strcat(str1, str2) Menambahkan (menggabungkan) str2 ke akhir str1 dan mengembalikan pointer ke str1.
strcpy(str1, str2) Menyalin str2 ke str1. Fungsi ini berguna untuk memberi string nilai baru.
Program di bawah ini mendemonstrasikan fungsi string.h:
#include <stdio.h>
#include <string.h>

int main()
{
  char s1[ ] = "The grey fox";
  char s2[ ] = " jumped.";
    
  strcat(s1, s2); //s1 + s2 = The grey fox jumped.
  printf("%s\n", s1);
  printf("Length of s1 is %d\n", strlen(s1)); //The grey fox = 12 (Ditambah spasi) + (spasi)jumped. = 8. Panjang string = 20 (Tidak termasuk NULL)
  strcpy(s1, s2); //s1 = (spasi)jumped.
  printf("s1 is now %s \n", s1);

  return 0;
}

Fungsi string.h tambahan meliputi:
strncat(str1, str2, n) Menambahkan (menggabungkan) n karakter pertama dari str2 ke akhir str1 dan mengembalikan pointer ke str1.
strncpy(str1, str2, n) Menyalin n karakter pertama dari str2 ke str1.
strcmp(str1, str2) Mengembalikan 0 saat str1 sama dengan str2, kurang dari 0 saat str1 <str2, dan lebih besar dari 0 saat str1 > str2.
strncmp(str1, str2, n) Mengembalikan 0 jika n karakter pertama str1 sama dengan n karakter pertama str2, kurang dari 0 jika str1 < str2, dan lebih besar dari 0 jika str1 > str2.
strchr(str1, c) Mengembalikan pointer ke kemunculan pertama char c di str1, atau NULL jika karakter tidak ditemukan.
strrchr(str1, c) Mencari str1 secara terbalik dan mengembalikan pointer ke posisi char c di str1, atau NULL jika karakter tidak ditemukan.
strstr(str1, str2) Mengembalikan pointer ke kemunculan pertama str2 di str1, atau NULL jika str2 tidak ditemukan.

Type in a code to include the header file containing string functions:
#include <string.h>

Mengubah String menjadi Angka
Mengubah serangkaian karakter angka menjadi nilai numerik adalah tugas umum dalam pemrograman C dan sering digunakan untuk mencegah kesalahan run-time.
Membaca string lebih sedikit rawan kesalahan daripada mengharapkan nilai numerik, hanya untuk membuat pengguna secara tidak sengaja mengetikkan "o" daripada "0" (nol).
Pustaka stdio.h berisi fungsi-fungsi berikut untuk mengonversi string menjadi angka:
int atoi(str) Singkatan dari ASCII ke bilangan bulat. Mengubah str menjadi nilai int yang setara. 0 dikembalikan jika karakter pertama bukan angka atau tidak ada angka yang ditemui.
double atof(str) Singkatan dari ASCII untuk float. Mengubah str menjadi nilai ganda yang setara. 0.0 dikembalikan jika karakter pertama bukan angka atau tidak ada angka yang ditemukan.
long int atol(str) Singkatan dari ASCII ke long int. Mengubah str menjadi nilai integer panjang yang setara. 0 dikembalikan jika karakter pertama bukan angka atau tidak ada angka yang ditemui.
Program berikut mendemonstrasikan atoi.
#include <stdio.h>
int main()
{
  char input[10];
  int num;
    
  printf("Enter a number: ");
  gets(input);
  num = atoi(input);

  return 0;
}
Perhatikan, bahwa atoi() tidak memiliki penanganan kesalahan, dan disarankan untuk menggunakan strtol() jika Anda ingin memastikan bahwa penanganan kesalahan dilakukan dengan benar.
