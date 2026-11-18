/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Voice {
    char pad00[0x34];
    int stateIndex;
    char pad38[0x14];
    float accum;
    char pad50[0x10];
    int state;
};
typedef void (Voice::*Handler)();
extern Handler D_006135D8[];
extern "C" unsigned long func_004C5208(Voice *);
extern "C" int func_004C5DD8(Voice *v) {
    (v->*D_006135D8[v->stateIndex >> 4])();
    int done = 0;
    if (v->state != 3) {
        v->accum += (float)func_004C5208(v);
    } else {
        done = 1;
    }
    return done;
}
