#include "types.h"

struct List;

extern List D_00584758;
extern char D_00584778[];

extern "C" s32 *func_00388D68(char *, s32 *);
extern "C" s32 *func_0042FAD8(List *arg0, s32 *arg1);

extern "C" s32 *func_00388FB0(s32 *arg0) {
    if (arg0 != 0) {
        arg0 = func_00388D68(D_00584778, arg0);
        if (arg0 != 0)
            arg0 = func_0042FAD8(&D_00584758, arg0);
    }
    return arg0;
}
