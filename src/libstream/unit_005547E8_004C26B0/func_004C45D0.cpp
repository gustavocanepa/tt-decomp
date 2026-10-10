/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry_00559CC8 {
    char data[0x18];
};

extern "C" Entry_00559CC8 D_0059C018[8];
extern "C" s32 func_004C4270(Entry_00559CC8 *e);

extern "C" Entry_00559CC8 *func_004C45D0(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_004C4270(&D_0059C018[i])) {
            return &D_0059C018[i];
        }
    }
    return 0;
}
