/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x1e];
    unsigned char mode;
    char pad1[5];
    float a;
    float b;
    char pad2[0x14];
    signed char result;
    signed char flag;
    char pad3[0xa6];
    char *data;
};
extern "C" void func_004367E8(Obj *) throw();
extern "C" int func_003146C8(char *, float);
static inline float minimum(float value, float other) {
    if (!(value < other)) value = other;
    return value;
}
extern "C" void func_004367F8(Obj *self) {
    char *data = self->data;
    func_004367E8(self);
    char *p = data + 0x104;
    float limit;
    float current;
    switch (self->mode) {
    case 3:
        current = *(float *)(p + 0x55C);
        limit = self->b;
        goto compare;
    case 4: {
        current = self->b;
        float other = self->a;
        limit = minimum(current, other);
        current = *(float *)(p + 0x55C);
        break;
    }
    default:
        current = *(float *)(p + 0x55C);
        goto fallback;
    }
compare:
    if (current < limit) return;
    self->flag = 1;
    goto call;
fallback:
    limit = self->b;
    if (current < limit) return;
call:
    self->result = func_003146C8(data, limit);
}
