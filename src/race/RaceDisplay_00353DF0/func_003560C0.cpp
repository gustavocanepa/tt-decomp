/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void AutomaticFader__fadein(void *, float);
extern "C" void AutomaticFader__oneshot(void *, float, float, float, float);
extern "C" void func_003560C0(char *self, float time) {
    if ((*(int *)(self + 0x58) >> 10) & 1) {
        AutomaticFader__oneshot(self + 0x1490, 0.0f, time, 0x1.333332p-3f, 0x1.333332p-3f);
        return AutomaticFader__oneshot(self + 0x1570, 0.0f, time, 0x1.333332p-3f, 0x1.333332p-3f);
    }
    AutomaticFader__fadein(self + 0x1490, 0x1.333332p-3f);
    AutomaticFader__fadein(self + 0x1570, 0x1.333332p-3f);
}
