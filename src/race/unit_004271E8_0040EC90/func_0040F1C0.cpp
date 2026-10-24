/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Db { char p[0x1EC]; int f1E4; };
struct Self { char pad[0xA8]; u32 key; };
extern Db D_00585A30;
extern "C" int func_0040B940(void *, int, int, void *);
extern "C" void func_00411D78(int, int);

extern "C" void func_0040F1C0(Self *self) {
    int buf[4];
    unsigned long u = self->key;
    if (func_0040B940(&D_00585A30, (int)u, 0x28, buf) != 0) {
        func_00411D78(D_00585A30.f1E4, buf[0]);
    }
}
