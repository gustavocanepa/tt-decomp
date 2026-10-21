extern "C" void RaceSoundPlay(void *a, void *b, void *c, float x, float y);

extern "C" void func_0039D148(char *arg0)
{
    int i = 0;
    int *p = (int *)(0x98D0 + arg0);

    while (i < 6) {
        int v;
        i++;
        v = *p;
        p += 2;
        if (v == 0) {
            continue;
        }
        RaceSoundPlay(arg0 + 0x9900, (void *)0x2C, (void *)0x40, 1.0f, 1.0f);
        break;
    }
}
