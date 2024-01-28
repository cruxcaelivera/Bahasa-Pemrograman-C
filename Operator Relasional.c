Operator && 
Logis AND operator && mengembalikan hasil yang benar hanya jika kedua ekspresi benar.
Sebagai contoh:
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n > 0 && n <= 100) //Mengeksekusi pernyataan ketika kedua kondisi benar. Jika kedua kondisi tidak dipenuhi atau salah satu benar, program tidak dieksekusi.
    printf("Jangkauan (1 - 100).\n");
}

|| Operator (Either (Atau/Salah Satu)
Logika OR operator || mengembalikan hasil yang benar ketika salah satu ekspresi atau kedua ekspresi itu benar.
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 999 || (n > 0 && n <= 100))
      printf("Masukan valid.\n");
}

! Operator
Operator NOT yang logis! mengembalikan kebalikan dari nilainya.
NOT true mengembalikan false, dan NOT false mengembalikan true.
Sebagai contoh:
#include<stdio.h>
int main()
{
int n, x, X;
scanf("%d %d %d", &n, &x, &X);
if (!(n == x || n == X)) //Ketika salah satu pernyataan benar, maka if(kondisi salah karena operator ! sehingga yang dieksekusi adalah else)
    printf("Angka romawi bukan 10.\n"); 
else //Ketika kedua pernyataan salah, maka if(kondisi benar karena operator! sehingga yang diekseksusi adalah if)
    printf("Tidak sama\n");
}
Di C, setiap nilai bukan nol dianggap benar dan 0 salah. Oleh karena itu, operator NOT logis, mengonversi nilai benar menjadi 0 dan nilai salah menjadi 1.
