/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Seeds the VU0 random generator. */
extern "C" void func_0047A064(float seed) {
    __asm__ volatile("mfc1 $8, %0" : : "f"(seed) : "$8");
    __asm__ volatile("qmtc2.i $8, $vf1");
    __asm__ volatile("vrinit R, $vf1x");
}
