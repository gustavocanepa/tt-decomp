/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 {float x,y;};

struct Tmp {
    char raw[0x20];
    float f;
};

typedef void (*VFn)(void *self, void *a1, float f);

extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_0043BA20(void *a, void *b, void *c, float f) throw();
extern "C" void func_0043BAA0(void *a, void *b) throw();

extern "C" void func_00444378(char *arg0, char *arg1) {
    Vec2 *sv = (Vec2 *)(arg1 + 0x6E18);
    Vec2 saved;
    Tmp tmp;

    char *b = arg0 + 8;
    func_00473050();
    float fz = *(float *)(arg1 + 0x6E24);
    saved = *sv;
    func_0043BA20(&tmp, b, arg0 + 0x2C, fz);
    func_0043BAA0(&tmp, arg1);
    char *vt = *(char **)(arg0 + 0x5C) + 0x20;
    short adj = *(short *)vt;
    VFn fn = *(VFn *)(vt + 4);
    fn(arg0 + adj, arg1, tmp.f);
    *sv = saved;
    func_004730A8();
}
