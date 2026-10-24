/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
struct StickBone {
    s128 m0;
    s128 m10;
    s32 vtbl;
    char pad24[0xC];
    s128 m30;
    f32 m40;
    f32 m44;
};
extern char D_005D7238[];
extern "C" void func_0055FA30(StickBone *self, const StickBone *src) {
    self->m0 = src->m0;
    self->m10 = src->m10;
    self->vtbl = (s32)D_005D7238;
    self->m30 = src->m30;
    self->m40 = src->m40;
    self->m44 = src->m44;

}
