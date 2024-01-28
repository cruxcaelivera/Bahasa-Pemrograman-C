Data Types
int: bilangan bulat, bilangan utuh.
float: floating point, angka dengan bagian pecahan.
double: nilai floating point presisi ganda.
char: karakter tunggal.
C memiliki operator sizeof bawaan yang memberikan persyaratan memori untuk tipe data tertentu.
#include <stdio.h>
int main() {
  printf("int: %ld \n", sizeof(int));
  printf("float: %ld \n", sizeof(float));
  printf("double: %ld \n", sizeof(double));
  printf("char: %ld \n", sizeof(char));
  return 0;
}

Jika soal meminta bilangan desimal, gunakan double scanf %lf dan printf %lf atau float scanf %f dan printf %f 
%.2lf, Jika ingin menghasilkan output 2 angka di belakang koma 
Input (0<n<2M) menggunakan long long int %lld
(-2m<n<2m) menggunakan int %d
(-128 to 127) menggunakan char %c
(0 to 255) menggunakan unsigned char %u 
