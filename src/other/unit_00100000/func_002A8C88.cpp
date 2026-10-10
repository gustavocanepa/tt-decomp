typedef int s32;

/* A function-local static object written out: guard D_0057C2C8, object D_00766D00, its
   constructor func_002A7A30 and the atexit-registered destructor stub func_002A9E18. */
extern "C" s32 D_0057C2C8;
extern "C" char D_00766D00[];
extern "C" void *func_002A7A30(void *obj);
extern "C" void func_002A9E18(void);
extern "C" s32 func_004F4D20(void (*fn)(void));

extern "C" void *func_002A8C88(void) {
    if (D_0057C2C8 == 0) {
        func_002A7A30(D_00766D00);
        D_0057C2C8 = 1;
        func_004F4D20(func_002A9E18);
    }
    return D_00766D00;
}
