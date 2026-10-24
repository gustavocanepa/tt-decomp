/* compiler: ee-gcc2.9-991111 */
/* SDK parameter layouts inferred from the fields passed to CreateSema and
 * CreateThread. Fields not initialized by the original are left untouched. */
typedef struct {
    int count, max_count, initial_count, waiting_threads;
    unsigned int attributes;
    const char *option;
} SemaParameters;
typedef struct {
    int status;
    void (*entry)(void);
    void *stack;
    int stack_size;
    void *global_pointer;
    int priority, initial_priority;
    unsigned int attributes;
    const char *option;
} ThreadParameters;
extern void *D_00779FF8;
extern int D_00779FFC, D_0077A000, D_0077A004;
extern const char D_00613AC0[], D_00613AD0[];
extern void *func_004D9D78(int, unsigned int, unsigned int);
extern int func_004FA820(SemaParameters *);
extern int func_004FA620(ThreadParameters *);
extern int func_005038D8(void);
extern int func_00503928(void);
extern int func_004FA510(int, void (*)(void), int, int);
extern int func_004FB368(int);
extern void func_004D27D0(void);
extern void func_004D27C0(void);
void func_004D27D8(void)
{
    ThreadParameters thread;
    SemaParameters semaphore;
    int interrupts_enabled;
    D_00779FF8 = func_004D9D78(4, 0xA000, 0x100);
    if (!D_00779FF8)
        return;
    semaphore.max_count = 1;
    semaphore.option = D_00613AC0;
    semaphore.initial_count = 0;
    D_00779FFC = func_004FA820(&semaphore);
    thread.entry = func_004D27D0;
    thread.stack = D_00779FF8;
    thread.stack_size = 0x400;
    thread.priority = 0x7E;
    thread.option = D_00613AD0;
    thread.global_pointer = 0;
    D_0077A000 = func_004FA620(&thread);
    interrupts_enabled = func_005038D8();
    D_0077A004 = func_004FA510(3, func_004D27C0, 0, 0);
    func_004FB368(3);
    if (interrupts_enabled)
        func_00503928();
}
