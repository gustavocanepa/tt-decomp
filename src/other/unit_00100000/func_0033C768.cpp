typedef int s32;

struct Obj0038A098 {
    char pad[0xCE4];
    char pad2[0xDDC - 0xCE4];
    s32 unkD18;
};

extern "C" void func_004AEBD8(void *arg0);
extern "C" void func_00100BC0(struct Obj0038A098 *arg0);

extern "C" void func_0033C768(struct Obj0038A098 *arg0, s32 arg1) {
    arg0->unkD18 = arg1;
    func_004AEBD8((char *)arg0 + 0xDA8);
    func_00100BC0(arg0);
}
