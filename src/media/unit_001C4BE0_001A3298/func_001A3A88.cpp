#include "types.h"
struct Image { char *start; char *finish; };
struct Hdr { char pad0[8]; u32 flags; };
extern "C" void *func_004F64C4(void *, const void *, unsigned int);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void func_001A3950(Image *img, short *dst);
extern "C" u32 func_001A3DB0(void *dst, void *src);
extern "C" void func_004A45D0(void *);
extern "C" short *func_004AE6D8(s32);

extern "C" s32 func_001A3A88(Image *img, Hdr *dst, char *src) {
    s32 n = img->finish - img->start;
    char *start = img->start;
    if ((char *)dst != start) {
        memcpy(dst, start, n);
    }
    char *end = (char *)dst + n;
    u32 *fl = &dst->flags;
    *fl &= ~8;
    short *buf = func_004AE6D8(0x8000);
    func_001A3950(img, buf);
    for (s32 i = 0; i < 64; i++) {
        memcpy((char *)buf + i * 0x100, src + i * 0x80, 0x80);
    }
    u32 r = func_001A3DB0(end, buf);
    if (r > 0x7FFF) {
        r = 0x8000;
        func_004F64C4(end, buf, 0x8000);
    } else {
        *fl |= 8;
    }
    func_004A45D0(buf);
    return n + r;
}
