typedef int s32;

extern s32 func_00408B58(s32 a);
extern s32 func_0040D380(s32 a);

s32 func_001316F0(void *arg0) {
    return func_0040D380(func_00408B58(*(s32*)((char*)arg0 + 0x14)));
}
