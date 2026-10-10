extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_0020B408(...) throw();
void func_004A59F0(...) throw();

struct mSceneViewFace__virtual_68_arg0 {
    char pad0[0xB8];
    s32 unkB8;
};

void mSceneViewFace__virtual_68(char *arg0) {
    func_0020B408();
    if (((struct mSceneViewFace__virtual_68_arg0 *)arg0)->unkB8 != 0) {
        do {
            func_004A59F0();
        } while (((struct mSceneViewFace__virtual_68_arg0 *)arg0)->unkB8 != 0);
    }
}

}
