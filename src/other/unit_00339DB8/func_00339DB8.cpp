typedef unsigned int u32;
typedef unsigned long u64;

extern "C" u32 func_004B2AC8(void);

extern "C" u64 func_00339DB8(void) {
    return (u64)(u32)func_004B2AC8();
}
