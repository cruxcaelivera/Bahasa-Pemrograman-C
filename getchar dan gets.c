#include <stdio.h>
int main() {
  char a = getchar(), b = getchar(); //getchar() Mengembalikan nilai input karakter tunggal berikutnya. 
  char c;
  scanf("%c", &c);
  //Input disimpan dalam variabel a
  //Mendeklarasikan tipe data char dengan variabel baru, misal char b = getchar() dengan printf yang ditambahkan format %c dan b maka akan menghasilkan output R o (Jika inputnya Ronald)
  //Mendeklarasikan lebih dari 1 variabel dengan inisialisasi getchar dapat dipisah dengan koma dan setiap variabel diassign dengan getchar(). Jika tidak, maka keluarannya kosong. 
  //Spasi juga dihitung sebagai character
  printf("You entered: %c %c %c", a, b, c);
  return 0;
}

Fungsi gets() digunakan untuk membaca input sebagai urutan karakter yang terurut, juga disebut string. Sebuah string disimpan dalam array char.
#include <stdio.h>
int main() {
  char a[100]; //Menyimpan input dalam array 100 karakter.
  gets(a); 
  //scanf("%s", &a); Mengapa jika diberi scanf outputnya tidak menghasilkan berdasarkan scanf???
  printf("You entered: %s", a); //Output akan menghasilkan banyak karakter sebanyak-banyaknya asalkan inputnya masih <= 100 Karakter.
  //putchar(a); //Tidak dapat menggunakan putchar untuk keluaran input string 
  return 0;
}
