/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Event {
    int lap;
    int pad4;
    int time;
    int point;
};
struct Packed {
    unsigned int lap : 4;
    unsigned int point : 4;
    unsigned int time : 10;
    unsigned int rest : 14;
};
union Word {
    Packed p;
    unsigned int w;
};
extern "C" void RaceDisplayCheckPointEvent__decode(Event *e, unsigned int w) {
    Word u;
    u.w = w;
    e->lap = u.p.lap;
    e->point = u.p.point;
    e->time = u.p.time;
}
