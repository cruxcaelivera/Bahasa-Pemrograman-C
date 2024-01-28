Konstanta
Konstanta menyimpan nilai yang tidak dapat diubah dari penetapan awalnya.
#include <stdio.h>
int main() {
  const double PI = 3.14; //Nilai PI tidak dapat diubah selama eksekusi program, contoh penugasan lain PI = 3,141 menghasilkan error //Harus diassign dengan nilai saat dideklarasikan 
  double a;
  a = PI + 5; //  Sebagai contoh saja, jadi nilai variabel PI hanya dapat dibaca, tidak untuk diubah.
  printf("%lf %lf", PI, a);    
  return 0;
}

Cara lain untuk mendefinisikan sebuah konstanta adalah dengan direktif preprosesor #define.
#include <stdio.h>
#define PI 3.14 //Setiap kemunculan PI diganti dengan 3.14. //JANGAN letakkan karakter titik koma di akhir pernyataan #define
int main(){
    printf("%f", PI);
    return 0;
}
Perbedaan antara const dan #define adalah yang pertama menggunakan memori untuk penyimpanan dan yang kedua tidak.
