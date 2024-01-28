Pernyataan if
Pernyataan if disebut struktur kontrol bersyarat karena mengeksekusi pernyataan ketika kondisi benar. 
Dalam perintah if dapat berisikan lebih dari 2 operator relasional (==, dll)
#include <stdio.h>
int main() {
   int skor = 89;
   if (skor > 75) //if (kondisi), tidak diakhiri titik koma ;
     printf("Anda lulus.\n");
   return 0;
}

Operator Relasional
< kurang dari
<= kurang dari atau sama dengan
> lebih besar dari
>= lebih besar dari atau sama dengan
== sama dengan
!= tidak sama dengan
&& jika ... dan ... maka
|| jika ... atau ... maka

#include <stdio.h>
int main()
{
    int bilangan = 41;
    bilangan += 1;
    if (bilangan == 42) {
        printf("Anda menang!");
    }
}

Pernyataan if dapat menyertakan klausa else opsional yang mengeksekusi pernyataan saat kondisi salah.
#include <stdio.h>
int main(){
    int skor = 89;
    if (skor > 89){
        printf("10% teratas\n");
    }
    else{
        printf("Kurang dari 90.\n");
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        c = a - b;
        if (c < 5) printf("%d\n", a); 
        else printf("%d\n", b);
    }
    else printf("%d\n", b - a);
}

#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b > c) printf("menurun\n"); //Tidak bisa mengerjakan operator sekaligus, sehingga outputnya akan selalu else. Solusi = Gunakan Operator Relasional.
    if (a > b && b > c) printf("menurun\n"); //Kode program yang baik
    else printf("tidak menurun\n");
}

Nested If Statements
Pernyataan Jika Bersarang (Nested If)
Pernyataan if dapat menyertakan pernyataan if lainnya untuk membentuk pernyataan bersarang. Bersarang jika memungkinkan keputusan didasarkan pada persyaratan lebih lanjut.

#include <stdio.h>
int main()
{
    int laba, klien, bonus;
    scanf("%d", &laba);
    if (laba > 1000)
    {
        scanf("%d", &klien);
        if (klien > 15)
            bonus = 100;
        else //Kalau else di taruh di luar kurung kurawal, berarti jika laba <= 1000, bonus = 25.
            bonus = 25;
        
    }
    printf("%d", bonus); //printf jika ditaruh dalam kurung atau ditaruh di sini akan menghasilkan keluaran yang sama.
}

Pernyataan if-else if
Ketika keputusan di antara tiga tindakan atau lebih diperlukan, pernyataan if-else if dapat digunakan.
#include <stdio.h>
int main()
{
    int skor;
    scanf("%d", skor); 
    if (skor >= 90)
    {
        printf("%s", "10% Teratas\n"); 
    }
    else if (skor >= 80)
    {
        printf("%s", "20% Teratas\n"); //Else if untuk mengeksekusi pernyataaan, jika ada kondisi kedua, 3, dst
    }
    else if (skor > 75)
    {
        printf("%s", "Anda lulus.\n");
    }
    else
    {
        printf("%s", "Anda tidak lulus.\n"); //Else untuk mengeksekusi pernyataan di luar kondisi yang ada
    }
}
