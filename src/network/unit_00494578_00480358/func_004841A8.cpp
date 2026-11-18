/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Obj {
    char pad0[4];
    int f4;
    char pad8[8];
    int f10;
    u16 *p14;
};
extern "C" void func_00483DA8(Obj *, void *, int) throw();
extern "C" int func_004A6448(const char *, ...) throw();
extern "C" void *func_0050E130(int);
extern "C" void func_0050E1A8(void *) throw();

extern char D_00605B08[], D_00605B18[], D_00605B20[], D_00605B28[], D_00605B30[], D_00605B38[];

static inline int len16(const u16 *p) {
    int n = 0;
    if (*p) {
        const u16 *cursor = p;
        do {
            cursor++;
            n++;
        } while (*cursor);
    }
    return n;
}

extern "C" void func_004841A8(Obj *o) {
    int n = 0;
    void *buf = func_0050E130(o->f4 * 2);
    func_00483DA8(o, buf, o->f4);
    func_004A6448(D_00605B08, o->f10, buf);
    n = len16(o->p14);
    int i;
    for (i = 0; i < n; i++) {
        if (i == o->f10) func_004A6448(D_00605B18);
        func_004A6448(D_00605B20, o->p14[i] & 0x7F);
    }
    if (o->f10 == n) func_004A6448(D_00605B18);
    for (i = 0; i < len16(o->p14); i++) {
        unsigned int bits = o->p14[i];
        if ((bits >> 7) & 1) {
            func_004A6448(D_00605B28);
        } else {
            func_004A6448(D_00605B30);
        }
    }
    func_004A6448(D_00605B38);
    func_0050E1A8(buf);
}
