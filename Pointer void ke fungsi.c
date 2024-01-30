Fungsi Menggunakan Pointer void
Void pointer sering digunakan untuk deklarasi fungsi.
Sebagai contoh:
void *square (const void *); 
Menggunakan tipe pengembalian void * memungkinkan untuk semua jenis pengembalian. Demikian pula, parameter yang batal * menerima jenis argumen apa pun. Jika Anda ingin menggunakan data yang diteruskan oleh parameter tanpa mengubahnya, Anda mendeklarasikannya sebagai const.
Anda dapat mengabaikan nama parameter untuk lebih melindungi deklarasi dari penerapannya. Mendeklarasikan fungsi dengan cara ini memungkinkan definisi disesuaikan sesuai kebutuhan tanpa harus mengubah deklarasi.
Pertimbangkan program berikut:
#include <stdio.h>

void *square (const void *num);

int main() {
  //Secara implisit: Deklarasi void (*sq_int)(); seperti cara 1 mendeklarasikan variabel pointer.
  int x, sq_int;
  x = 6;
  sq_int = square(&x); 
  printf("%d squared is %d\n", x, sq_int); //Karena cara 1, makanya sq_int tidak menggunakan *sq_int

  return 0;
}

void *square (const void *num) {
  //Deklarasi bayangan
  //void *num = *sq_int = &x = 6 
  int result;
  result = (*(int *)num) * (*(int *)num); //Karena deklarasi bayangan masih berupa void, kita memberikan tipe data dulu berupa int agar dapat dioperasikan (Ingat: Tidak dapat melakukan aritmatika pointer dengan void pointer)
  return result; //Mengembalikan hasil berupa integer, sehingga pada printf, hasil sq_int dapat menggunakan format %d
}
Fungsi kuadrat ini telah ditulis untuk mengalikan int, itulah sebabnya penunjuk num void dilemparkan ke int. Jika implementasinya diubah untuk memungkinkan square() mengalikan float, maka hanya definisi yang perlu diubah tanpa harus membuat perubahan pada deklarasi.
