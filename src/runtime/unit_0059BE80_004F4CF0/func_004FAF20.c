/* compiler: ee-gcc2.9-991111 */
/* Adjust the shared heap break under interrupt exclusion. The upper limit is
 * queried from the kernel; failure sets errno to ENOMEM and retains the break. */
extern unsigned D_005A30C0;
extern unsigned func_004FA800(void);
extern int *func_004F4F80(void);
static inline unsigned cpu_status(void) {
    unsigned value;
    __asm__ volatile("mfc0 %0, $12" : "=r"(value));
    return value;
}
static inline void disable_interrupts(void) { __asm__ volatile("di" ::: "memory"); }
static inline void synchronize_pipeline(void) { __asm__ volatile("sync.p" ::: "memory"); }
static inline void enable_interrupts(void) { __asm__ volatile("ei" ::: "memory"); }
void *func_004FAF20(int increment) {
    unsigned enabled;
    unsigned next;
    __asm__ volatile("mfc0 %0, $12" : "=r"(enabled));
    enabled&=0x10000;
    if(enabled) {
        do {
            disable_interrupts();
            synchronize_pipeline();
        } while(cpu_status()&0x10000);
    }
    next=D_005A30C0+increment;
    if(func_004FA800()<next) {
        *func_004F4F80()=12;
        if(enabled) enable_interrupts();
        return (void *)-1;
    } else {
        void *previous=(void *)D_005A30C0;
        D_005A30C0=next;
        if(enabled) enable_interrupts();
        return previous;
    }
}
