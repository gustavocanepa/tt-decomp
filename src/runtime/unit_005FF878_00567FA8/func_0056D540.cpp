/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sampling {
    int factor[4][2];
};

struct O {
    char pad[0xC];
    struct Sampling sampling;
};

extern "C" int func_0056D540(struct O *o, int i) {
    struct Sampling *s = &o->sampling;
    return s->factor[i][0] * s->factor[i][1];
}
