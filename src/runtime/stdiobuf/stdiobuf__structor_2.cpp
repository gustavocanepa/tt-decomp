typedef int s32;

extern void *D_005DB608;
extern "C" void func_004EC2C8(void *, void *, s32);
extern "C" void filebuf__structor_3(void *, s32);
extern "C" void func_0050E1A8(void *);

struct stdiobuf__structor_2_arg0 {
    char pad0[0x10];
    void *unk10;
    char pad14[0x3C];
    void *unk50;
};

extern "C" void stdiobuf__structor_2(void *arg0, s32 arg1) {
    ((struct stdiobuf__structor_2_arg0 *)arg0)->unk50 = &D_005DB608;
    func_004EC2C8(arg0, ((struct stdiobuf__structor_2_arg0 *)arg0)->unk10, ((s32)*(void **)((char *)arg0 + 0x14) - (s32)*(void **)((char *)arg0 + 0x10)));
    filebuf__structor_3(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
