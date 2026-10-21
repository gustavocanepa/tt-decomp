typedef int s32;
struct O { char p0[4]; s32 u4; char p1[0x30]; char u38[0x30]; s32 u68; };
extern "C" void func_00102FB0(void *);
extern "C" void func_001042E0(void);
extern "C" void func_004AEAF8(void *);
extern "C" void func_004AEB30(void *);
extern "C" void func_004A45D0(int);
extern "C" void func_001027A0(O *a) {
    while (a->u4) {
        func_004AEAF8((char *)a + 8);
        if (!a->u4) break;
        func_00102FB0(a);
        func_004A45D0(a->u68);
        a->u68 = 0;
        func_001042E0();
        func_004AEB30(a->u38);
    }
    func_004AEB30(a->u38);
}
