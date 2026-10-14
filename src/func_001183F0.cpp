/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

struct Sample {
    u16 gear : 3;
    u16 rpm : 13;
    u8 b2;
    u8 b3;
    s16 h4;
    s16 h6;
};

struct Log {
    char pad0[0x30];
    Sample *buf;
    s32 *cnt;
};

extern "C" void func_001183F0(Log *self) {
    s32 i = 1;
    u32 p0 = self->buf[0].rpm;
    u32 p2 = self->buf[0].b2;
    u32 p3 = self->buf[0].b3;
    while (i < *self->cnt - 1) {
        s32 off = i * 8;
        i++;
        Sample *s = (Sample *)(off + (s32)self->buf);
        Sample *n = s + 1;
        u32 c0 = s->rpm;
        u32 c2 = s->b2;
        u32 n3 = n->b3;
        u32 n2 = n->b2;
        s->rpm = (p0 + c0 * 2 + n->rpm) >> 2;
        u32 c3 = s->b3;
        ((Sample *)(off + (s32)self->buf))->b2 = (p2 + c2 * 2 + n2) >> 2;
        ((Sample *)(off + (s32)self->buf))->b3 = (p3 + c3 * 2 + n3) >> 2;
        p0 = c0;
        p2 = c2;
        p3 = c3;
    }
}
