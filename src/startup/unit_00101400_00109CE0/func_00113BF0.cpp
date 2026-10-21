typedef int s32;
struct P8 { char pad[8]; char **f8; };
struct Mid { char pad[0x60]; P8 *f60; char pad1[0x70 - 0x64]; void *f70; };
struct Self { char pad[0x6C]; Mid *mid; };
extern "C" void func_003761D0(void *);
extern "C" s32 func_0040BE90(void *, long);
extern "C" s32 func_0040D3D8(void *, s32);
extern "C" long func_0040EFA8(void *, s32);
extern "C" long func_0040F000(void *, s32);

extern "C" void func_00113BF0(Self *arg0) {
    Mid *m = arg0->mid;
    void *spec = m->f70;
    long a = func_0040EFA8(spec, 0);
    long b = func_0040F000(spec, 0);
    if (b != -1) b -= 1;
    else b = 0;
    char *obj = *m->f60->f8 + 0xFD8;
    func_0040BE90(obj, a);
    func_0040D3D8(obj, (int)b);
    func_003761D0(m);
}
