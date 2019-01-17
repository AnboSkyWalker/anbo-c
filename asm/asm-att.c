#include <stdio.h>
#include <stdint.h>

void test1()
{
    int a=10, b=20;
    printf("[test1] before a=%d; b=%d\n", a, b);
    __asm__(
        // b byte; w word; l long; q xx-64 bit
        "movl %2, %%eax;"
        "movl %3, %%ebx;"
        "movl %%ebx, %0;"
        "movl %%eax, %1;"
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
        //__asm__(
        __asm__ __volatile__(
            "movl %1, %%eax;"
            // special (i+x)%4  x may be 0 1 2 3 4 and so on
            "add $0x4, %%eax;" // 0 1 2 3 4 ... and so on
            "movl %%eax, %%esi;"
            "sar $0x1f, %%eax;"
            "shr $0x1e, %%eax;"
            "add %%eax, %%esi;"
            "and $0x3, %%esi;"
            "sub %%eax, %%esi;"

            "mov %%esi, %%eax;"
            "movb %%al, %0;"
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
