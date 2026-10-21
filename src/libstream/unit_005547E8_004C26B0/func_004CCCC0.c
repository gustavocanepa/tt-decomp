#include "types.h"

extern s32 D_005A0800;
extern s32 D_005A0804;
extern s32 func_004CC568(s32 count);
extern void func_004CC668(u32 count);
extern void func_004BAFD0(void);
extern void func_004BB080(void);
extern s32 func_004CCE98(void);

s32 func_004CCCC0(void) {
    /* The sequence header begins with 12-bit horizontal and vertical sizes. */
    s32 *horizontalSize = &D_005A0800;
    s32 *verticalSize = &D_005A0804;

    *horizontalSize = func_004CC568(12);
    *verticalSize = func_004CC568(12);
    /* Aspect ratio, frame rate, bitrate, marker, VBV size, and constrained flag. */
    func_004CC568(4);
    func_004CC568(4);
    func_004CC568(18);
    func_004CC668(1);
    func_004CC568(10);
    func_004CC568(1);
    /* Optional intra and non-intra quantizer matrices. */
    if (func_004CC568(1) != 0)
        func_004BAFD0();
    if (func_004CC568(1) != 0)
        func_004BB080();
    return func_004CCE98();
}
