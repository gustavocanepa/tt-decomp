struct Timer {
    int pad0;
    float time;
    char pad8[0xC];
    unsigned char paused;
};

extern char D_00582E98[];
extern "C" float func_002F4F90(void *clock);

extern "C" void func_002E4750(Timer *t, float dt)
{
    if (t->paused == 0) {
        void *clock = D_00582E98;
        t->time += dt;
        if (t->time > func_002F4F90(clock))
            t->time = func_002F4F90(clock);
    }
}
