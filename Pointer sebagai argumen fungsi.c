POINTER SEBAGAI FUNGSI ARGUMEN
Pointer fungsi dengan meneruskannya sebagai argumen ke fungsi lain.
STRUKTUR: 
void qsort(void *base, size_t num, size_t width, 
    int (*compare)(const void *, const void *))
void *base Sebuah pointer kosong ke array.
size_t num Jumlah elemen dalam array.
size_t width Ukuran elemen.
int (*compare (const void *, const void *) Pointer fungsi yang memiliki dua argumen dan mengembalikan 0 ketika argumen memiliki nilai yang sama, <0 ketika arg1 datang sebelum arg2, dan >0 ketika arg1 datang setelah arg2.
Implementasi sebenarnya dari fungsi compare terserah Anda. Bahkan tidak perlu memiliki nama "compare". Anda memiliki kesempatan untuk menentukan pengurutan dari tinggi ke rendah atau rendah ke tinggi, atau jika array berisi elemen struktur, Anda dapat membandingkan nilai anggota.
#include <stdlib.h> untuk menggunakan fungsi qsort() (Quicksort ntuk mengurutkan array).
#include <stdio.h>
#include <stdlib.h>

int compare (const void *, const void *); 

int main() {
  int arr[5] = {52, 23, 56, 19, 4};
  int num, width, i;
  
  num = sizeof(arr)/sizeof(arr[0]); // num = 5. elemen dengan tipe data int = 4. sizeof(arr) = 20 dibagi alokasi memori array indeks ke-0 (1 elemen bertipe integer) = 4 maka 20/4 = 5
  width = sizeof(arr[0]); // 1 elemen tipe data int = 4
  qsort((void *)arr, num, width, compare); // memanggil fungsi qsort dengan parameter berupa array yang akan diurutkan secara ascending ((void *)arr = Sebuah pointer kosong ke array, num = 5, width = 4, memanggil fungsi compare untuk membandingkan dua elemen array bertipe integer)
  
  for (i = 0; i < 5; i++)
    printf("%d ", arr[ i ]); //52, 23, 56, 19, 4
    
  return 0;
}

int compare (const void *elem1, const void *elem2) {
  //Deklarasi bayangan
  //void *elem 1 = 
  //void *elem 2 = 
  if ((*(int *)elem1) == (*(int *)elem2))
    return 0;
  else if ((*(int *)elem1) < (*(int *)elem2))
    return -1; //Ketika diganti return 0, nilainya sama dengan return -1

  else
    return 1;
}
