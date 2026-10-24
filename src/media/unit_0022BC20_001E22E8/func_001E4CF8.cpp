struct Obj { char pad[0x1D4C]; unsigned int ticks; };
extern "C" float func_001E4CF8(Obj *self, float period) {
    if (period <= 0.016666666f) return 1.0f;
    unsigned int n = self->ticks % (unsigned int)(int)(period * 60.0f);
    return ((float)n / 60.0f) / period;
}
