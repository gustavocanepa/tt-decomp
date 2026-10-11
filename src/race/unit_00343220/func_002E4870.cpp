struct Timer {
    int f0;
    int f4;
    float t;
    int fC;
    int f10;
    unsigned char paused;
};

extern char D_00582E98[];
extern "C" float func_002F4FB8(void *g);
extern "C" float func_002F4FF0(void *g);

extern "C" void func_002E4870(Timer *tm, float dt)
{
    if (tm->paused) {
        return;
    }
    if (tm->t < 0.0f) {
        tm->t += dt;
        if (tm->t >= 0.0f) {
            tm->t = -func_002F4FB8(D_00582E98);
        }
    } else {
        tm->t += dt;
    }
    if (func_002F4FF0(D_00582E98) < tm->t) {
        tm->t = func_002F4FF0(D_00582E98);
    }
}
