struct Inner { char pad[0x44]; int f2c; };
struct S { int a0, a4, a8, aC, a10, a14, a18, a1C, a20, a24; };
extern Inner *D_00586EF4;
extern "C" int func_00439930(S *s) {
    s->a0 = 0;
    s->a4 = 0;
    s->a8 = 0;
    s->aC = 0;
    s->a10 = 0;
    s->a14 = 0;
    s->a18 = 1;
    s->a1C = 0;
    s->a20 = 2;
    s->a24 = 0x80;
    D_00586EF4->f2c = 1;
}
