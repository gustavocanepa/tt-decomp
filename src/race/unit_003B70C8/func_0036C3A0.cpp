/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Link { short next; short time; int key; };
extern "C" void ErrorEventView__removeMessage(void *, void *);
extern "C" Link *func_0036C490(void *, int);
extern "C" Link *func_0036C4D8(void *);
extern "C" int RaceEventQueue__get(void *, int, int *, int);
extern "C" void func_0036C3A0(void *self, char *context) {
    int values[4];
    while (RaceEventQueue__get(context + 0xF4, 0x1B, values, 1)) {
        int key = values[0];
        Link *p = func_0036C490(self, key);
        if (!p) {
            p = func_0036C4D8(self);
            if (!p) {
                ErrorEventView__removeMessage(self, context);
                return;
            }
        }
        p->key = key;
        p->time = 120;
    }
}
