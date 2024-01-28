While Loop
Pernyataan while disebut struktur perulangan karena pernyataan tersebut mengeksekusi pernyataan secara berulang-ulang saat sebuah ekspresi benar, berulang-ulang. Ini mengambil bentuk:
#include <stdio.h>
int main() {
   int count = 1, hitung;
   while (count < 8) {
     printf("count = %d\n", ++hitung);
     count++;
   }
   return 0;
}

Infinite loop adalah loop yang berlanjut tanpa batas waktu karena kondisi loop tidak pernah bernilai false. Hal ini dapat menyebabkan kesalahan run-time error.


Do-while Loop
Perulangan do-while mengeksekusi pernyataan perulangan sebelum mengevaluasi ekspresi untuk menentukan apakah perulangan harus diulang.
Perulangan dalam do while dilaksanakan sekali meskipun kondisi salah
do{
  //Pernyataan
} while (kondisi);

#include <stdio.h>
int main() {
   int count = 1; //Ketika count = 8, tetap akan mengekseksui pernyataan sekali dengan output Jumlah = 8
   do
   {
    printf("Jumlah = %d\n", count);
    count++;
   } 
   while (count < 8);
   return 0;
}

The for Loop
The for Loop
Pernyataan for adalah struktur loop yang mengeksekusi pernyataan beberapa kali.
Ini mengambil bentuk:
for (nilai init; kondisi; kenaikan) {
   pernyataan;
}
Nilai init adalah penghitung yang diatur ke nilai awal. Bagian dari perulangan for ini hanya dilakukan sekali.
Kondisinya adalah ekspresi Boolean yang membandingkan penghitung dengan nilai sebelum setiap iterasi loop, menghentikan loop ketika false dikembalikan.
Kenaikan meningkatkan (atau menurunkan) penghitung dengan nilai yang ditetapkan.

Misalnya, program di bawah ini menampilkan 0 hingga 9:
#include <stdio.h>
int main()
{
    int i;
    int maks = 10;
    for (i = 0; i < maks; i++) //0. 0 < 10, masuk pernyataan .... 9. 9 < 10 masuk pernyataan 10. 10 < 10 (loop berhenti) 
    {
        printf("%d\n", i); //0. 0 newline, 1. 1 newline, 2. 2 newline, ... 9. 9 newline 
    }
}

The For Loop
Perulangan for dapat berisi banyak ekspresi yang dipisahkan dengan koma di setiap bagian.
Sebagai contoh:
for (x = 0, y = num; x < y; i++, y--) { //Nilai inisialisasi, kondisi, dan kenaikan dapat lebih dari 1 yang dipisahkan dengan koma.
   pernyataan;
}

Selain itu, Anda dapat melewati nilai init, kondisi, dan/atau peningkatan.
Sebagai contoh:
#include <stdio.h>
int main()
{
    int i=0;
    int maks = 10;
    for (; i < maks; i++) //Melewati nilai init, tapi sudah dideklarasikan di awal i = 0
    {
        printf("%d\n", i);
    }
}
Loop juga bisa bersarang.

Dalam contoh berikut, perulangan for bersarang digunakan untuk menampilkan tabel perkalian:
#include <stdio.h>
int main()
{
    int i, j;
    int tabel = 10;
    int maks = 12;
    for (i = 1; i <= tabel; i++)  
    {
        for (j = 0; j <= maks; j++) 
        {
            printf("%d x %d = %d\n", i, j, i*j);
        }
        printf("\n"); //Pindah ke baris selanjutnya
    }
}
