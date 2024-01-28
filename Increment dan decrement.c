Increment & Decrement
Menambahkan 1 ke variabel dapat dilakukan dengan operator increment (kenaikan) ++. Demikian pula, operator pengurangan -- digunakan untuk mengurangkan 1 dari suatu variabel.
Operator increment dan decrement dapat digunakan baik prefix (sebelum nama variabel) atau postfix (setelah nama variabel). Cara mana Anda menggunakan operator dapat menjadi penting dalam pernyataan penugasan, seperti dalam contoh berikut.
z = 3;
x = z--; //Decrement Postfix /* tetapkan 3 ke x, lalu decrement(turunkan) z ke 2 */
y = 3;
x = ++y; //Increment Prefix /* increment y ke 4, lalu tetapkan 4 ke x */
Bentuk prefix menambah/mengurangi variabel dan kemudian menggunakannya dalam pernyataan penugasan.
Bentuk postfix menggunakan nilai variabel terlebih dahulu, sebelum menambah/menguranginya.

Latihan
#include <stdio.h>
int main()
{
    int x = 8;
    int y = 7;
    x++; //Akhir pernyataan, maka nilai x = 8 langsung ditambah +1
    x+= y--; // x = x + y-- // Masukkan y = 7 ke pernyataan terlebih dahulu, baru dikurang. x = 9 + 7 = 16
    printf("%d %d", x, y);
}
