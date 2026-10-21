/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;

struct Ent {
    char pad0[4];
    u16 a;
    u16 b;
};

struct A {
    char pad0[0x24];
    u16 count;
    char pad1[0x26];
    Ent *ents;
};

struct B {
    char pad0[0xC];
    char *p0C;
    char *p10;
    s32 f14;
    short f18;
};

extern "C" void func_0041FBE0(A *, B *, s32, s32);
extern "C" void func_00422678(A *, s32, B *);
extern "C" void *func_004F6678(void *, int, unsigned int);

extern "C" void func_0041FAC8(A *arg0, B *arg1, s32 arg2, s32 arg3)
{
    s32 i = 0;
    arg1->f14 = 0;
    arg1->f18 = 0;
    if (arg0->count != 0) {
        do {
            Ent *e = &arg0->ents[i];
            i += 1;
            func_004F6678((void *)(e->b * 4 + (s32)arg1->p0C), 0, e->a * 4);
        } while (i < (s32)arg0->count);
    }
    func_00422678(arg0, 0, arg1);
    func_004F6678(arg1->p10, 0, arg0->count * 4);
    func_0041FBE0(arg0, arg1, arg2, arg3);
}
