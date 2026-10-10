typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_001693C0(struct Buf00109C40 *arg0);
extern "C" void func_003F82A0(s32 arg0);
extern "C" void func_00169368(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00169E20(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_001693C0(&buf);
    p = buf.ptr;
    func_003F82A0(p->unk10);
    func_00169368(&buf, 2);
}
