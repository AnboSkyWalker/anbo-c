#include <stdio.h>
#include <stdint.h>

void test1()
{
    int a=10, b=20;
    printf("[test1] before a=%d; b=%d\n", a, b);
    __asm__(
        "mov %%eax, %2;"
        "mov %%ebx, %3;"
        "mov %0, %%ebx;"
        "mov %1, %%eax;"
        :"=r"(a), "=r"(b) // output a=%0; b=%1
        :"r"(a), "r"(b) // input a=%2; b=%3
        :"eax", "ebx" // list of clobbered registers
    );
    printf("[test1] after a=%d; b=%d\n", a, b);
}

void test2()
{
    uint32_t len = 13;
    uint8_t ok = 0x77;
    for (uint32_t i=0; i<len; i++) {
        __asm__(
            "mov %%eax, %1;"
            // special (i+x)%4  x may be 0 1 2 3 4 and so on
            "add %%eax, 4;" // 0 1 2 3 4 ... and so on
            "mov %%esi, %%eax;"
            "sar %%eax, 0x1f;"
            "shr %%eax, 0x1e;"
            "add %%esi, %%eax;"
            "and %%esi, 3;"
            "sub %%esi, %%eax;"

            "mov %%eax, %%esi;"
            "mov %0, %%al;"
            //:"=r"(key3[i]) // output key3[i]=%0
            :"=r"(ok) // output ok=%0
            :"r"(i) // input i=%1
            :"eax", "esi"
        );
        printf("[test2] ok=%d\n", ok);
    }
}

int main(int argc, char *argv[])
{
    test1(); 
    test2(); 
    return 0;
}
