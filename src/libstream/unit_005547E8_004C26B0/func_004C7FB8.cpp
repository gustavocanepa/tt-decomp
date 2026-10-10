/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Clock {
    float time;
    float rate;
    s32 unk8;
    s32 unkC;
};

extern float D_005A0498;

extern "C" void func_004C7FB8(Clock *c, s32 hz, s32 now, s32 prev) {
    float k = 1000.0f / (D_005A0498 * (float)hz);
    float d = (float)(now - prev);
    c->time += d;
    c->unkC = 0;
    c->rate = d * k;
}
