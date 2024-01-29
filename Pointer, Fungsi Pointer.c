Pointers
Menggunakan Memori
C dirancang untuk menjadi bahasa tingkat rendah yang dapat dengan mudah mengakses lokasi memori dan melakukan operasi yang berhubungan dengan memori.
Misalnya, fungsi scanf() menempatkan nilai yang dimasukkan oleh pengguna di lokasi, atau alamat, dari variabel. Ini dilakukan dengan menggunakan simbol &.
Misalnya:
#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%d", num);
	return 0;
}
&num adalah alamat dari variabel num.
Alamat memori diberikan sebagai angka heksadesimal. Hexadecimal, atau hex, adalah sistem bilangan berbasis 16 yang menggunakan angka 0 sampai 9 dan huruf A sampai F (16 karakter) untuk mewakili sekelompok empat digit biner yang dapat memiliki nilai dari 0 sampai 15.
Jauh lebih mudah untuk membaca angka hex yang panjangnya 8 karakter untuk memori 32 bit daripada mencoba menguraikan 32 1 dan 0 dalam biner.
Program berikut menampilkan alamat memori untuk variabel i dan k:
#include <stdio.h>

void test(int k);

int main() {
    int i = 0;
    
    printf("The address of i is %x\n", &i);
    test(i);
    printf("The address of i is %x\n", &i);
    test(i);

    return 0;
}

void test(int k) {
    printf("The address of k is %x\n", &k);
} 
Dalam pernyataan printf, %x adalah penentu format hex.
Keluaran program bervariasi dari satu proses ke proses lainnya, tetapi terlihat mirip dengan:
The address of i is 846dd754
The address of k is 846dd758
The address of i is 846dd754
The address of k is 846dd758
Alamat variabel tetap sama sejak dideklarasikan hingga akhir ruang lingkupnya.

Apa itu Pointer?
Pointer sangat penting dalam pemrograman C karena memungkinkan Anda bekerja dengan mudah dengan lokasi memori.
Mereka sangat mendasar untuk array, string, dan struktur data serta algoritme lainnya.
Pointer adalah variabel yang berisi alamat dari variabel lain. Dengan kata lain, itu "menunjuk" ke lokasi yang ditetapkan ke variabel dan secara tidak langsung dapat mengakses variabel tersebut.
Pointer dideklarasikan menggunakan simbol * dan berbentuk:
pointer_type *identifier
pointer_type adalah tipe data yang akan ditunjuk oleh pointer. Tipe data penunjuk yang sebenarnya adalah bilangan heksadesimal, tetapi saat mendeklarasikan penunjuk, Anda harus menunjukkan jenis data yang akan ditunjuknya.
dAsterisk * mendeklarasikan sebuah pointer dan akan muncul di sebelah identifier yang digunakan untuk variabel pointer.
Program berikut mendemonstrasikan variabel, pointer, dan alamat:
#include <stdio.h>

int main() {
    int j = 63;
    int *p = NULL; //Deklarasi pointer
    p = j; 
    
    printf("The address of j is %x\n", &j);
    printf("p contains address %x\n", p);
    printf("The value of j is %d\n", j);
    printf("p is pointing to the value %d\n", *p);
}
Ada beberapa hal yang perlu diperhatikan dalam program ini:
• Pointer harus diinisialisasi ke NULL sampai diberi lokasi yang valid.
• Pointer dapat diberikan alamat variabel menggunakan ampersand & tanda.
• Untuk melihat apa yang ditunjuk pointer, gunakan * lagi, seperti pada *p. Dalam hal ini * disebut operator tipuan atau dereferensi. Proses ini disebut dereferensi.
Output program mirip dengan:
The address of j is ff3652cc
p contains address ff3652cc
The value of j is 63
p is pointing to the value 63 

Pointer ke Pointer
Beberapa algoritma menggunakan pointer ke pointer. Jenis deklarasi variabel ini menggunakan **, dan dapat diberi alamat penunjuk lain, seperti pada:
int x = 12;
int *p = NULL //Deklarasi pointer 
int **ptr = NULL; //Deklarasi pointer ke pointer
p = &x; //Deklarasi variabel pointer menyimpan alamat variabel lain
ptr = &p; //Deklarasi variabel pointer menyimpan alamat variabel pointer

Pointer dalam Ekspresi
Pointer dapat digunakan dalam ekspresi seperti halnya variabel apa pun. Operator aritmatika dapat diterapkan pada apa pun yang ditunjuk pointer.
Sebagai contoh:
#include <stdio.h>

int main() {
    int x = 5;
    int y;
    int *p = NULL; //Deklarasi pointer
    p = &x; //Deklarasi variabel pointer menyimpan alamat variabel lain
    // int *p = &x; 
    
    y = *p + 2; /* y is assigned 7 */ //*p = &x (*p menunjuk alamat variabel x, dan mengakses nilai di dalamnya, yaitu 5)
    y += *p;     /* y is assigned 12 */
    *p = y;       /* x is assigned 12 */
    (*p)++;      /* x is incremented to 13 */

    printf("p is pointing to the value %d\n", *p); 
}
printf("p is pointing to the value %d\n", *p); 
Perhatikan bahwa tanda kurung diperlukan untuk operator ++ untuk menaikkan nilai yang ditunjuk. Hal yang sama berlaku saat menggunakan -- operator.
 
More On Pointers
Pointer dan Array
Pointer sangat berguna dengan array. Deklarasi array mencadangkan blok alamat memori yang berdekatan untuk elemen-elemennya. Dengan pointer, kita bisa menunjuk ke elemen pertama dan kemudian menggunakan alamat aritmatika untuk melintasi array:
  + digunakan untuk bergerak maju ke lokasi memori
  - digunakan untuk bergerak mundur ke lokasi memori
Pertimbangkan program berikut:
#include <stdio.h>

int main() {
    int a[5] = {22, 33, 44, 55, 66};
    int *ptr = NULL;
    int i;
    
    ptr = &a[1];  
    for (i = 0; i < 3; i++) {
        printf("%d ", *(ptr + i));
    }
}
Keluaran programnya adalah: 22 33 44
Konsep penting dengan array adalah bahwa nama array bertindak sebagai pointer ke elemen pertama dari array. Oleh karena itu, pernyataan ptr = a dapat dianggap sebagai ptr = &a[0].
Pertimbangkan pernyataan berikut, yang mencetak elemen pertama dari array: printf("%d ", *a);

Alamat Lainnya Aritmatika
Aritmatika alamat juga dapat dianggap sebagai aritmatika pointer karena operasinya melibatkan pointer.
Selain menggunakan + dan – untuk merujuk ke lokasi memori berikutnya dan sebelumnya, Anda dapat menggunakan operator penugasan untuk mengubah alamat yang berisi penunjuk.
Sebagai contoh:
#include <stdio.h>

int main() {
    int a[5] = {22, 33, 44, 55, 66};
    int *ptr = NULL;
        
    ptr = a;  /* point to the first   array element */
    printf("%d  %x\n", *ptr, ptr);  /* 22 */
    ptr++;
    printf("%d  %x\n", *ptr, ptr);  /* 33 */
    ptr += 3;
    printf("%d  %x\n", *ptr, ptr);  /* 66 */
    ptr--;
    printf("%d  %x\n", *ptr, ptr);  /* 55 */
    ptr -= 2;
    printf("%d  %x\n", *ptr, ptr);  /* 33 */ 
}
Output program mirip dengan:
22 febd4760
33 febd4764
66 febd4770
55 febd476c
33 febd4764 
Ketika pointer bertambah, alamat memori bertambah dengan jumlah byte yang diarahkan. Pada program di atas, pointer bertambah 4 ketika operator increment digunakan (ptr++) karena pointer menunjuk ke int.
Anda juga dapat menggunakan operator ==, <, dan > untuk membandingkan alamat penunjuk.

Pointer dan Fungsi
Pointer sangat memperluas kemungkinan untuk fungsi. Kami tidak lagi terbatas untuk mengembalikan satu nilai. Dengan parameter penunjuk, fungsi Anda dapat mengubah data aktual, bukan salinan data.
Untuk mengubah nilai sebenarnya dari variabel, pernyataan panggilan meneruskan alamat ke parameter penunjuk dalam suatu fungsi.
Misalnya, program berikut menukar dua nilai:
void swap (int  num1, int *num2);

int main() {
  int x = 25;
  int y = 100;

  printf("x is %d, y is %d\n", x, y); 
  swap(&x, &y);
  printf("x is %d, y is %d\n", x, y); 

  return 0;
}
 
void swap (int *num1, int *num2) {
  // int *num1 = &x = 25 
  // int *num2 = &y = 100
  int temp;

  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

Program menukar nilai sebenarnya dari variabel, karena fungsi mengaksesnya dengan alamat menggunakan pointer.

Functions & Arrays
Fungsi dengan Parameter Array
Array tidak dapat diteruskan oleh nilai ke suatu fungsi. Namun, nama array adalah pointer, jadi hanya meneruskan nama array ke suatu fungsi berarti meneruskan pointer ke array.

Pertimbangkan program berikut:
#include <stdio.h>

int add_up (int *a, int num_elements);

int main() {
    int orders[5] = {100, 220, 37, 16, 98};

    printf("Total orders is %d\n", add_up(orders, 5)); 

    return 0;
}

int add_up (int *a, int num_elements) {
  //int *a = orders dimana secara implisit berarti int *a = &orders[0]
  //int num_elements = 5
   int total = 0;
   int k;

   for (k = 0; k < num_elements; k++) {
        total += a[k]; 
   }

    return (total);
}

//Program bukan fungsi
#include <stdio.h>
int main()
{
    int orders[5] = {100, 220, 37, 16, 98};
    //Cara 1
    int *a;
    a = orders;
    //Cara 2
    // int *a = &orders[0];
    int num_elements = 5;
    int total = 0;
    int k;

    for (k = 0; k < num_elements; k++) {
        total += a[k]; 
    }
    printf("Total orders is %d\n", total); 
}

Keluaran program adalah: "Total pesanan adalah 471"

Fungsi yang Mengembalikan Array
Sama seperti pointer ke array dapat diteruskan ke fungsi, pointer ke array dapat dikembalikan, seperti dalam program berikut:
#include <stdio.h>

int * get_evens();

int main() {
    int *a;
    int k;

    a = get_evens(); //Deklarasi pengambilan karakter, dalam hal ini angka (even = 0)
    // Statis (Deklarasi bayangan adalah memasukkan fungsi ke pemanggilan fungsi (Fungsi main))
    // int nums[5];
    // int k;
    // int even = 0;

    // for (k = 0; k < 5; k++) {
    //   nums[k] = even += 2;
    // nums[0] = even + even = 0 + 2, nums[1] = even + even = 2 + 2 = 4, dst.
    // }

    // return (nums); //Mengembalikan elemen-elemen array
    for (k = 0; k < 5; k++)
      printf("%d\n", a[k]); //Mengeluarkan elemen-elemen array

    return 0;
}

int * get_evens () {
   static int nums[5];
   int k;
   int even = 0;

   for (k = 0; k < 5; k++) {
        nums[k] = even += 2;
   }

    return (nums);
}
Perhatikan bahwa pointer, bukan array, dideklarasikan untuk menyimpan nilai yang dikembalikan oleh fungsi. Perhatikan juga bahwa ketika variabel lokal dikeluarkan dari suatu fungsi, Anda perlu mendeklarasikannya sebagai statis dalam fungsi tersebut.
Ingatlah bahwa a[k] sama dengan *(a + k).
