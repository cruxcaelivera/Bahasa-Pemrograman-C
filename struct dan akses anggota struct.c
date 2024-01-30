Structures & Unions
Structures
Struktur
Struktur adalah tipe data yang ditentukan pengguna yang mengelompokkan variabel terkait dari tipe data yang berbeda.
Deklarasi struktur mencakup kata kunci struct, tag struktur untuk referensi struktur, dan kurung kurawal {} dengan daftar deklarasi variabel yang disebut anggota.
Sebagai contoh:
struct course {
  int id;
  char title[40];
  float hours; 
};
Pernyataan struct ini mendefinisikan tipe data baru bernama course yang memiliki tiga anggota.
Anggota struktur dapat berupa tipe data apa pun, termasuk tipe dasar, string, array, pointer, dan bahkan struktur lainnya, seperti yang akan Anda pelajari di pelajaran selanjutnya.
Jangan lupa beri titik koma setelah deklarasi struktur.
Struktur juga disebut tipe data komposit atau agregat. Beberapa bahasa menyebut struktur sebagai catatan.

Deklarasi Menggunakan Struktur
Untuk mendeklarasikan variabel dari tipe data struktur, Anda menggunakan kata kunci struct diikuti dengan tag struct, dan kemudian nama variabel.
Misalnya, pernyataan di bawah ini mendeklarasikan tipe data struktur dan kemudian menggunakan struktur siswa untuk mendeklarasikan variabel s1 dan s2:
struct student {
  int age;
  int grade;
  char name[40];
};

/* declare two variables */
struct student s1;
struct student s2;
Variabel struct disimpan dalam blok memori yang berdekatan. Operator sizeof harus digunakan untuk mendapatkan jumlah byte yang dibutuhkan untuk sebuah struct, sama seperti tipe data dasar.


Deklarasi Menggunakan Struktur
Variabel struct juga dapat diinisialisasi dalam deklarasi dengan mencantumkan nilai awal secara berurutan di dalam kurung kurawal:
#include <stdio.h>

struct student {
    int age;
    int grade;
    char name[40];
};

int main() {
    /* declare two variables */
    struct student s1 = {19, 9, "John Birghimer"}; //s1 dengan tipe data struct student dengan 3 anggota. 
    struct student s2 = {22, 10, "Batman Jokerson"};
    
    printf("Student: %s, %d\n", s1.name, s1.age); //pemanggilan anggota struct nama variabel dengan tipe data struct.nama anggota
    printf("Student: %s, %d\n", s2.name, s2.age);
    
    return 0;
}

Jika Anda ingin menginisialisasi struktur menggunakan kurung kurawal setelah deklarasi, Anda juga perlu mengetikkan cast, seperti pada pernyataan:
#include <stdio.h>

struct student {
    int age;
    int grade;
    char name[40];
};

int main() {
    struct student s1; // declaring
    
    // type cast needed
    s1= (struct student){19, 9, "John Birghimer"}; //
    
    printf("Student: %s, %d\n", s1.name, s1.age);
    
    return 0;
}

Anda dapat menggunakan inisialisasi anggota bernama saat menginisialisasi struktur untuk menginisialisasi anggota terkait:
struct student s1 
#include <stdio.h>

struct student {
    int age;
    int grade;
    char name[40];
};

int main() {
    struct student s1 = { .grade = 9, .age = 19, .name = "John Birghimer"};
    
    printf("Name: %s, Age: %d, Grade: %d\n", s1.name, s1.age, s1.grade);
    
    return 0;
}

Pada contoh di atas, .grade mengacu pada anggota grade dari struktur. Demikian pula, .age dan .name mengacu pada usia dan nama anggota.

Mengakses Anggota Struktur
Anda mengakses anggota variabel struct dengan menggunakan . (operator titik) antara nama variabel dan nama anggota.
Misalnya, untuk menetapkan nilai ke anggota usia variabel struct s1, gunakan pernyataan seperti:
s1.age = 19;
Anda juga dapat menetapkan satu struktur ke struktur lain dengan tipe yang sama:
struct student s1 = {19, 9, "Jason"};
struct student s2;
//....
s2 = s1;
Kode berikut menunjukkan menggunakan struktur:
#include <stdio.h>
#include <string.h> //Karena menggunakan strcpy()

struct course {
  int id;
  char title[40];
  float hours; 
};

int main() {
  struct course cs1 = {341279, "Intro to C++", 12.5};
  struct course cs2;

  /* initialize cs2 */
  cs2.id = 341281;
  strcpy(cs2.title, "Advanced C++"); //cs2.title = "Advanced C++"
  cs2.hours = 14.25;
   
  /* display course info */
  printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours); 
  printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);
  
  return 0;
}
Penetapan string membutuhkan strcpy() dari perpustakaan string.h.
Perhatikan juga penentu format %4.2f menyertakan opsi lebar dan presisi.
