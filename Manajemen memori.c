Memory Management
Working With Memory
Manajemen memori
Memahami memori adalah aspek penting dari pemrograman C. Saat Anda mendeklarasikan variabel menggunakan tipe data dasar, C secara otomatis mengalokasikan ruang untuk variabel di area memori yang disebut tumpukan.
Variabel int, misalnya, biasanya dialokasikan 4 byte saat dideklarasikan. Kami tahu ini dengan menggunakan operator sizeof:
#include <stdio.h>
int main() {
    int x; //Program mengalokasikan 4 byte ke int x
    printf("%d", sizeof(x)); /* output: 4 */
    return 0;
}

Sebagai contoh lain, sebuah array dengan ukuran tertentu dialokasikan blok memori yang berdekatan dengan setiap blok ukuran untuk satu elemen:
#include <stdio.h>
int main() {
    int arr[10];
    printf("%d", sizeof(arr)); /* output: 4*10 = 40 */ //Setiap indeksnya dialokasikan 10
    return 0;
}

Selama program Anda secara eksplisit mendeklarasikan tipe data dasar atau ukuran array, memori dikelola secara otomatis. Namun, Anda mungkin sudah ingin mengimplementasikan program di mana ukuran array belum diputuskan hingga runtime.
Alokasi memori dinamis adalah proses mengalokasikan dan membebaskan memori sesuai kebutuhan. Sekarang Anda dapat meminta saat runtime untuk jumlah elemen array dan kemudian membuat array dengan banyak elemen tersebut. Memori dinamis dikelola dengan pointer yang menunjuk ke blok memori yang baru dialokasikan di area yang disebut heap.
Selain manajemen memori otomatis menggunakan stack dan alokasi memori dinamis menggunakan heap, ada data yang dikelola secara statis di memori utama untuk variabel yang bertahan seumur hidup program.

Dynamic memory allocation is:
the process of allocating and freeing memory as needed.

Fungsi Manajemen Memori
Pustaka stdlib.h menyertakan fungsi manajemen memori.
Pernyataan #include <stdlib.h> di bagian atas program Anda memberi Anda akses ke yang berikut:
malloc(bytes) Mengembalikan pointer ke blok memori yang berdekatan yang berukuran byte.
calloc(num_items, item_size) Mengembalikan pointer ke blok memori yang berdekatan yang memiliki item num_items, masing-masing berukuran byte item_size. Biasanya digunakan untuk array, struktur, dan tipe data turunan lainnya. Memori yang dialokasikan diinisialisasi ke 0.
realloc(ptr, bytes) Mengubah ukuran memori yang ditunjuk oleh ptr ke ukuran byte. Memori yang baru dialokasikan tidak diinisialisasi.
free(ptr) Melepaskan blok memori yang ditunjuk oleh ptr.
Saat Anda tidak lagi membutuhkan blok memori yang dialokasikan, gunakan fungsi free() untuk membuat blok tersedia untuk dialokasikan lagi.
Include the header file which gives access to memory management functions.
#include <stdlib.h> 
    
Fungsi  
Fungsi malloc() mengalokasikan sejumlah byte yang berdekatan dalam memori.
Sebagai contoh:
#include <stdio.h>
#include <stdlib.h>
int main() {
  int *ptr; //Seperti deklarasi pointer cara 1
  ptr = malloc(10*sizeof(*ptr)); //Mengalokasikan memori sebanyak tipe datanya, yaitu 4*10 = 40 /* a block of 10 ints */ 
  if (ptr != NULL) { //ptr = 40
    *(ptr+2) = 50; //*ptr by default menunjuk indeks 0 dari array, menunjuk elemen ke-3, yaitu indeks 0 digeser sebesar 2, lalu diinisialisasi nilai = 50.
    /* assign 50 to third int */
  }
  printf("3rd elem equals to %d", *(ptr + 2));
  return 0;
}
malloc mengembalikan pointer ke memori yang dialokasikan.
Perhatikan bahwa sizeof diterapkan ke *ptr alih-alih int, membuat kode lebih kuat seandainya deklarasi *ptr diubah menjadi tipe data yang berbeda nanti.


Fungsi malloc
Memori yang dialokasikan bersebelahan dan dapat diperlakukan sebagai larik. Alih-alih menggunakan tanda kurung [ ] untuk merujuk ke elemen, aritmatika pointer digunakan untuk melintasi array. Anda disarankan untuk menggunakan + untuk merujuk ke elemen array. Menggunakan ++ atau += mengubah alamat yang disimpan oleh penunjuk.
Jika alokasi tidak berhasil, NULL dikembalikan. Karena itu, Anda harus menyertakan kode untuk memeriksa pointer NULL.
Array dua dimensi sederhana membutuhkan (baris*kolom)*sizeof(tipe data) ((rows*columns)*sizeof(datatype)) byte memori.

The allocated memory is:
Contiguous

Fungsi free
Fungsi free() adalah fungsi manajemen memori yang dipanggil untuk melepaskan memori. Dengan membebaskan memori, Anda menyediakan lebih banyak untuk digunakan nanti dalam program Anda.
Sebagai contoh:
#include <stdio.h>
#include <stdlib.h>

int main() {  
  int *ptr;
  ptr = malloc(10*sizeof(*ptr));  /* a block of 10 ints */
  if (ptr != NULL)
    *(ptr+2) = 50;  /* assign 50 to third int */
  printf("%d\n", *(ptr+2));  /* 50 */
  free(ptr);

  return 0;
}
 
Calloc and Realloc
Fungsi calloc 
Fungsi calloc() mengalokasikan memori berdasarkan ukuran item tertentu, seperti struct.
Program di bawah ini menggunakan calloc untuk mengalokasikan memori untuk suatu struktur dan malloc untuk mengalokasikan memori untuk string di dalam struktur:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int num;
  char *info; 
  //Deklarasi variabel pointer untuk alokasi memori malloc(sizeof(str))
  //Deklarasi variabel pointer untuk menunjuk dan menerima nilai string yang disimpan string char str[ ]
} record;

int main() {
  record *recs; //Deklarasi variabel pointer cara 1
  int num_recs = 2;
  int k;
  char str[ ] = "This is information"; //Ukuran string str adalah sebesar 20 (Gunakan printf("%d", sizeof(str))

  recs = calloc(num_recs, sizeof(record)); //Deklarasi variabel pointer cara 1
  //sizeof(record), mengalokasikan memori sebesar 
  //calloc(num_recs, sizeof(record)), Mengalokasikan memori sebesar 4 (Tidak peduli seberapa besar nilai inisialisasi karena hanya 1 elemen) ke setiap anggota struct record masing-masing 4 sehingga karena ada 2 anggota, maka mengalokasikan sebanyak 8 byte.
  //Setelah sudah mengalokasikan memori ke setiap anggota struct record, memori yang disimpan recs kembali = 0.
  if (recs != NULL) { //recs = 8
    for (k = 0; k < num_recs; k++) { //k < 2 (ada 2 perulangan)
      (recs+k)->num = k; 
      //(recs+0)->num = 0; Menginisialisasi nilai anggota struct int num = 0
      //(recs+1)->num = 1; Menginisialisasi nilai anggota struct int num = 1
      (recs+k)->info = malloc(sizeof(str)); 
      //Mengalokasikan memori untuk variabel pointer dalam struct, yaitu
      //(recs+0)->info = malloc(sizeof(str)) = 20;
      //(recs+1)->info = malloc(sizeof(str)) = 20;
      //malloc(sizeof(str)) = Mengalokasikan memori sebesar 20 menjadi nilai untuk anggota struct info (This is information + 1 = 20 (Spasi dan karakter NULL dihitung))
      strcpy((recs+k)->info, str); //(recs+k)->info = str = "This is information"
      //Ingat nama string berfungsi sebagai pointer.
    }
  }

  for (k = 0; k < num_recs; k++) {
    printf("%d\t%s\n", (recs+k)->num, (recs+k)->info);
    //0, 1
    //(recs+k)->info = str = "This is information"
  }
  return 0;
}
calloc mengalokasikan blok memori dalam blok memori yang berdekatan untuk array elemen struktur. Anda dapat menavigasi dari satu struktur ke struktur berikutnya dengan aritmatika penunjuk.
Setelah mengalokasikan ruang untuk struktur, memori harus dialokasikan untuk string di dalam struktur. Menggunakan penunjuk untuk anggota info memungkinkan string panjang apa pun disimpan.
Struktur yang dialokasikan secara dinamis adalah dasar dari daftar tertaut dan pohon biner serta struktur data lainnya.

Fungsi realloc
Fungsi realloc() memperluas blok saat ini untuk menyertakan memori tambahan.
Sebagai contoh:
#include <stdio.h>
#include <stdlib.h>
int main() {
  int *ptr; //Seperti deklarasi pointer cara 1
  ptr = malloc(10*sizeof(*ptr)); //Mengalokasikan memori sebanyak tipe datanya, yaitu 4*10 = 40 /* a block of 10 ints */ 
  if (ptr != NULL) { //ptr = 40
    *(ptr+2) = 50; //*ptr by default menunjuk indeks 0 dari array, menunjuk elemen ke-3, yaitu indeks 0 digeser sebesar 2, lalu diinisialisasi nilai = 50.
    /* assign 50 to third int */
  }
  ptr = realloc(ptr, 100*sizeof(*ptr)); /* 100 ints */
  //Mengubah/memperluas ukuran memori untuk ptr dari 40, menjadi sebesar 100*4 = 400
  *(ptr+30) = 75;
  //*ptr by default menunjuk indeks 0 dari array, menunjuk elemen ke-31, yaitu indeks 0 digeser sebesar 30, lalu diinisialisasi nilai = 75.
  printf("%d %d", *(ptr+2), *(ptr+30));
  return 0;
}
realloc meninggalkan konten asli dalam memori dan memperluas blok untuk memungkinkan lebih banyak penyimpanan.

What is the output of this code?
int *arr = malloc(sizeof(int));
*arr = 13;
arr = realloc(arr, 2*sizeof(int));
*(arr + 1) = *arr;
printf("%d", *(arr + 1));
13

Dynamic Strings & Arrays
 
Mengalokasikan Memori untuk String 
Saat mengalokasikan memori untuk penunjuk string, Anda mungkin ingin menggunakan panjang string daripada operator sizeof untuk menghitung byte.
Pertimbangkan program berikut:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str20[20];
  char *str = NULL;

  strcpy(str20, "12345"); //str20 = "12345"
  printf("str20 size: %d\n", sizeof(str20)); //Mengalokasikan memori untuk sebuah string, yaitu sebesar tipe_data * ukuran array/string = 1*20 = 20
  printf("str20 length: %d\n", strlen(str20)); //Mengembalikan panjang string yang disimpan di dalamnya tanpa karanter NULL str20, yaitu 5.
  str = malloc(strlen(str20)+1); /* make room for \0 , mengalokasikan memori tambahan sebesar 5 ditambah 1 untuk NULL*/ 
  strcpy(str, str20); //*str = str20 = "12345"
  //Pointer menunjuk ke nama_string dan nama_string tidak membutuhkan & karena sudah berfungsi sebagai pointer.
  printf("%s", str);

  return 0;
}

Pendekatan ini adalah manajemen memori yang lebih baik karena Anda tidak mengalokasikan lebih banyak ruang daripada yang diperlukan untuk penunjuk. Saat menggunakan strlen untuk menentukan jumlah byte yang diperlukan untuk sebuah string, pastikan untuk menyertakan satu byte ekstra untuk karakter NULL '\0'.
Char selalu satu byte, jadi tidak perlu mengalikan persyaratan memori dengan sizeof(char).

Array Dinamis
Banyak algoritma mengimplementasikan array dinamis karena ini memungkinkan jumlah elemen bertambah sesuai kebutuhan.
Karena elemen tidak dialokasikan sekaligus, array dinamis biasanya menggunakan struktur untuk melacak ukuran array saat ini, kapasitas saat ini, dan penunjuk ke elemen, seperti pada program berikut.
#include <stdio.h>
#include <stdlib.h> //Karena menggunakan fungsi alokasi memori

typedef struct {
  int *elements; //penunjuk ke elemen
  int size; //kapasitas saat ini
  int cap; //melacak ukuran array saat ini 
} dyn_array;

int main() {
  dyn_array arr; //Deklarasi variabel struct arr
  int i;

  /* initialize array */
  arr.size = 0; //Mengakses anggota struct size lalu diinisialisasi nilai = 0
  arr.elements = calloc(1, sizeof(*arr.elements)); //Mengalokasikan memori sebesar 1 untuk anggota struct elements berukuran sizeof(*arr.elements) = 4 (Sesuai tipe datanya int)
  arr.cap = 1;  //Mengakses anggota struct cap lalu diinisialisasi nilai = 1
  printf("%d", sizeof(*arr.elements));

  /* expand by 5 more elements */
  arr.elements = realloc(arr.elements, (5 + arr.cap)*sizeof(*arr.elements)); 
  //realloc(arr.elements, (5 + arr.cap)*sizeof(*arr.elements)) Mengubah ukuran memori arr.elements ke ukuran 
  //(5 + arr.cap)*sizeof(*arr.elements) = (5 + 1)*4 = 24.
  if (arr.elements != NULL) //24
    arr.cap += 5; /* increase capacity */ //arr.cap = 1 + 5 = 6

  /* add an element and increase size */  
  if (arr.size < arr.cap) { //0 < 6
    arr.elements[arr.size] = 50; /* add element to array */
    //arr.elements[0] = 50, inisialisasi 50 ke anggota struct elements pada indeks 0nya.
    //int *elements = elements[0] = 50
    arr.size++;
    //1;
  }
  else
    printf("Need to expand array.");

  /* display array elements */
  for (i = 0; i < arr.cap; i++)
    printf("Element %d: %d\n", i, arr.elements[ i ]);
    //Element 0~5: 
    //arr.elemets[0] = 50
    //arr.elemets[1] = 
    //arr.elemets[2] = 
    //arr.elemets[3] = 
    //arr.elemets[4] = 
    //arr.elemets[5] = 
    //element 1~5 tidak diinisialisasi nilainya sehingga outputnya berupa angka random.

  return 0;
}

To expand by more elements:
Menambahkan elemen ke array meningkatkan ukurannya:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *elements;
  int size;
  int cap;
} dyn_array;

int main() {
  dyn_array arr;
  int i;

  /* initialize array */
  arr.size = 0;
  arr.elements = calloc(1, sizeof(*arr.elements));
  arr.cap = 1;  /* room for 1 element */

  /* expand by 5 more elements */
  arr.elements = realloc(arr.elements, (5 + arr.cap)*sizeof(*arr.elements));
  if (arr.elements != NULL)
    arr.cap += 5; /* increase capacity */

  /* add an element and increase size */  
  if (arr.size < arr.cap) {
    arr.elements[arr.size] = 50; /* add element to array */
    arr.size++;
  }
  else
    printf("Need to expand array.");

  /* display array elements */
  for (i = 0; i < arr.cap; i++)
    printf("Element %d: %d\n", i, arr.elements[ i ]);

  return 0;
}
Seluruh program ditulis dalam main() untuk tujuan demonstrasi. Untuk mengimplementasikan larik dinamis dengan benar, subtugas harus dipecah menjadi fungsi seperti init_array(), increase_array(), add_element(), dan display_array(). Pengecekan kesalahan juga dilewati agar demo tetap singkat.
