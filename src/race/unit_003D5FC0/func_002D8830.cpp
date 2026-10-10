typedef int s32;

extern "C" s32 func_002D7F98(void *) throw();
extern "C" s32 func_002D8D80(void *);
extern "C" s32 func_002D8DA8(void *);
extern "C" s32 func_002D8DD0(void *);
extern "C" s32 func_002D8E28(void *);
extern "C" s32 func_003EB020(s32);

extern "C" void func_002D8830(char *self, s32 id) {
    s32 flags;
    s32 state;

    flags = func_003EB020(id);
    if (flags & 0x3000C) {
        state = 3;
        if (func_002D7F98(self) != 0) {
            if (flags & 4) {
                state = (func_002D8DA8(self) != 0) ? 2 : 3;
            }
            if (flags & 8) {
                state = (func_002D8D80(self) != 0) ? 2 : state;
            }
            if (flags & 0x10000) {
                state = (func_002D8DD0(self) != 0) ? 6 : state;
            }
            if (flags & 0x20000) {
                state = (func_002D8E28(self) != 0) ? 6 : state;
            }
        }
        *(s32 *)(self + 0x9C) = state;
    }
}
