#include "types.h"

enum PictureType { PredictivePicture = 2, BidirectionalPicture = 3 };

extern s32 D_005A0810;
extern s32 func_004CC568(s32 count);
extern void func_004CC668(u32 count);
extern s32 func_004CCE98(void);

s32 func_004CCDC8(void) {
    s32 *pictureCodingType;

    func_004CC568(10);
    pictureCodingType = &D_005A0810;
    *pictureCodingType = func_004CC568(3);
    func_004CC568(16);

    /* P and B pictures include forward motion-vector fields. */
    if (*pictureCodingType == PredictivePicture ||
        *pictureCodingType == BidirectionalPicture) {
        func_004CC568(1);
        func_004CC568(3);
    }
    /* B pictures also include backward motion-vector fields. */
    if (*pictureCodingType == BidirectionalPicture) {
        func_004CC568(1);
        func_004CC568(3);
    }

    while (func_004CC568(1) != 0)
        func_004CC668(8);
    return func_004CCE98();
}
