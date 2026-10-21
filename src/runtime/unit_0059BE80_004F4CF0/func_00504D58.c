/* compiler: ee-gcc2.9-991111 */
/* Resume a generation-checked timer object. An already-running object returns
 * 1; successful resumption returns 0. Shared pool layout is provisional. */
struct Timer {
    struct Timer *next, *previous;
    int generation;
    unsigned flags;
    unsigned long long started;
    char unknown18[0x28];
};
struct Pool { char unknown0[0x1C]; int current; };
extern volatile struct Pool D_005A4110;
static inline volatile struct Pool *pool_state(void) { return &D_005A4110; }
extern unsigned long long func_00504A30(void);
extern void func_005046C8(struct Timer *);
extern void func_00504538(unsigned long long);
int func_00504D58(int handle) {
    struct Timer *timer=(struct Timer *)(((unsigned)handle>>10)<<6);
    unsigned long long now;
    if(handle<0 || (handle&0x3ff)!=timer->generation) return 0x80008002;
    if(pool_state()->current==handle) return 0x80000010;
    if(timer->flags&1) return 1;
    now=func_00504A30();
    timer->started=now;
    timer->flags|=1;
    if(timer->flags&2) {
        func_005046C8(timer);
        func_00504538(now);
    }
    return 0;
}
