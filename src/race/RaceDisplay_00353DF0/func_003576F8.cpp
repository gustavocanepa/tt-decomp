/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_005F44E8[];
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0035A5F0(void *, const char *, int);
extern "C" void RaceEventDisplay__addEvent(void *, const char *, float, float, float, float);
extern "C" void func_003576F8(char *self, const char *text, unsigned int color, float time) {
    char *lock = self + 0xE8;
    func_004A4D68(lock);
    char *p = self + 0x177C;
    if (color == 0) color = 0x80C8C8C8;
    *(unsigned int *)(p + 0x20) = color;
    func_0035A5F0(p, D_005F44E8, 1);
    RaceEventDisplay__addEvent(p, text, time, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    func_004A4DD8(lock);
}
