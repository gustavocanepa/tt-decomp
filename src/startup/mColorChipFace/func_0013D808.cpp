/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
struct Obj {
    char pad0[0xC4];
    s16 unkB0;
    char padB2[2];
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    u32 unkC0[4];
    char padD0[4];
    char unkD4[8];
};
extern "C" void func_0013D718(void *arg0) throw();
extern "C" void *func_00408B58(void *arg0);
extern "C" s32 func_0040D360(void *arg0);
extern "C" s8 func_0040D420(void *arg0);
extern "C" s32 func_0040D680(void *self, s32 key, s32 *out);
extern "C" void func_004F6678(void *dst, int v, int n);
extern "C" void *func_001324D8(void *);

extern "C" void func_0013D808(Obj *self, void *arg1, s32 idx) {
    s32 col[4];
    s32 n;
    s32 m;
    int i;
    void *h;
    func_004F6678(self->unkD4, 0, 8);
    h = func_001324D8(arg1);
    if (idx < 0) idx = func_0040D420(func_00408B58(h));
    m = func_0040D360(func_00408B58(h));
    if (idx >= m) idx = m - 1;
    if (func_0040D680(func_00408B58(h), idx, col) != 0) {
        n = 0;
        for (i = 0; i < 4; i++) {
            if (col[i] & 0x01000000) n++;
        }
        if (n > 0) {
            self->unkB0 = n;
            int j;
            for (j = 0; j < 4; j++) {
                self->unkC0[j] = (col[j] & 0xFFFFFF) | 0xFF000000;
            }
            self->unkB8 = (col[0] >> 25) & 1;
            self->unkB4 = (col[0] >> 26) & 1;
            self->unkBC = (col[0] >> 27) & 1;
            func_0013D718(self);
        }
    }
}
