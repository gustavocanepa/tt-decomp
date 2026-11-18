#include "types.h"

extern "C" void func_004A6500(void *dst, const char *fmt, s32 arg);
extern "C" s32 func_0045DC50(void *globalObj, const char *path, s32 *outObj, s32 flag);

extern "C" char D_005840A0[];

extern "C" void func_00357310(s32 arg0) {
    char buf[0x80];
    s32 obj;

    func_004A6500(buf, "image/%s.png", arg0);
    obj = 0;
    if (func_0045DC50(D_005840A0, buf, &obj, 0) == 0) {
        obj = 0;
        func_0045DC50(D_005840A0, "image/00no_texture.png", &obj, 0);
    }
}
