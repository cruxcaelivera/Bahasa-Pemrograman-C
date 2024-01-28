Operator Pembagian (/ dan %)
Pembagian / operator bekerja secara berbeda tergantung pada tipe data operan. Ketika kedua operan adalah tipe data int, pembagian bilangan bulat, juga disebut pembagian terpotong, 
menghilangkan sisa apa pun untuk menghasilkan bilangan bulat.  (int berfungsi seperti modulo %)
Ketika salah satu atau kedua operan adalah bilangan real (float atau double), hasilnya adalah bilangan real.
Operator modulo % hanya mengembalikan sisa pembagian bilangan bulat. Pembagian modulus tidak dapat dilakukan pada float atau double. 

Prioritas Operator
Tanda + dan – memiliki prioritas yang sama, begitu pula *, /, dan %.
*, /, dan % dilakukan terlebih dahulu dengan urutan dari kiri ke kanan dan kemudian + dan -, juga dengan urutan dari kiri ke kanan.
Anda dapat mengubah urutan operasi dengan menggunakan tanda kurung ( ) untuk menunjukkan operasi mana yang akan dilakukan terlebih dahulu.

#include <stdio.h>
int main() {
   float harga = 6.50; //Koma harus menggunakan titik.
   int peningkatan = 2;
   float harga_baru;
   harga_baru = (float) harga + peningkatan; //Konversi tipe eksplisit
   printf("Harga baru adalah %4.2f",harga_baru); 
   /* Keluaran: Harga baru 8,50 */
   return 0;
}
