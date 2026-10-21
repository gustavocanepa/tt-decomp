typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_0020B998(void *self, s32 arg1, void *arg2);
extern "C" s32 mListBox__is_left(void *self, s32 key);
extern "C" s32 func_00254148(void *self, s32 key);

extern "C" s32 func_00255E28(void *arg0, s32 arg1, void *arg2) {
    s32 r;

    r = func_0020B998(arg0, arg1, arg2);
    if (r == 0) {
        s32 key = *(s32 *)((char *)arg2 + 0x20);
        if (mListBox__is_left(arg0, key) != 0 || func_00254148(arg0, key) != 0) {
            r = 1;
            *(s32 *)((char *)arg0 + 0x15C) = *(s32 *)((char *)arg0 + 0x14C);
        }
    }
    return r;
}
