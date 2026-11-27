/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ev { char pad[0x20]; unsigned short kind; };
extern "C" int func_0020BF80(void *, int, Ev *);
extern "C" void mWidget__setActive(void *, int);

extern "C" int mScrollArrow__onButtonRelease(void *self, int a1, Ev *ev) {
    int r = func_0020BF80(self, a1, ev);
    if (ev->kind == 1) {
        mWidget__setActive(self, 0);
        return 1;
    }
    return r;
}
