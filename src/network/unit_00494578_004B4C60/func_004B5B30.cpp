/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;

/* A file object followed by the header it reads: two sizes and a name. */
struct Frame {
    char obj[0xD0];
    s32 d0;
    s32 d4;
    s32 d8;
    char name[0x150 - 0xDC];
};
struct Stream {
    s32 handle;
    char pad[0x3C];
    s32 arg0;
    s32 arg1;
    s32 user;
    s32 flags;
    char name[0xB0];
};
struct Status {
    s64 position;
    char pad[0xC];
    s32 busy;
};
extern Stream D_00773FC0;
extern Status D_007740C0;

extern "C" void func_0047F748(void *self);
extern "C" s32 func_0047F340(void *self, void *arg);
extern "C" void func_0047F780(void *self, s32 mode);
extern "C" s32 func_0047F7F8(void *self, void *name, s32 mode);
extern "C" s32 func_0047F880(void *self);
extern "C" void func_004F7B74(char *dst, char *src);
extern "C" s32 func_004F4348(s32 handle);
extern "C" s32 func_004F45D8(void *obj, s32 a1, s32 a2, void *buf, s32 size);

extern "C" void func_004B5B30(void *name, s32 user) {
    Frame f;

    func_0047F748(&f);
    if (func_0047F7F8(&f, name, 3) >= 0) {
        f.d0 = 0;
        if (func_0047F340(&f, &f.d0) != 0) {
            Stream *s;
            do { s = &D_00773FC0; } while (0);
            s32 d4 = f.d4;
            s32 d8 = f.d8;
            s32 flags = 0x40000;
            func_004F4348(s->handle);
            D_007740C0.position = -1;
            D_007740C0.busy = 0;
            s->arg0 = d4;
            s->arg1 = d8;
            s->user = user;
            s->flags = flags;
            s->name[0] = 0;
            func_004F7B74(s->name, f.name);
            func_004F45D8(s, 1, 0, 0, 0);
        }
        func_0047F880(&f);
    }
    func_0047F780(&f, 2);
}
