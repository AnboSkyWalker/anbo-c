
# asm
## opcode
```asm
pop ecx     ; 1 byte
add esp, 4  ; 3 bytes

xor eax, eax ; 2 bytes

```


# gcc
```bash
# create intel style assembly
gcc -S -masm=intel
```

# objdump
```bash
objdum -d -Mintel xxx
```

# cross-compile-arm&aarch64
```bash
sudo apt install gcc-arm-linux-gnueabi
sudo apt install gcc-aarch64-linux-gnu
sudo apt install qemu-user

arm-linux-gnueabi-gcc
aarch64-linux-gnu-gcc
```