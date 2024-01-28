#include <stdio.h>
int main()
{
    printf("Pohon memiliki %d apel.\n", 22); //Angka masuk ke dalam %d 
    /* Pohon itu memiliki 22 buah apel. */
    printf("\"Hello World!\"\n");
    /* "Halo Dunia!" */
}

#include <stdio.h>
int main()
{
    printf("Warna: %s, Angka: %d, float: %5.2f\n", "merah", 42, 3.14159); //%5 berarti memberikan spasi sebanyak 5 dan %.2f pembulatan 2 angka di belakang koma (Angka dekat format)
    //Pada Bahasa Pemrograman C, Simbol %c Pada printf() Berfungsi Menampilkan Karakter. Sementara, %s Berfungsi Menampilkan Teks (String) Berupa char[], char*, atau const char[].
    /* Warna: merah, Nomor: 42, float: 3,14 */
    printf("Pi = %3.2f\n", 3.14159);
    /* Pi = 3,14 */
    printf("Pi = %8.5f\n", 3.14159);
    /* Pi = 3,14159 */
    printf("Pi = %-8.5f\n", 3.14159); //Output menjorok ke dalam
    /* Pi = 3,14159 */
    printf("Ada %d %s di pohon.\n", 22, "apel");
    /* Ada 22 apel di pohon. */
}
