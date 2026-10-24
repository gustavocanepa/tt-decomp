/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Hit {
    float pos[3];
    float dist;
    int flag;
    int *src;
};

struct Probe {
    char pad0[0x10];
    float f10;
    char pad14[4];
    float f18;
    char pad1C[0x28 - 0x1C];
    float f28;
    float f2C;
    char pad30[0x3C - 0x30];
};

struct World {
    char pad0[0xA30];
    int skip;
    char padA34[0x1848 - 0xA34];
    int count;
    Hit hits[100];
    char pad[0x222C - 0x184C - 100 * 0x18];
    Probe probes[1];
};

extern "C" int func_0038FCF0(World *w, float *a, float *b, int *src, float x, float y);
extern "C" float func_0038FE30(World *w, float *a, int *src, float x);
extern "C" int func_0038FF40(World *w, float *b, float x, float y);

extern "C" void func_0038FBC8(World *w, int *src)
{
    float a[4];
    float b[4];

    if (w->count < 100) {
        Hit *h = &w->hits[w->count];
        Probe *p = &w->probes[*src];
        if (func_0038FCF0(w, a, b, src + 1, p->f10, p->f28)) {
            float d = func_0038FE30(w, a, src + 4, p->f18);
            if (d < 0.0f)
                h->flag = 0;
            else if (w->skip)
                h->flag = 1;
            else
                h->flag = func_0038FF40(w, b, 1.0f, p->f2C);
            h->pos[0] = a[0];
            h->pos[1] = a[1];
            h->pos[2] = a[2];
            h->dist = d;
            h->src = src;
            w->count++;
        }
    }
}
