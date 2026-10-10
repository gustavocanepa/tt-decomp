struct Stream {
    int base;
    int pad4;
    int size;
    int padC;
    int index;
    int pad14[2];
    volatile int waitSema;
    int lockSema;
};

extern "C" int func_004FA860(int sema);
extern "C" int func_004FA840(int sema);
extern "C" int func_004CDBE8(Stream *s);

extern "C" int func_004CDC80(Stream *s) {
    do {
        if (s->waitSema != -1)
            func_004FA860(s->waitSema);
    } while (s->waitSema != -1 && func_004CDBE8(s));
    func_004FA860(s->lockSema);
    int pos = s->base + s->index * s->size;
    func_004FA840(s->lockSema);
    return pos;
}
