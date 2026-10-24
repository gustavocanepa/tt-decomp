/* compiler: ee-gcc2.9-991111 */
/* Same worker state as 00586DA0 and 00587BB0. */
struct Driver { int thread, priority, done_semaphore, idle_semaphore, request; };
extern struct Driver D_00782900;
extern int func_004FA860(int);
extern int func_004FA670(int);
extern int func_004FA630(int);
extern int func_004FA830(int);
int func_004D5B30(void) {
    if(func_004FA860(D_00782900.done_semaphore)<0) return 0x81058003;
    func_004FA670(D_00782900.thread);
    func_004FA630(D_00782900.thread);
    func_004FA830(D_00782900.done_semaphore);
    func_004FA830(D_00782900.idle_semaphore);
    D_00782900.thread=-1;
    D_00782900.done_semaphore=-1;
    D_00782900.idle_semaphore=-1;
    return 0;
}
