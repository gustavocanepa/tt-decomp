/* compiler: ee-gcc2.9-991111 */
struct Timer {
    int m0;
    int m4;
    int id;
    int flags;
    long long base;
    long long total;
    unsigned long long schedule;
    void *handler;
    void *gp;
    void *common;
    int pad;
};

struct TimerCtl {
    char pad[0x1C];
    volatile int current;
};

extern struct TimerCtl D_005A4110;
extern void func_00504750(struct Timer *);
extern void func_005046C8(struct Timer *);
extern long long func_00504A30(void);
extern void func_00504538(long long);

/* iSetTimerHandler */
int func_00505198(int id, unsigned long long schedule, void *handler, void *common)
{
    struct Timer *t = (struct Timer *)(((unsigned int)id >> 10) << 6);

    if (id < 0 || (id & 0x3FF) != t->id)
        return 0x80008002;
    if (D_005A4110.current == id)
        return 0x80000010;
    if (t->flags & 2)
        func_00504750(t);
    t->handler = handler;
    if (handler == 0) {
        t->flags &= 0xFFFFFFFDU;
    } else {
        t->schedule = schedule;
        t->flags |= 2;
        /* the handler runs with the caller's module gp */
        __asm__ volatile("sw $28, %0" : "=m"(t->gp) : : "memory");
        t->common = common;
        if (t->flags & 1)
            func_005046C8(t);
    }
    func_00504538(func_00504A30());
    return 0;
}
