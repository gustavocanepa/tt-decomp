typedef int s32;

struct Resource;

extern "C" void func_00473498(void *self);
extern "C" void func_00104BA8(Resource *self);
extern "C" void func_004780F8(void);
extern "C" void func_00465EF8(char *self, s32 arg1);

extern "C" void func_003908A0(char *arg0) {
    func_00473498(arg0);
    func_00104BA8((Resource *)(arg0 + 0xC8));
    s32 v = *(s32 *)(arg0 + 0x8);
    *(s32 *)(arg0 + 0xA08) = v;
    if (v == 0 && *(s32 *)(arg0 + 0xA34) == 0 && *(s32 *)(arg0 + 0x1848) == 0) {
        return func_00104BA8((Resource *)(arg0 + 0x8C));
    }
    func_004780F8();
    func_00465EF8(arg0, *(s32 *)(arg0 + 0x104));
    func_00104BA8((Resource *)(arg0 + 0x8C));
}
