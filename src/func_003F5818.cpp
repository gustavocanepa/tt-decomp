typedef int s32;
typedef unsigned char u8;

extern "C" void func_003F58A8(void *p);
extern "C" void func_003F58E8(void *p);
extern "C" void func_003F5A80(void *p, s32 n);
extern "C" void func_0046F0F8(s32 n);
extern "C" void func_004702D8(s32 n, float f);

struct S42E160 {
    s32 m0;
    s32 m4;
    u8 m8;
    u8 m9;
    u8 mA;
};

extern "C" void func_003F5818(struct S42E160 *self) {
    s32 t;
    s32 a1;
    func_0046F0F8(6);
    func_004702D8(0x44, 0.0f);
    t = self->m8;
    switch (t) {
    case 1:
        func_003F58A8(self);
        break;
    case 2:
    case 3:
    case 4:
        func_003F58E8(self);
        break;
    default:
        return;
    }
    if (self->mA != 0) {
        a1 = self->m4;
    } else {
        a1 = self->m0;
    }
    func_003F5A80(self, a1);
}
