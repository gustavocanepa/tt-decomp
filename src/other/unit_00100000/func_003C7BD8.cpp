typedef int s32;

struct Obj_00407648 {
    char pad0[0x10];
    void *m10;
    char pad14[0x24 - 0x14];
    s32 m24;
};

extern "C" void *func_00357310(const char *name);
extern "C" void func_00391980(Obj_00407648 *obj, s32 arg);
extern "C" char D_005F8638[];

extern "C" void func_003C7BD8(Obj_00407648 *arg0, s32 arg1) {
    if (arg0->m10 == 0) {
        arg0->m10 = func_00357310(D_005F8638);
        arg0->m24 = 0;
    }
    func_00391980(arg0, arg1);
}
