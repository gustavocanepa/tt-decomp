typedef int s32;

extern volatile s32 D_00598358;
extern "C" s32 func_005038D8(void);

/* Swap the global with interrupts disabled (func_005038D8 is DI returning the previous state).
   The original reads the volatile global once more after the store (lw $a0, dead). */
extern "C" s32 func_004BA470(s32 v) {
    s32 st = func_005038D8();
    s32 old = D_00598358;
    D_00598358 = v;
    (void)D_00598358;
    if (st) __asm__ volatile("ei");
    return old;
}
