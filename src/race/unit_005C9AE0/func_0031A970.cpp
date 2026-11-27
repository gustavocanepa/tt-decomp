/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { long w[8]; } __attribute__((aligned(8)));
extern "C" void func_0031A970(char *self, const Blk *src, float f) {
    Blk *dst = (Blk *)(self + 0xA80);
    *dst = *src;
    *(float *)((char *)dst + 0x40) = f;
}
