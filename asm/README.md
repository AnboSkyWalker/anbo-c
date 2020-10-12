
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

# compile to thumb mode, opcode 2 or 4 bytes, default is thumb mode
arm-linux-gnueabi-gcc -mthumb 

# compile to arm mode, opcode 4 bytes
arm-linux-gnueabi-gcc -marm

aarch64-linux-gnu-gcc
```
