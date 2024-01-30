Function Pointers
Pointer Fungsi
Karena pointer dapat menunjuk ke suatu alamat di lokasi memori mana pun, mereka juga dapat menunjuk ke awal kode yang dapat dieksekusi.
Pointer ke fungsi, atau pointer fungsi, menunjuk ke kode yang dapat dieksekusi untuk suatu fungsi di memori. Pointer fungsi dapat disimpan dalam array atau diteruskan sebagai argumen ke fungsi lain.
Deklarasi pointer fungsi menggunakan * seperti yang Anda lakukan dengan pointer apa pun:
return_type (*func_name)(parameters) 
Tanda kurung di sekitar (*func_name) penting. Tanpa mereka, kompiler akan berpikir bahwa fungsi tersebut mengembalikan sebuah pointer.
Setelah mendeklarasikan pointer fungsi, Anda harus menetapkannya ke suatu fungsi. Program singkat berikut mendeklarasikan fungsi, mendeklarasikan pointer fungsi, menugaskan pointer fungsi ke fungsi, dan kemudian memanggil fungsi melalui pointer:
#include <stdio.h>
void say_hello(int num_times); /* function */

int main() {
  void (*funptr)(int);  /* function pointer */ //Sama seperti mendeklarasikan variabel pointer jika ditulis secara terpisah (Cara 1).  //Dalam kurung boleh tidak ditulis tipe datanya, penulisan tipe data untuk memperjelas nilai yang dikirimkan ke parameter.
  funptr = say_hello;  /* pointer assignment */
  funptr(3);  /* function call */ 
  //Fungsi yang dipanggil menunjuk ke alamat fungsi say_hello, lalu mengirimkan nilai integer, yaitu 3 ke fungsi say_hello.
 
  return 0;
}

void say_hello(int num_times) {
  //Deklarasi bayangan
  //int num_times = *funptr = &say_hello = int (nama variabel implisit) = 3 
  int k;
  for (k = 0; k < num_times; k++)
    printf("Hello\n");
}

Nama fungsi menunjuk ke awal kode yang dapat dieksekusi, sama seperti nama array menunjuk ke elemen pertamanya. Oleh karena itu, meskipun pernyataan seperti funptr = &say_hello dan (*funptr)(3) sudah benar, tidak perlu menyertakan operator alamat & dan operator tipuan * dalam penetapan fungsi dan pemanggilan fungsi.
Bentuk lain:
#include <stdio.h>
void say_hello(int num_times); /* function */

int main() {
  void (*funptr)(int);  /* function pointer */
  funptr = &say_hello;  /* pointer assignment */
  (*funptr)(3);  /* function call */
 
  return 0;
}

void say_hello(int num_times) {
  int k;
  for (k = 0; k < num_times; k++)
    printf("Hello\n");
}

Fill in the blanks to declare a function sum returning the sum of its arguments and declare a function pointer psum pointing to sum.
int sum(int a, int b) {
  return a+b;
}
int (*psum)(int, int) = sum;

Array Pointer Fungsi
Larik penunjuk fungsi dapat menggantikan switch atau pernyataan if untuk memilih tindakan, seperti dalam program berikut:
#include <stdio.h>

int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

int main() 
{
  int x, y, choice, result;
  int (*op[4])(int, int); //Deklarasi pointer fungsi 
  op[0] = add;
  op[1] = subtract;
  op[2] = multiply; 
  op[3] = divide;
  printf("Enter two integers: "); 
  scanf("%d%d", &x, &y); //Ex: 1 dan 2
  printf("Enter 0 to add, 1 to subtract, 2 to multiply, or 3 to divide: ");
  scanf("%d", &choice); //Ex: 2
  result = *op[choice](x, y); //Ex: op[2](1,2) = multiply; atau versi lain op[2](1,2) = &multiply; Kenapa tidak deklarasi sekaligus *op[2](1,2) = &multiply ? Karena program sudah mendeklarasikan variabel pointer.
  printf("%d", result);
    
  return 0;
}

int add(int x, int y) {
  //Ex:
  //int x = int num 1 = op[2](1,2) = &multiply = int x = 1 
  //int y = int num 2 = op[2](1,2) = &multiply = int y = 2
  return(x + y);
}

int subtract(int x, int y) {
  return(x - y);
}

int multiply(int x, int y) {
  //int x = *op[] = &multiply = 1
  //int y = *op[] = &multiply = 2
  return(x * y);
}

int divide(int x, int y) {
  if (y != 0)
    return (x / y);
  else
    return 0;
}
Pernyataan int (*op[4])(int, int); mendeklarasikan array pointer fungsi. Setiap elemen array harus memiliki parameter dan tipe pengembalian yang sama. Dalam hal ini, fungsi yang ditetapkan ke array memiliki dua parameter int dan mengembalikan sebuah int. Hasil pernyataan = op[pilihan](x, y); mengeksekusi fungsi yang sesuai berdasarkan pilihan pengguna. Bilangan bulat yang dimasukkan sebelumnya adalah argumen yang diteruskan ke fungsi.
