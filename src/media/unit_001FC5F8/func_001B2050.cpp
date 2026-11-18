/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0xC0]; int width, height, pw, ph, mode; };
extern "C" void func_001B2050(S *s, int w, int h) {
    s->height = h;
    s->width = w;
    s->pw = 1;
    if (s->pw < w) do {
        int v = s->pw * 2;
        s->pw = v;
        if (v >= 0x400) break;
    } while (s->pw < s->width);
    float height;
    if (s->mode == 1) height = (float)(s->height / 2);
    else height = (float)s->height;
    s->ph = 1;
    if (!(height <= (float)s->ph)) do {
        int v = s->ph * 2;
        s->ph = v;
        if (v >= 0x400) break;
    } while (!(height <= (float)s->ph));
}
