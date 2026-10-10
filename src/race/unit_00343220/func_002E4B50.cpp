struct Timer {
    int pad0[4];
    float time;
    unsigned char paused;
};

extern char D_00583690[];
extern "C" float func_0030E650(void *clock);

extern "C" void func_002E4B50(Timer *t, float dt)
{
    if (t->paused == 0) {
        void *clock = D_00583690;
        t->time += dt;
        if (t->time > func_0030E650(clock))
            t->time = func_0030E650(clock);
    }
}
