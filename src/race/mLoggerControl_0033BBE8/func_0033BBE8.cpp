typedef int s32;

/* A function-local static object written out: guard D_00583EE8, object D_00767AA0, its
   constructor RaceInput__structor_0 and the atexit-registered destructor stub func_0033CC78. */
extern "C" s32 D_00583EE8;
extern "C" char D_00767AA0[];
extern "C" void *RaceInput__structor_0(void *obj);
extern "C" void func_0033CC78(void);
extern "C" s32 func_004F4D20(void (*fn)(void));

extern "C" void *func_0033BBE8(void) {
    if (D_00583EE8 == 0) {
        RaceInput__structor_0(D_00767AA0);
        D_00583EE8 = 1;
        func_004F4D20(func_0033CC78);
    }
    return D_00767AA0;
}
