#include <stdio.h>
int main()
{
    int x, y;
    char text[20]; //String adalah array char 
    scanf("%3d %d %5s", &x, &y, text); //& tidak diperlukan untuk string karena nama string berfungsi sebagai pointer.
    //Khusus dalam tipe data integer dan string, penggunaan angka  dibelakang % hanya akan memindai banyak bilangan bulat (Misal 1234 dengan %3d akan memindai 123)
    /* masukan: 1234 5,7 gajah */
    printf("%d %d %s", x, y, text);
    /* keluaran: 12 34 gajah */ //%d pada keluaran akan memindai sisa dari %d pertama, bukan 5,7. 
}
