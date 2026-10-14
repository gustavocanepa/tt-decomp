typedef int s32;

struct Slot { s32 b[0x11]; };
struct Dbl {
    s32 unk0;
    Slot slot[2];
    s32 cur;
    s32 flag;
    Slot *at(s32 i) { return (Slot *)((char *)this + i * 0x44 + 4); }
};

extern "C" void func_002DD458(Dbl *self, Slot *src) {
    self->cur ^= 1;
    *self->at(self->cur) = *src;
    if (self->flag == 0) {
        self->flag = 1;
        *self->at(1 - self->cur) = *self->at(self->cur);
    }
}
