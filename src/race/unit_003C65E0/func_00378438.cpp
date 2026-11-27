#include "types.h"

struct V { s32 w[6]; };
struct Vec { s32 n; V *begin; V *end; };
struct Owner { char pad[0xA8]; s32 fA8; };
struct Node { char pad[4]; s32 *list; };
struct Src { char pad[2]; u16 count; s32 *list; };
struct Slot { s32 a; s32 b; s32 c; Owner *o; };
struct Frame {
    char buf[0x3000];
    s32 cnt;
    s32 pad3004;
    char obj[0x584];
    Owner *owner;
    s32 z;
    char pad3594[0xC];
    Vec v;
    s32 pad35AC;
    char o35B0[0x10];
    s32 s35C0;
    s32 s35C4;
    char pad35C8[8];
    s32 s35D0;
    Owner *s35D4;
};

extern "C" void func_003786E0(s32, void *);
extern "C" void func_0046A6C8(s32, V *, s32, s32, s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" V *func_00473980(s32);
extern "C" void func_00475730(f32);
extern "C" void func_00477E30(f32, f32, f32, f32);
extern "C" void func_00478C98(s32);
extern "C" s32 func_0055B1C0(void *, void *, s32);
extern "C" Owner *func_0055B258(void *);
extern "C" void func_0055B280(void *);
extern "C" void *func_0055B2B8(void *, void *, void *, void *);
extern "C" void func_0055B360(void *, void *);

extern "C" void func_00378438(Src *src, f32 a, f32 b, f32 c, f32 d) {
    Frame f;
    s32 i = 0;
    f.cnt = 0;
    func_0055B280(f.obj);
    f.owner = func_0055B258(f.obj);
    f.z = 0;
    for (i = 0; i < src->count; i++) {
        func_003786E0(src->list[i], &f);
    }
    Vec *pv = &f.v;
    pv->n = f.cnt + src->count * 2 - 4;
    pv->end = pv->begin = func_00473980((pv->n * 0x18 + 0xF) >> 4);
    func_00477E30(a, b, c, d);
    func_00478C98(0xF);
    func_00478C98(2);
    func_0055B1C0(&f, pv, 0x4000);
    func_00473050();
    func_00475730(90.0f);
    func_0046A6C8(((s32 *)f.v.end - (s32 *)f.v.begin) / 6, f.v.begin, 0, 0, 0);
    func_004730A8();
    f.s35D4 = f.owner;
    f.s35C4 = f.owner->fA8;
    func_0055B2B8(f.o35B0, f.obj, &f.s35C0, &f.s35D0);
    func_0055B360(f.obj, f.owner);
}
