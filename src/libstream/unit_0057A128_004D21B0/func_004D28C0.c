/* compiler: ee-gcc2.9-991111 */
/* ELOADP driver teardown: release synchronization, worker and stack resources,
 * then unregister its interrupt handler while CPU interrupts are disabled. */
extern int D_00779FFC, D_0077A000, D_0077A004;
extern void *D_00779FF8;
extern void func_004FA830(int);
extern void func_004FA630(int);
extern void func_004D9D80(void *);
extern int func_005038D8(void);
extern int func_00503928(void);
extern int func_004FA520(int, int);
extern int func_004FB300(int);
void func_004D28C0(void)
{
    int interrupts_enabled;
    int unregister_result;
    func_004FA830(D_00779FFC);
    D_00779FFC = -1;
    func_004FA630(D_0077A000);
    D_0077A000 = -1;
    if (D_00779FF8) {
        func_004D9D80(D_00779FF8);
        D_00779FF8 = 0;
    }
    interrupts_enabled = func_005038D8();
    unregister_result = func_004FA520(3, D_0077A004);
    D_0077A004 = -1;
    if (unregister_result == 0)
        func_004FB300(3);
    if (interrupts_enabled)
        func_00503928();
}
