/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Item {
    char pad0[4];
    f32 f4;
    s32 i8;
};

struct Holder {
    s32 pad0[2];
    s32 h8;
};

struct Handle {
    Holder *obj;
};

struct Self {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_001CE3D0(void *, s32);
extern "C" void func_001CE5A8(void *, f32, f32);
extern "C" void func_003EEB10(s32);
extern "C" void func_003EEC90(void *);
extern "C" void func_003EECA0(void *, s32, s32);
extern "C" void func_003EFF48(void *, s32, s32, s32, f32, f32);
extern "C" f32 func_003F1740(void *, s32);
extern "C" f32 func_003F17D0(void *, s32);
extern "C" s32 func_00421C40(s32);
extern "C" s32 func_00421C68(s32);
extern "C" void func_0041A170(f32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_0046F470(s32);
extern "C" void func_0046F498(s32);
extern "C" void func_00478C98(s32);

extern "C" void mModelSetPS2__virtual_10(Self *self, Handle *h, s32 arg2) {
    char buf[0x10];
    s32 s0;
    Item *it;
    f32 f20;
    s0 = h->obj->h8;
    if (self->unk8 == 0 || s0 == 0) {
        func_001CE3D0(h, 2);
        return;
    }
    func_003EEB10(s0);
    func_003EEC90(buf);
    func_003EECA0(buf, self->unk8, s0);
    it = (Item *)((char *)h->obj + 0x10);
    f20 = func_003F1740(buf, it->i8);
    func_001CE5A8(it, f20, func_003F17D0(buf, it->i8));
    func_0041A170(1.0f);
    func_00421C40(1);
    func_00421C68(0);
    func_0046F0F8(0xF);
    func_0046F498(arg2 != 0);
    func_0046F470(2);
    func_003EFF48(buf, it->i8, 0, 0, it->f4, 0.0f);
    func_00478C98(0xF);
    func_001CE3D0(h, 2);
}
