strings
String
String dalam C adalah larik karakter yang diakhiri dengan karakter NULL '\0'.
Deklarasi string dapat dilakukan dengan beberapa cara, masing-masing dengan pertimbangannya sendiri.
Sebagai contoh:
char str_name[str_len] = "string"; 
Ini membuat string bernama str_name dari karakter str_len dan menginisialisasi ke nilai "string".
Saat Anda memberikan literal string untuk menginisialisasi string, kompiler secara otomatis menambahkan karakter NULL '\0' ke array karakter.
Untuk alasan ini, Anda harus mendeklarasikan ukuran array setidaknya satu karakter lebih panjang dari panjang string yang diharapkan.
Pernyataan di bawah membuat string yang menyertakan karakter NULL. Jika deklarasi tidak menyertakan ukuran array karakter, maka akan dihitung berdasarkan panjang string dalam inisialisasi ditambah satu untuk '\0':
#include <stdio.h>
int main() {
    char str1[6] = "hello";
    char str2[ ] = "world";  /* size 6 */
    printf("str1 is: %s, str2 is: %s", str1, str2);
    
    return 0;
}
Sebuah string juga dapat dideklarasikan sebagai sekumpulan karakter:
#include <stdio.h>
int main() {
    char str3[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str4[ ] = {'h', 'e', 'l', 'l', 'o', '\0'}; /* size 6 */
    printf("str3 is: %s, str4 is: %s", str3, str4);
    return 0;
}
Dengan pendekatan ini, karakter NULL harus ditambahkan secara eksplisit. Perhatikan bahwa karakter diapit oleh tanda kutip tunggal.
Seperti halnya array apa pun, nama string bertindak sebagai penunjuk.
Literal string adalah teks yang diapit dengan tanda kutip ganda.
Karakter, seperti 'b', ditandai dengan tanda kutip tunggal dan tidak dapat diperlakukan sebagai string.
Deklarasi penunjuk string seperti char *str = "stuff"; dianggap sebagai konstanta dan tidak dapat diubah dari nilai awalnya.
Untuk mengoperasikan string dengan aman dan nyaman, Anda dapat menggunakan fungsi string Perpustakaan Standar yang ditunjukkan di bawah ini. Jangan lupa sertakan <string.h>.
strlen() - mendapatkan panjang string
strcat() - menggabungkan dua string
strcpy() - salin satu string ke string lainnya
strlwr() - mengubah string menjadi huruf kecil
strupr() - mengubah string menjadi huruf besar
strrev() - membalikkan string
strcmp() - membandingkan dua string

EOF - End of File 'akhir file' menunjukkan akhir dari input. Baris baru (yang terjadi saat Anda menekan enter) bukanlah akhir dari sebuah file.
Baris baru tersebut bukanlah akhir, juga tidak mengakhiri program.
Gunakan CTRL + Z pada Windows setelah menekan enter.
EOF biasanya didefinisikan sebagai konstanta dengan nilai -1.


https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
https://www.geeksforgeeks.org/ctype-hcctype-library-in-c-c-with-examples/
File header ctype.h dari C Standard Library mendeklarasikan beberapa fungsi yang berguna untuk menguji dan memetakan karakter.
Semua fungsi menerima int sebagai parameter, yang nilainya harus EOF atau dapat direpresentasikan sebagai karakter yang tidak ditandatangani.
Semua fungsi menghasilkan bukan nol (benar) jika argumen c memenuhi kondisi yang dijelaskan, dan nol (salah) jika tidak.
Fungsi Perpustakaan
Berikut ini adalah fungsi yang didefinisikan di header ctype.h −

Sr.No.	Deskripsi fungsi
1	int isalnum(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah alfanumerik.

2	int isalpha(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah abjad/Mengidentifikasi huruf dari karakter lain.

3	int iscntrl(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah karakter kontrol (\n, \b, \t, \r)

4	int isdigit(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah angka desimal/Mengidentifkasi angka dalam karakter

5	int isgraph(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan memiliki representasi grafis menggunakan lokal.

6	int islower(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah huruf kecil.

7	int isprint(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan dapat dicetak.

8	int ispunct(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah karakter tanda baca (Karakter yang bukan alfanumerik atau spasi).

9	int isspace(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah spasi putih.

10	int isupper(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah huruf besar.

11	int isxdigit(int c)
Fungsi ini memeriksa apakah karakter yang diteruskan adalah digit heksadesimal.

12 isblank(int c)
Fungsi ini 

Pustaka juga berisi dua fungsi konversi yang menerima dan mengembalikan "int".

Sr.No.	Deskripsi fungsi
1	int tolower(int c)
Fungsi ini mengubah huruf besar menjadi huruf kecil.

2	int toupper(int c)
Fungsi ini mengubah huruf kecil menjadi huruf besar.

Kelas Karakter
Sr.No.	Kelas Karakter & Deskripsi
1	
Digits

Ini adalah himpunan bilangan bulat { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.

2	
Digit heksadesimal

Ini adalah himpunan dari { 0 1 2 3 4 5 6 7 8 9 ABCDEF abcdef }.

3	
Huruf kecil

Ini adalah kumpulan huruf kecil { abcdefghijklmnopqrstu vwxyz }.

4	
Huruf besar

Ini adalah kumpulan huruf kapital {ABCDEFGHIJKLMNOPQRSTU VWXYZ }.

5	
Letters

Ini adalah satu set huruf kecil dan huruf besar.

6	
Karakter alfanumerik

Ini adalah satu set Digit, huruf kecil dan huruf besar.

7	
Karakter tanda baca

Ini adalah satu set! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~ "

8	
Karakter grafis

Ini adalah kumpulan karakter alfanumerik dan tanda baca.

9	
Karakter space

Ini adalah sekumpulan tab, baris baru, tab vertikal, umpan formulir, carriage return, dan spasi.

10	
Karakter yang dapat dicetak

Ini adalah sekumpulan karakter Alfanumerik, karakter Tanda Baca, dan karakter Spasi.

11	
Kontrol karakter

Dalam ASCII, karakter ini memiliki kode oktal 000 hingga 037, dan 177 (DEL).

12	
Karakter kosong

Ini adalah spasi dan tab.

13	
Karakter alfabet

Ini adalah satu set huruf kecil dan huruf besar.


Input String
Program seringkali bersifat interaktif, meminta input dari pengguna.
Untuk mengambil sebaris teks atau string lain dari pengguna, C menyediakan fungsi scanf(), gets(), dan fgets().
Anda dapat menggunakan scanf() untuk membaca input sesuai dengan penentu format.
Sebagai contoh:
#include <stdio.h>
int main() {
    char first_name[25];
    int age;
    printf("Enter your first name and age: \n");
    scanf("%s %d", first_name, &age);
    
    printf("\nHi, %s. Your age is %d", first_name, age);
    
    return 0;
}

Ketika scanf() digunakan untuk membaca string, & tidak perlu mengakses alamat variabel karena nama array bertindak sebagai pointer.
scanf() berhenti membaca input ketika mencapai spasi. Untuk membaca string dengan spasi, gunakan fungsi get(). Itu membaca input sampai baris baru terminasi tercapai (tombol Enter ditekan).
Sebagai contoh:
#include <stdio.h>
int main() {
    char full_name[50];
    printf("Enter your full name: ");
    gets(full_name);
    // scanf("%s", full_name);
    
    printf("\nHi, %s.", full_name);
    
    return 0;
}

Alternatif yang lebih aman untuk gets() adalah fgets(), yang membaca hingga sejumlah karakter tertentu. Pendekatan ini membantu mencegah buffer overflow, yang terjadi ketika array string tidak cukup besar untuk teks yang diketik.
Sebagai contoh:
#include <stdio.h>
int main() {
    char full_name[50];
    printf("Enter your full name: ");
    fgets(full_name, 50, stdin);
    printf("\nHi, %s", full_name);
    return 0;
}

Argumen fgets() adalah nama string, jumlah karakter yang akan dibaca, dan pointer ke tempat Anda ingin membaca string. stdin artinya membaca dari input standar, yaitu keyboard.
Perbedaan lain antara get dan fgets adalah bahwa karakter baris baru disimpan oleh fgets.
fgets() hanya membaca n-1 karakter dari stdin karena harus ada ruang untuk '\0'.

Output String
Keluaran string ditangani dengan fungsi fputs(), puts(), dan printf().
fputs() membutuhkan nama string dan penunjuk ke tempat Anda ingin mencetak string. Untuk mencetak ke layar, gunakan stdout yang mengacu pada keluaran standar.
Sebagai contoh:
#include <stdio.h>
int main()
{
  char city[40];
  printf("Enter your favorite city: ");
  gets(city);
  // Note: for safety, use
  // fgets(city, 40, stdin);
  fputs(city, stdout);
  //puts(city) bandingkan dengan fputs!
  printf(" is a fun city.");
  return 0;
} 

Fungsi puts() hanya mengambil argumen string dan juga dapat digunakan untuk menampilkan output. Namun, itu menambahkan baris baru ke output.
Sebagai contoh:
#include <stdio.h>
int main()
{
  char city[40];
  printf("Enter your favorite city: ");
  gets(city);
  // Note: for safety, use
  // fgets(city, 40, stdin);

  puts(city);

  return 0;
}

