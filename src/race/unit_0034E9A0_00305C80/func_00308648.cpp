/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_003080E0(int, void *, void *) throw();
extern "C" int func_003082F8(void *, void *) throw();
extern "C" float func_002F8538(void *) throw();
extern "C" float func_003084B0(int, void *, void *, float) throw();
extern "C" void *func_004F6678(void *, int, unsigned int);
extern unsigned char D_00583877[];

static inline float percent(unsigned char x) { return (float)x * 0.01f; }

extern "C" void func_00308648(char *dst, char *src, int mode, int arg3) {
    unsigned char cnt[6];
    unsigned int i = 0;
    func_004F6678(cnt, 0, 6);
    char *d = dst + 0xFF4;
    unsigned char *s = (unsigned char *)(src + 0x1F0);
    do {
        unsigned char v = *s;
        s++;
        i++;
        if (v >= 3)
            v = 0;
        int w = v + 3;
        d[-0x18] = v;
        *d = w;
        cnt[v]++;
        d++;
        cnt[w]++;
    } while (i < 0x18);
    unsigned int start = 0;
    unsigned int end = 6;
    if (mode == 1) {
        end = 3;
    } else {
        start = ((mode ^ 2) != 0) ? 0 : 3;
    }
    i = start;
    if (i < end) {
        char *p = (char *)(i * 0x1EC + (unsigned int)dst);
        do {
            if (((signed char *)cnt)[i] != 0) {
                unsigned int k = i;
                if (*(unsigned char *)(src + 0x1E0) == 0)
                    k = i % 3;
                char *a = p + 0x454;
                char *b = src + k * 0xA8 + 0x210;
                a[0x1D8] = b[3];
                a[0x1D9] = b[4];
                a[0x1DA] = b[5];
                func_003080E0(arg3, a, b);
                func_003082F8(a, b);
                float f = func_002F8538(a);
                *(float *)(a + 0xB8) = f;
                if (f > 0.78539807f)
                    *(float *)(a + 0xB8) = 0.78539807f;
                unsigned int idx = k % 3;
                float scale = 0.01f;
                scale = (float)D_00583877[idx + 0xB0] * scale;
                func_003084B0(arg3, a, b, scale);
            }
            i++;
            p += 0x1EC;
        } while (i < end);
    }
}
