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
extern int D_005A30C4, D_0078B920;
extern int D_0078B928[2];
extern char D_0078B520[], D_006235F0[];
extern const char D_00617698[];
extern void func_004FB520(void);
extern int func_004FA820(SemaParameters *);
extern int func_004FA830(int);
extern int func_004FA620(ThreadParameters *);
extern int func_004FB960(int, void *);
extern int func_004FA710(void);
extern int func_004FA6B0(int, int);

/* Start the kernel's top worker once, releasing its semaphore if thread
 * creation fails. The two-word start message is zero-initialized. */
int func_004FB5F8(void)
{
    ThreadParameters thread;
    SemaParameters semaphore;
    if (D_005A30C4 > 0)
        return -1;
    semaphore.max_count = 255;
    semaphore.initial_count = 0;
    semaphore.option = D_00617698;
    D_0078B920 = func_004FA820(&semaphore);
    if (D_0078B920 < 0)
        return -1;
    thread.entry = func_004FB520;
    thread.stack = D_0078B520;
    thread.stack_size = 0x400;
    thread.global_pointer = D_006235F0;
    thread.option = D_00617698;
    thread.priority = 0;
    D_005A30C4 = func_004FA620(&thread);
    if (D_005A30C4 < 0) {
        func_004FA830(D_0078B920);
        return -1;
    }
    D_0078B928[0] = 0;
    D_0078B928[1] = 0;
    func_004FB960(D_005A30C4, D_0078B928);
    func_004FA6B0(func_004FA710(), 1);
    return D_005A30C4;
}
