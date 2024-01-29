Fungsi dalam C
Fungsi adalah pusat pemrograman C dan digunakan untuk menyelesaikan solusi program sebagai rangkaian subtugas.
Sebuah fungsi:
  • adalah blok kode yang melakukan tugas tertentu
  • dapat digunakan kembali
  • membuat program lebih mudah untuk diuji
  • dapat dimodifikasi tanpa mengubah program pemanggilan

Menghitung kuadrat dari sebuah angka:
#include <stdio.h>
int main() {
   int x, hasil;
   x = 5;
   hasil = [b]persegi[/b](x);
   printf("%d kuadrat adalah %d\n", x,hasil);
   return 0;
}

Untuk menggunakan fungsi, perlu mendeklarasikannya di atas fungsi main() dan berbentuk:
return_type function_name(parameter); 
Return_type adalah tipe nilai yang dikirim kembali oleh fungsi ke pernyataan pemanggilan. Nama_fungsi diikuti dengan tanda kurung. Nama parameter opsional dengan deklarasi tipe ditempatkan di dalam tanda kurung.
Fungsi tidak diperlukan untuk mengembalikan nilai, tetapi tipe pengembalian harus tetap ada dalam deklarasi. Dalam hal ini, kata kunci void digunakan.
Misalnya, deklarasi fungsi display_message menunjukkan fungsi tidak mengembalikan nilai: void display_message();

Fungsi dalam c
Ketika tipe dan nama parameter disertakan dalam deklarasi, deklarasi tersebut disebut prototipe fungsi.
Misalnya, prototipe fungsi kuadrat muncul di atas main():
#include <stdio.h>
/* deklarasi */
int kuadrat (int num); 
int main() {
   int x, hasil;
   x = 5;
   hasil = kuadrat(x); 
   printf("%d kuadrat adalah %d\n", x,hasil);
   return 0;
}
Fungsi kuadrat kami mengembalikan bilangan bulat dan mengambil satu parameter bertipe int.
Langkah terakhir sebenarnya mendefinisikan fungsi. Definisi fungsi biasanya muncul setelah fungsi main() agar program dapat mengetahui ada fungsi selain fungsi main().
Program lengkap di bawah ini menunjukkan deklarasi dan definisi fungsi kuadrat:
#include <stdio.h>
/* deklarasi */
int kuadrat (int num); //int = return_type, kuadrat = nama_fungsi, (int num) di deklarasi = argumen, di definisi fungsi = parameter.
//Suatu fungsi dapat mengambil beberapa parameter dipisahkan dengan koma.
//return type functionname(parameter1, parameter2, dst)
int main() {
  //Kode yang akan dieksekusi
   int x = 5, z = 10, hasil;
   hasil = kuadrat(z); //Pernyataan pemanggilan fungsi berdasarkan variabel yang dipinjamkan
   printf("%d kuadrat adalah %d\n", z, hasil);
   return 0;
}
/* definisi */
int kuadrat (int num) { //Mengambil satu parameter bertipe int, yaitu int x = 5
  //int num = z = 10
  int y;
  y = num * num;
  return(y); //Mengembalikan hasil fungsi ke pernyataan pemanggilan
} 

Definisi fungsi dapat diletakkan di atas fungsi main(), tanpa harus mendeklarasikan fungsi tersebut. Contoh:
#include <stdio.h>
int main()
{
  //Definisi fungsi
  int kuadrat (int num)
  {
    int y;
    y = num * num;
    return(y);
  }
  
  int main() {
  //Kode yang akan dieksekusi
  int x = 5, z = 10, hasil;
  hasil = kuadrat(z); //Pernyataan pemanggilan fungsi berdasarkan variabel yang dipinjamkan
  printf("%d kuadrat adalah %d\n", x, hasil);
  return 0;
  }
}
Fungsi kuadrat menghitung dan mengembalikan kuadrat dari parameternya.
Suatu fungsi dapat mengambil beberapa parameter - dalam hal ini harus dipisahkan dengan koma.
Pernyataan kembali digunakan untuk mengirim nilai kembali ke pernyataan panggilan.
Fill in the blanks to declare a function named "triple" taking an int parameter and returning its value times 3:
#include <stdio.h>
int triple (int num) {
    int y;
    y = num * 3;
    return y;
}

Parameter Fungsi
Parameter fungsi digunakan untuk menerima nilai yang diperlukan oleh fungsi. Nilai diteruskan ke parameter ini sebagai argumen melalui pemanggilan fungsi.
Secara default, argumen diteruskan dengan nilai, yang berarti salinan data diberikan ke parameter fungsi yang dipanggil. Variabel aktual tidak diteruskan ke fungsi, sehingga tidak akan berubah.
Argumen yang diteruskan ke fungsi dicocokkan dengan parameter berdasarkan posisi. Oleh karena itu, argumen pertama diteruskan ke parameter pertama, yang kedua ke parameter kedua, dan seterusnya.
Program berikut mendemonstrasikan parameter yang diteruskan oleh nilai:
#include <stdio.h>
int jumlah_up(int x, int y); //Argumen pertama diteruskan ke parameter pertama, yang kedua ke parameter kedua, dan seterusnya.
int main() {
  int x, y, hasil;
  x = 3;
  y = 12;
  hasil = jumlah_up(x, y); //Pernyataan pemanggilan fungsi berdasarkan variabel yang dipinjamkan
  //Return (x) bukan berarti nilai x pada int main berubah menjadi 15 melainkan hasil = 15
  printf("%d + %d = %d", x, y, hasil);
  return 0;
}
int jumlah_up (int x, int y) { //Parameter menerima nilai dari argumen berdasarkan posisi 
  //Mengambil dua parameter bertipe int, yaitu int x = int x = 3, int y = int y = 12
  //Jika nilai yang diteruskan pernyataan pemanggilan fungsi jumlah_up(y, x), maka yang akan terjadi adalah int x = int y = 12 dan int y = int x = 3 sehingga ketika x -= y = 9
  x += y;
  return (x); //Mengembalikan hasil fungsi ke pernyataan pemanggilan
}
Keluaran programnya adalah: 3 + 12 = 15
Nilai x dan y diteruskan ke jumlah_up. Perhatikan bahwa meskipun nilai parameter x diubah di jumlah_up, nilai argumen x di main() tidak diubah karena hanya nilainya yang diteruskan ke parameter x.
Parameter dalam deklarasi fungsi adalah parameter formal. Nilai yang diteruskan ke parameter ini adalah argumen, terkadang disebut parameter aktual.

Fungsi berikut yang mengambil serangkaian karakter dengan nama sebagai parameter. Saat fungsi dipanggil, kami memberikan nama, yang digunakan di dalam fungsi untuk mencetak "Halo" dan nama setiap orang.
void myFunction(char name[]) {
  //char name[] = "Liam"
  //char name[] = "Jenny"
  //char name[] = "Anja"
  printf("Hello %s\n", name);
}

int main() {
  myFunction("Liam");
  myFunction("Jenny");
  myFunction("Anja");
  return 0;
}

// Hello Liam
// Hello Jenny
// Hello Anja

//Ingat!
#include <stdio.h>
int main()
{
    int x, y;
    char text[20]; //String disimpan dalam array char 
    scanf("%3d %d %5s", &x, &y, text); //& tidak diperlukan untuk string karena nama string berfungsi sebagai pointer.
    //Penulisan angka di belakang format % akan memindai banyak bilangan/karakter (Misal 1234 dengan %3d akan memindai 123) (Misal Ronald dengan %5d akan memindai Ronal)
    /* masukan: 1234 5,7 gajah */
    printf("%d %d %s", x, y, text);
    /* keluaran: 12 34 gajah */ //%d pada keluaran akan memindai sisa dari %d pertama, bukan 5,7. 
}

Lulus Array sebagai Parameter Fungsi
Anda juga bisa meneruskan array ke suatu fungsi:
Contoh
#include <stdio.h>
void myFunction(int myNumbers[5]) {
  //int myNumbers[5] = {10, 20, 30, 40, 50};
  for (int i = 0; i < 5; i++) {
    printf("%d\n", myNumbers[i]);
  }
}

void myFunction();
int main() {
  int myNumbers[5] = {10, 20, 30, 40, 50};
  myFunction(myNumbers);
  return 0;
}
Fungsi (myFunction) mengambil array sebagai parameternya (int myNumbers[5]), dan mengulang melalui elemen array dengan for loop.
Saat fungsi dipanggil di dalam main(), kita meneruskan larik myNumbers, yang menampilkan elemen larik.
Perhatikan bsahwa saat Anda memanggil fungsi, Anda hanya perlu menggunakan nama larik saat meneruskannya sebagai argumen myFunction(myNumbers). Namun, deklarasi lengkap dari array diperlukan dalam parameter fungsi (int myNumbers[5]).

Nilai Pengembalian
Kata kunci void, yang digunakan pada contoh sebelumnya, menunjukkan bahwa fungsi tidak boleh mengembalikan nilai. Jika Anda ingin fungsi mengembalikan nilai, Anda dapat menggunakan tipe data (seperti int atau float, dll.) alih-alih batal, dan gunakan kata kunci return di dalam fungsi:
Contoh
int myFunction(int x) {
  //int x = 3
  return 5 + x;
}

int main() {
  printf("Result is: %d", myFunction(3));
  return 0;
}
// Outputs 8 (5 + 3)

Contoh ini mengembalikan jumlah fungsi dengan dua parameter:
Contoh
int myFunction(int x, int y) {
  return x + y;
}

int main() {
  printf("Result is: %d", myFunction(5, 3));
  return 0;
}
// Outputs 8 (5 + 3)

Anda juga dapat menyimpan hasil ke suatu variabel
Contoh
int myFunction(int x, int y) {
  //int x = 5, int y = 3
  return x + y;
}

int main() {
  int result = myFunction(5, 3);
  printf("Result is = %d", result);
  return 0;
}
// Outputs 8 (5 + 3)
