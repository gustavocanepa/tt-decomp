#include "types.h"

struct List;

struct Tmp {
    s32 w[4];
};

extern "C" s32 func_003C7FF8(List *, s32);
extern "C" void func_003C7FD0(Tmp *, s32);
extern "C" s32 DisplayRText__getRTextStr(Tmp *);

extern "C" s32 func_003C8058(List *list, s32 index) {
    s32 n = func_003C7FF8(list, index);
    if (n < 0)
        return 0;
    Tmp t;
    func_003C7FD0(&t, n % 13);
    return DisplayRText__getRTextStr(&t);
}
