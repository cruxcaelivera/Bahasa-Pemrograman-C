Array of Strings
Array dua dimensi dapat digunakan untuk menyimpan string terkait.
Pertimbangkan pernyataan berikut yang mendeklarasikan array dengan 3 elemen, masing-masing berisi 15 karakter:
char trip[3][15] = {
  "suitcase",
  "passport",
  "ticket"
};
Meskipun panjang string bervariasi, perlu untuk menyatakan ukuran yang cukup besar untuk menampung string terpanjang. Selain itu, bisa sangat rumit untuk mengakses elemen.
Mengacu pada trip[0] untuk "koper" rawan kesalahan. Sebaliknya, Anda harus menganggap elemen di [0][0] sebagai 's', elemen di [2][3] sebagai 'k', dan seterusnya.
Cara yang lebih mudah dan lebih intuitif untuk menangani kumpulan string terkait adalah dengan larik penunjuk, seperti dalam program berikut:

#include <stdio.h>
char *trip[ ] = {
  "suitcase",
  "passport",
  "ticket"
};

int main()
{
  printf("Please bring the following:\n");
  for (int i = 0; i < 3; i++) {
    printf("%s\n", trip[ i ]);
  }
}
Karena setiap elemen dapat bervariasi panjangnya, larik penunjuk string memiliki struktur yang lebih kasar dibandingkan dengan struktur kisi dua dimensi.
Dengan pendekatan ini, tidak ada batasan panjang string. Dan yang lebih penting, item dapat dirujuk dengan pointer ke karakter pertama dari setiap string.
Perlu diingat bahwa deklarasi seperti char *items[3]; hanya menyisakan ruang untuk tiga angka; string sebenarnya sedang direferensikan oleh pointer tersebut.

Fill in the blanks to declare an array of strings:
char *names[] = {
  "John",
  "Jill",
  "Janet"
};
