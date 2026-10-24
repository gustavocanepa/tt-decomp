struct O {
    char pad0[0xC];
    int tab[8][8];   /* at 0xC, accessed from 0x2C below */
};
extern "C" int func_0045D1D0(void *);
extern "C" float func_004A5C50(float);
extern "C" int func_0045A880(void *);
extern char D_005DA238[];

struct Obj {
    char pad[0xC];
    char col[0x20];
    int tab[8][8];
};

extern "C" int func_0045A6A0(Obj *o) {
    int n = 2;
    char *p = (char *)o + 0x12C;
    *(char **)((char *)o + 0xA7C) = D_005DA238;
    do {
        char *q = p;
        p += 0x108;
        n--;
        func_0045D1D0(q);
    } while (n != -1);
    *(int *)((char *)o + 0xA68) = 0;
    int i = 0;
    int *colp = (int *)((char *)o + 0xC);
    do {
        int j = 0;
        int *dst = colp + 8;
        do {
            float t = (float)j;
            j++;
            float v = func_004A5C50(((t + t) + 1.0f) * (float)i * 0x1.921fb4p-3f);
            *dst = (int)(v * 32768.0f);
            dst += 8;
        } while (j < 8);
        i++;
        colp += 1;
    } while (i < 8);
    return func_0045A880(o);
}
