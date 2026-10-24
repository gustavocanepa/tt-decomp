/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void RaceMessageDisplay__setMessage(void *, const char *, float, float);
extern "C" void RaceMessageDisplay__clear(void *);
extern "C" void RaceMessageDisplay__show(void *, float, float);
extern "C" void RaceEventDisplay__clear(void *, float);
extern "C" void RaceEventDisplay__addEvent(void *, const char *, float, float, float, float);
extern "C" void func_00352060(char *self, const char *text, float time) {
    char *p = self + 0x2A2C;
    if (text != 0) {
        RaceMessageDisplay__clear(p);
        RaceMessageDisplay__setMessage(p, text, 0.0f, 0.0f);
        *(float *)(p+0x18) = 0.25f;
        *(float *)(p+0x1C) = 0.25f;
        RaceMessageDisplay__show(p, time, 0.0f);
        if (*(int *)(self+0x4C) == 0) {
            char *q = self + 0x44B4;
            RaceEventDisplay__clear(q, 0.1f);
            RaceEventDisplay__addEvent(q, text, time, 0.1f, 0x1.999998p-3f, 0x1.999998p-3f);
        }
    }
}
