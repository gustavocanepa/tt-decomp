/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

s32 func_004C9AB8(void *dev, s32 reg);

s32 func_004C9B10(void *dev, s32 index) {
    s32 reg = index * 2;
    s32 lo = func_004C9AB8(dev, reg);
    s32 hi = func_004C9AB8(dev, reg + 1);
    return lo | (hi << 16);
}
