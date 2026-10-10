typedef int s32;

/* A function-local static object written out: guard D_0057C2C4, object D_00766CF8, its
   constructor func_002A7A30 and the atexit-registered destructor stub func_002A9DF0. */
extern "C" s32 D_0057C2C4;
extern "C" char D_00766CF8[];
extern "C" void *func_002A7A30(void *obj);
extern "C" void func_002A9DF0(void);
extern "C" s32 func_004F4D20(void (*fn)(void));

extern "C" void *func_002A8C20(void) {
    if (D_0057C2C4 == 0) {
        func_002A7A30(D_00766CF8);
        D_0057C2C4 = 1;
        func_004F4D20(func_002A9DF0);
    }
    return D_00766CF8;
}
