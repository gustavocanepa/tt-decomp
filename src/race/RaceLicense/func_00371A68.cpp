/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct VEntI { s16 off; s16 pad; s32 (*fn)(void *); };

struct Self {
    char pad0[0x64];
    char *unk64;
};

struct Out {
    s32 unk0;
    s32 unk4;
    f32 eye[3];
    f32 center[3];
    f32 up[3];
    s32 unk2C;
    f32 unk30;
};

extern "C" void LicenseConcourse__computeCamera(void *);
extern "C" s32 LicenseConcourse__isAvailableCamera(void *);
extern "C" s32 LicenseConcourse__isAvailableFov(void *);
extern "C" f32 func_003CA048(void *, s32);
extern "C" f32 LicenseConcourse__getCenter(void *, s32);
extern "C" f32 LicenseConcourse__getUp(void *, s32);
extern "C" f32 func_003CA078(void *);

extern "C" s32 func_00371A68(Self *self, void *arg1, Out *out) {
    VEntI *v = (VEntI *)(self->unk64 + 0x490);
    s32 ok = v->fn((char *)self + v->off);
    if (ok) {
        char *c = (char *)self + 0x3A8C0;
        LicenseConcourse__computeCamera(c);
        out->unk0 = 0;
        out->unk4 = LicenseConcourse__isAvailableCamera(c);
        out->unk2C = LicenseConcourse__isAvailableFov(c);
        if (out->unk4) {
            for (s32 i = 0; i < 3; i++) {
                out->eye[i] = func_003CA048((char *)self + 0x3A8C0, i);
                out->center[i] = LicenseConcourse__getCenter((char *)self + 0x3A8C0, i);
                out->up[i] = LicenseConcourse__getUp((char *)self + 0x3A8C0, i);
            }
        }
        if (out->unk2C) {
            out->unk30 = func_003CA078((char *)self + 0x3A8C0);
        }
        return 1;
    }
    out->unk0 = -1;
    out->unk4 = 0;
    out->unk2C = 0;
    return ok;
}
