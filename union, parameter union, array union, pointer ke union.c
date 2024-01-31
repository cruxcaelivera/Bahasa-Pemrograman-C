Unions
Union memungkinkan untuk menyimpan tipe data yang berbeda di lokasi memori yang sama.
Ini seperti struktur karena memiliki anggota. Namun, variabel gabungan menggunakan lokasi memori yang sama untuk semua anggotanya dan hanya satu anggota pada satu waktu yang dapat menempati lokasi memori tersebut.

Deklarasi gabungan menggunakan kata kunci gabungan, tag gabungan, dan kurung kurawal {} dengan daftar anggota.

Anggota union dapat berupa tipe data apa pun, termasuk tipe dasar, string, array, pointer, dan struktur.

Sebagai contoh:
#include <stdio.h>

union val {
    int int_num;
    float fl_num;
    char str[20]; 
};

int main() {
    union val test;
    test.int_num = 42;
    printf("%d", test.int_num);
    return 0;
}

Setelah mendeklarasikan union, Anda dapat mendeklarasikan variabel union. Anda bahkan dapat menugaskan satu union ke union lainnya dengan jenis yang sama:
#include <stdio.h>

union val {
    int int_num;
    float fl_num;
    char str[20]; 
};

int main() {
    union val u1;
    union val u2;
    u1.int_num = 42;
    u2 = u1; //Menugaskan satu union ke union lainnya
    printf("%d", u2.int_num);
    return 0;
}

union digunakan untuk manajemen memori. Tipe data anggota terbesar digunakan untuk menentukan ukuran memori yang akan dibagikan dan kemudian semua anggota menggunakan satu lokasi ini. Proses ini juga membantu membatasi fragmentasi memori. Manajemen memori dibahas dalam pelajaran selanjutnya.

Mengakses Anggota Union
Anda mengakses anggota variabel union dengan menggunakan . dot operator antara nama variabel dan nama anggota.
Saat penugasan dilakukan, lokasi memori gabungan akan digunakan untuk anggota tersebut hingga penugasan anggota lainnya dilakukan.
Mencoba mengakses anggota yang tidak menempati lokasi memori memberikan hasil yang tidak terduga.
Program berikut menunjukkan akses ke anggota union:
#include <stdio.h>
#include <string.h>

union val {
  int int_num;
  float fl_num;
  char str[20]; 
};
int main() {  
  union val test;

  test.int_num = 123;
  test.fl_num = 98.76;
  strcpy(test.str, "hello");

  printf("%d\n", test.int_num);
  printf("%f\n", test.fl_num);
  printf("%s\n", test.str); //Hanya satu anggota yang dapat menempati lokasi memori tersebut
  return 0;
}

Tugas terakhir mengesampingkan tugas sebelumnya, itulah sebabnya str menyimpan nilai dan mengakses int_num dan fl_num tidak ada artinya.
  
union val test;
test.int_num = 123;
test.fl_num = 98.76;

Structures with Unions
Union sering digunakan dalam struktur karena struktur dapat memiliki anggota untuk melacak anggota union mana yang menyimpan nilai.
Misalnya, dalam program berikut, sebuah struct kendaraan menggunakan nomor identifikasi kendaraan (VIN) atau id yang ditetapkan, tetapi tidak keduanya:
#include <stdio.h>
#include <string.h>

typedef struct { //struct dapat memiliki anggota union
  char make[20];
  int model_year;
  int id_type; /* 0 for id_num, 1 for VIN */
  union { //Union dalam struct
    int id_num; //Struct kendaraan menggunakan nomor identifikasi kendaraan (VIN) atau id yang ditetapkan, tetapi tidak keduanya:
    char VIN[20]; 
  } id;
} vehicle;

int main() {  
  vehicle car1;
  strcpy(car1.make, "Ford"); //char make[20] = "Ford"
  car1.model_year = 2017; //int model_year = 2017
  car1.id_type = 0; //int id_type = 0
  car1.id.id_num = 123098; //Mengakses anggota int id_num dari anggota union id, int id_num = 123098 (Disini yang digunakan salah satunya, yaitu id_num)
  
  printf("Car %s, %d", car1.make, car1.model_year);

  return 0;
}

Perhatikan bahwa union dideklarasikan di dalam struktur. Saat melakukan ini, nama union diperlukan di akhir deklarasi.
Union dengan tag union dapat dideklarasikan di luar struktur, tetapi dengan penggunaan khusus seperti itu, union di dalam struct memberikan kode yang lebih mudah dipahami.
Perhatikan juga operator titik digunakan dua kali untuk mengakses anggota gabungan dari anggota struct.
id_type melacak anggota union mana yang menyimpan nilai. Pernyataan berikut menampilkan data car1, menggunakan id_type untuk menentukan anggota union mana yang akan dibaca:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h> //Menggunakan fungsi seperti sqrt()
#include <ctype.h>
typedef struct {
  char make[20];
  int model_year;
  int id_type; /* 0 for id_num, 1 for VIN */
  union {
    int id_num;
    char VIN[20]; 
  } id;
} vehicle;

int main() {  
  vehicle car1;
  int n; 
  scanf("%d", &n);
  car1.id_type = n;
  strcpy(car1.make, "Ford"); //char make[20] = "2017"
  car1.model_year = 2017;
  car1.id.id_num = 123098;
  car1.id.VIN[20] = "Ronald";
  printf("Make: %s\n", car1.make);
  printf("Model Year: %d\n", car1.model_year);
  if (car1.id_type == 0) //id_type melacak anggota union mana yang menyimpan nilai untuk menentukan anggota union mana yang akan dibaca.
    printf("ID: %d\n", car1.id.id_num);
  else
    printf("ID: %s\n", car1.id.VIN);

  return 0;
}
Union juga dapat berisi struktur.

Working With Unions
Pointers to Unions
Penunjuk ke union menunjuk ke lokasi memori yang dialokasikan ke union.
Pointer union dideklarasikan dengan menggunakan kata kunci union dan tag union bersama dengan * dan nama penunjuk.
Misalnya, perhatikan pernyataan berikut:
#include <stdio.h>
#include <string.h>

union val {
  int int_num;
  float fl_num;
  char str[20]; 
};

int main() {  
  union val info;
  union val *ptr = NULL; //Deklarasi pointer: Pointer ke Union. Deklarasi pointer cara 1
  ptr = &info; //Variabel pointer menyimpan alamat info yang berupa union. Deklarasi dapat menggunakan cara 2, union val *ptr = &info;
  ptr->int_num = 10; //Mengakses nilai anggota union yang lebih spesifik, yaitu "int_num" dan diinisialisasi = 10.
  printf("info.int_num is %d", info.int_num);
  
  return 0;
}
Saat Anda ingin mengakses anggota union melalui penunjuk, operator -> diperlukan.
(*ptr).int_num sama dengan ptr->int_num.

Union sebagai Parameter Fungsi
Suatu fungsi dapat memiliki parameter gabungan yang menerima argumen berdasarkan nilai ketika hanya salinan variabel gabungan yang diperlukan.

Agar fungsi dapat mengubah nilai aktual di lokasi memori gabungan, diperlukan parameter penunjuk.

Sebagai contoh:
#include <stdio.h>
#include <string.h>

union id {
  int id_num;
  char name[20]; 
};

void set_id (union id *item); //Mengakses semua nilai anggota union id dengan variabel baru item
void show_id (union id item); //Cara yang sama mengakses semua nilai anggota union id dengan variabel baru item

int main() {  
  union id item;
  
  set_id(&item);  
  show_id(item);

  return 0;
}

void set_id(union id *item) {
  // Deklarasi bayangan
  // union id *item = &item;
  // Mengakses seluruh anggota union
  // int id_num;
  // char name[20]; 
    item->id_num = 42; //Inisialisasi anggota union id_num = 42
}

void show_id(union id item) {
  // Deklarasi bayangan
  // union id item = item;
  // int id_num = 42;
  // char name[20]; 
    printf("ID is %d", item.id_num);
}

Array Union
Array dapat menyimpan elemen dari tipe data apa pun, termasuk union.
Dengan union, penting untuk diingat bahwa hanya satu anggota union dapat menyimpan data untuk setiap elemen array.
Setelah mendeklarasikan array union, sebuah elemen dapat diakses dengan nomor indeks. Operator titik kemudian digunakan untuk mengakses anggota union, seperti dalam program:
#include <stdio.h>

union val {
  int int_num;
  float fl_num;
  char str[20]; 
};

int main() {  
  union val nums[10]; //Mendeklarasikan array dengan tipe data union
  int k;
  
  /* create an array of ints */
  for (k = 0; k < 10; k++) {
    nums[k].int_num = k; 
  }
  //k = 0, nums[0].int_num = 0; //nums = mengakses anggota union val pada nums, [0] = diinisialisasi nilai indeks 0, yaitu = 0, mengakses anggota union int_num = 0;
  //dst.

  /* display array values */
  for (k = 0; k < 10; k++) {
    printf("%d  ", nums[k].int_num); //Menghasilkan output
  }
  
  return 0;
}

Array adalah struktur data yang menyimpan nilai koleksi yang semuanya bertipe sama. Array union memungkinkan menyimpan nilai dari berbagai jenis.
Sebagai contoh:
#include <stdio.h>

union type {
  int i_val;
  float f_val;
  char ch_val;
};

int main() {
  union type arr[3]; // = {42, 3.14, 'x'};
  arr[0].i_val = 42; //Mengakses anggota union type,  mengakses anggota union i_val = 42, [0] = mengisi nilai indeks 0;
  arr[1].f_val = 3.14; //Mengakses anggota union type,  mengakses anggota union f_val = 3.14, [1] = mengisi nilai indeks 1;
  arr[2].ch_val = 'x'; //Mengakses anggota union type,  mengakses anggota union ch_val = 'x', [2] = mengisi nilai indeks 2;
  printf("1st element is %d, 2nd is %.2f, and the 3rd is %c", arr[0].i_val, arr[1].f_val, arr[2].ch_val);
  
  return 0;
}
