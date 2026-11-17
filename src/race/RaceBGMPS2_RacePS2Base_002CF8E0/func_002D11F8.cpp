#include "types.h"

/* Draws a texture through a temporary draw state, like its neighbour func_0033E520: the state at sp
   (constructed by func_0038B758, scaled by fp0 with aspect 1.333, offset by fp1/fp2) and a texture
   copy of `dst` sized w x h/2. When `src` and `dst` share the same id the plain copy
   (func_0038B8D8) is used, otherwise the blended one (func_0038BD20) with a zero blend. The
   meaning of the fields is inferred from the callees; the first parameter is unused. */

struct Surface {
    s32 id;
    s32 pad4;
    s32 width;
    s32 height;
};

extern "C" void func_00104868(void *, s32);
extern "C" void *func_001048C8(void *, s32, s32, s32);
extern "C" void func_0038B758(void *);
extern "C" void func_0038B818(void *, float, float);
extern "C" void func_0038B848(void *);
extern "C" void func_0038B8D8(void *, void *, void *, void *, void *, float, float, float);
extern "C" void func_0038BD20(void *, void *, void *, void *, void *, float, s32, float, float, float);
extern "C" void func_0046F0F8(s32);
extern "C" void func_00478C98(s32);

extern "C" void func_002D11F8(void *self, Surface *src, void *view, Surface *dst, float scale, float x, float y) {
    char state[0xC0];
    char copy[0x40];
    func_0038B758(state);
    func_0046F0F8(5);
    func_00478C98(6);
    func_001048C8(copy, 1, dst->width, dst->height / 2);
    func_0038B818(state, scale, 0x1.553f7c0000000p+0f); /* 4:3 aspect */
    *(float *)(state + 8) = x;
    *(float *)(state + 0x10) = y;
    func_0038B848(state);
    if (src->id == dst->id)
        func_0038B8D8(state, src, dst, view, copy, 1.0f, 1.0f, 1.0f);
    else
        func_0038BD20(state, src, dst, view, copy, 0.0f, 0, 1.0f, 1.0f, 1.0f);
    func_00104868(copy, 2);
    func_00104868(state + 0x2C, 2);
}
