typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj1 {
    char pad[0xDC];
    s32 unkDC;
};

struct Obj0 {
    Obj1 *first;
};

struct Stk {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
};

extern char D_005CFB28[];

extern "C" s32 func_002F04D8(s32 arg0, s32 arg1);
extern "C" s32 func_00305C80(void *a0, void *a1, s32 a2);
extern "C" void RaceDisplayCheckPointEvent__structor_0(void *p);
extern "C" void RaceDisplayEventBase__put(void *o, void *t);
extern "C" void *func_00358B80(void *p);
extern "C" void func_00358CF8(void *p, u32 v);
extern "C" void func_00376780(void *a0, s32 a1, s32 a2, s32 a3);

extern "C" void func_00305CB0(Obj0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Stk st;
    Stk st2;
    Stk *p2;
    s32 v;
    Obj1 *s1;
    s32 s4;
    u8 *q;

    v = func_002F04D8((s32)arg0, arg1);
    q = (u8 *)v + 0x104;
    if (q[0x461] == 0 && q[0x64E] == 0) {
        s1 = arg0->first;
        s4 = func_00305C80(s1, arg0, v) == 0;
        if (s1->unkDC == 0) {
            RaceDisplayCheckPointEvent__structor_0(&st);
            st.w0 = arg1;
            st.w8 = arg2;
            st.wC = arg3;
            RaceDisplayEventBase__put(&st, s1);
            p2 = &st2;
            func_00358B80(p2);
            p2->w4 = (s32)D_005CFB28;
            p2->w0 = arg1;
            func_00358CF8(p2, arg5);
            RaceDisplayEventBase__put(p2, s1);
        }
        if (arg6 == 0 && s4 != 0) {
            func_00376780(s1, arg1, arg3, arg5);
        }
    }
}
