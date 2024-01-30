String Functions
Fungsi sprintf dan sscanf
String yang diformat dapat dibuat dengan fungsi sprintf(). Ini berguna untuk membangun string dari tipe data lain.
Sebagai contoh:
#include <stdio.h>
int main()
{
  char info[100];
  char dept[ ] = "HR";
  int emp = 75;
  sprintf(info, "The %s dept has %d employees.", dept, emp);
  printf("%s\n", info);

  return 0;
}
Fungsi lain yang berguna adalah sscanf() untuk memindai string untuk mencari nilai. Fungsi membaca nilai dari string dan menyimpannya di alamat variabel yang sesuai.
Sebagai contoh:
#include <stdio.h>
int main()
{
  char info[ ] = "Snoqualmie WA 13190";
  char city[50];
  char state[50];
  int population;
  sscanf(info, "%s %s %d", city, state, &population);
  printf("%d people live in %s, %s.", population, city, state);
  return 0;
}
