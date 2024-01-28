Beberapa escape sequence: '\n' (newline), '\t' (horizontal tab), '\v' (vertical tab), '\f' (new page), '\r' (carriage return), '\b' (backspace).

#include <stdio.h>
int main()
{
    printf("Hi, \t everyone!");
    return 0;
}

#include <stdio.h>
int main()
{
    printf("Hi, \v everyone!");
    return 0;
}

#include <stdio.h>
int main()
{
    printf("Hi, \r everyone!");
    return 0;
}

#include <stdio.h>
int main()
{
    printf("Hi, everyone\b!"); //Menghapus karakter sebelum \b
    return 0;
}
