#include <stdio.h>
int main() {
  char a = getchar(), b = getchar(); //Inisialisasi getchar terpisah
  printf("You entered: ");
  putchar(a); //Fungsi untuk menghasilkan keluaran satu karakter
  putchar(b); //Fungsi untuk menghasilkan keluaran karakter selanjutnya
  //Fungsi putchar tidak dapat menggunakan newline dalam ataupun di luar kurung.
  return 0;
}
