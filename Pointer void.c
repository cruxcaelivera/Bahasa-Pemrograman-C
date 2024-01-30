POINTER VOID
Struktur: void *ptr
Digunakan untuk merujuk ke jenis alamat apa pun di memori.
#include <stdio.h>
int main()
{
  int x = 33;
  float y = 12.4;
  char c = 'a';
  void *ptr; //Cara 1: Mendeklarasikan pointer dengan tipe data void.
    
  ptr = &x; //Cara 1 tidak menyertakan deklarasi pointer sekaligus dengan penunjuk ke alamat variabel apa.
  pri¬ntf("void ptr points to %d\n", *((int *)ptr)); //Yang dilakukan pertama adalah (int *) menunjuk ke tipe data. Kenapa? karena untuk menunjuk variabel dengan pointer, tipe datanya harus sama antara penunjuk dan yang ditunjuk, lalu *(ptr) sama seperti penunjuk ke elemen array.
  ptr = &y;
  printf("void ptr points to %f\n", *((float *)ptr));
  ptr = &c;
  printf("void ptr points to %c", *((char *)ptr));
}
//Tidak dapat melakukan aritmatika pointer dengan void pointer!!
