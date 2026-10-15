/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Obj { char pad[4]; void *unk4; };
struct Ent { char pad[0xB]; u8 unkB; };
extern "C" void func_00487968(void *l, void *b) throw();
extern "C" char *func_00488380(char *a, s32 b) throw();
extern "C" s32 func_00488D20(void *a, s32 b, s32 c, void *d, void *e) throw();
extern "C" s32 func_00488FF0(Obj *arg0, char *arg1, s32 arg2) {
    void *sp0;
    Ent *sp4;
    s32 r = 0;
    u8 flags = 0;
    char *cur = arg1;
    char *p;
    for (;;) {
        p = func_00488380(cur, arg2);
        if (!p) return -0x5B;
        if (*p == 0) {
            if (r == 0) return 0;
            return (flags & 0x10) ? r : -0x14;
        }
        r = func_00488D20(arg0, r, arg2, &sp0, &sp4);
        if (r < 0) return r;
        flags = sp4->unkB;
        func_00487968(arg0->unk4, sp0);
        cur = p;
    }
}
