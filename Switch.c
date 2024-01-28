Pernyataan saklar (Switch)
Pernyataan switch mencabangkan kontrol program dengan mencocokkan hasil ekspresi dengan nilai kasus konstan.
switch (variabel) {
   case nilai1:
     pernyataan;
   break; Pernyataan break diperlukan dalam setiap kasus untuk bercabang ke akhir pernyataan switch. 
   case nilai2:
     pernyataan
   break; 
   default: Kasus default opsional dijalankan ketika tidak ada kecocokan lain yang dibuat. Default sama seperti Else.
     pernyataan
}

Misalnya, program berikut menampilkan "Tiga":
#include <stdio.h>
int main()
{
    int bil = 3;
    switch (bil) 
    {
        case 1:
            printf("Satu\n");
            break;
        case 2:
            printf("Dua\n");
            break;
        case 3:
            printf("Tiga\n");
            break;
        default:
            printf("Bukan 1, 2, atau 3.\n"); 
    }
}

Tanpa pernyataan break, eksekusi program jatuh ke pernyataan kasus berikutnya. 
#include <stdio.h>
int main()
{
    int bil = 4; 
    switch (bil) {
    case 1: 
        // printf("Satu\n"); Jika diberi break, dan inisialisasi nilai awal = 1, tapi tidak ada pernyataan untuk dieksekusi, maka tidak ada output.
    case 2:
    case 3:
        printf("Satu, Dua, atau Tiga.\n"); //Jika nilai 1, 2, atau 3, maka outputnya adalah ini karena pada case 1 dan 2 tidak terdapat break. 
        break;
    case 4:
    case 5:
    case 6:
        printf("Empat, Lima, atau Enam.\n"); //Jika nilai 4, 5 atau 6, maka outputnya adalah ini karena pada case 4 dan 5 tidak terdapat break
        break;
    default:
        printf("Lebih besar dari Enam.\n"); //Jika pada case 6 tidak terdapat break, maka outputnya adalah Empat, Lima, atau Enam.\n lalu Lebih besar dari Enam.\n.
    }
}
