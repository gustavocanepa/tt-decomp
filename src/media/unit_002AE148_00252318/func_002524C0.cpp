typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_00251678(void *, void *) throw();
extern "C" void func_00251620(void *, s32) throw();
extern "C" s32 func_00257668(s32, s32, s32);
extern "C" void func_002A7578(void *, void *);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_001DF1C8(void *, void *);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

extern "C" void func_002524C0(s32 *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 h1[4];
    s32 buf2[4];
    s32 h3[4];
    s32 t[4];
    if (arg2 == 1) {
        func_00251678(buf0, arg1);
        char *obj = (char *)arg3[0];
        s32 v_s0 = buf0[0];
        s32 *pt = t;
        t[0] = func_00257668(v_s0, vcall_58(obj), 0);
        s32 *p = h1;
        func_002A7578(p, pt);
        if (arg0 != p) {
            s32 nv = p[0];
            if (nv != 0)
                func_002C0FE8(nv);
            if (arg0[0] != 0)
                func_002C1050(arg0[0]);
            arg0[0] = nv;
        }
        func_002A75A8(p, 2);
        func_00251620(buf0, 2);
    } else if (arg2 == 2) {
        func_00251678(buf0, arg1);
        s32 *q = &t[1];
        *q = arg3[1];
        s32 *b2 = buf2;
        func_001DF1C8(b2, q);
        char *obj = (char *)arg3[0];
        s32 v_s0 = buf0[0];
        s32 *pt = &t[2];
        *pt = func_00257668(v_s0, vcall_58(obj), b2[0]);
        s32 *p = h3;
        func_002A7578(p, pt);
        if (arg0 != p) {
            s32 nv = p[0];
            if (nv != 0)
                func_002C0FE8(nv);
            if (arg0[0] != 0)
                func_002C1050(arg0[0]);
            arg0[0] = nv;
        }
        func_002A75A8(p, 2);
        func_001DF1F8(b2, 2);
        func_00251620(buf0, 2);
    }
}
