#include "types.h"
struct Self { s64 q[0x1F]; };
struct Info { s64 q[0x1A]; };
extern char D_00585A30[];
extern "C" int func_0040B980(void *, s64);
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(void *, s64, void *);
extern "C" void func_0040BCF0(void *);
extern "C" s32 func_0040C410(void *);
extern "C" s64 func_0040D308(void *);
extern "C" s32 func_0040AC98(void *);
extern "C" s32 func_0040BED0(Self *self, s64 id) {
    s64 ref[4];
    Info info;
    s32 res = func_0040B980(D_00585A30, id);
    if (res != 0) {
        SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, id, ref);
        if (ref[0] == -1 || !func_0040B980(D_00585A30, ref[0])) return 0;
        SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, ref[0], &info);
        func_0040BCF0(self);
    self->q[4] = info.q[0];
    self->q[5] = info.q[1];
    self->q[0] = id;
    self->q[6] = info.q[5];
    self->q[7] = info.q[11];
    self->q[8] = info.q[9];
    self->q[9] = info.q[10];
    self->q[10] = info.q[2];
    self->q[11] = info.q[23];
    self->q[12] = info.q[24];
    self->q[13] = info.q[25];
    self->q[14] = info.q[8];
    self->q[15] = info.q[7];
    self->q[16] = info.q[6];
    self->q[17] = info.q[14];
    self->q[18] = info.q[15];
    self->q[1] = -1;
    self->q[19] = info.q[16];
    self->q[20] = info.q[17];
    self->q[21] = info.q[12];
    self->q[22] = info.q[13];
    self->q[23] = info.q[21];
    self->q[24] = info.q[20];
    self->q[25] = info.q[22];
    self->q[26] = info.q[19];
    self->q[27] = info.q[18];
    self->q[28] = info.q[3];
    self->q[29] = info.q[4];
    self->q[30] = -1;
        func_0040C410(self);
        s64 r = func_0040D308(self);
        self->q[2] = r;
        if (r == -1) return 0;
        ((char *)self)[0x18] = 0;
        return func_0040AC98(self) != 0;
    }
    return res;
}
