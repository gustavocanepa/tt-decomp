typedef int s32;

extern "C" s32 func_0030FE98(void *);
extern "C" s32 func_0030FEA8(void *);

extern "C" s32 func_0030FEB8(void *o) {
    s32 r = 0;
    if (func_0030FE98(o) || func_0030FEA8(o))
        r = 1;
    return r;
}
