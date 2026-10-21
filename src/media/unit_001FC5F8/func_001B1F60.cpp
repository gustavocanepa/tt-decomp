typedef int s32;

struct Obj {
    char p0[0x104];
    s32 fD4;
};

extern char D_005E8370[];

extern "C" int func_001D2508(char *dst, unsigned capacity, const char *name, const char *suffix);
extern "C" void func_0047DB20(s32 *self, char *path, s32 mode);
extern "C" void free(s32 arg0);

extern "C" void func_001B1F60(Obj *arg0, const char *arg1) {
    char buf[0x80];
    s32 rec[8];
    s32 *out;
    s32 old = arg0->fD4;
    if (old != 0) {
        arg0->fD4 = 0;
        free(old);
    }
    func_001D2508(buf, 0x80, arg1, D_005E8370);
    out = rec;
    func_0047DB20(out, buf, 1);
    if (out[0] == 0) {
        arg0->fD4 = out[4];
    }
}
