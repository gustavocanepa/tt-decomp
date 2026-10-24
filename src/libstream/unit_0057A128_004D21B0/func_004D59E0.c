/* compiler: ee-gcc2.9-991111 */
/* SDK parameter layouts inferred from matching callers. Unspecified fields
 * retain the original uninitialized state. The worker signals done or idle. */
struct Semaphore {
    int current_count, maximum_count, initial_count, waiters;
    unsigned attributes;
    void *tag;
};
struct Thread {
    int status;
    void (*entry)(void *);
    void *stack;
    int stack_size, global_pointer, priority, current_priority;
    unsigned attributes;
    void *tag;
};
struct Driver { int thread, priority, done_semaphore, idle_semaphore, request; };
extern struct Driver D_00782900;
extern char D_00613BA0, D_00613BB8, D_00613BD0, D_0077A900;
extern void func_004D67F0(void *);
extern void func_004D8838(int);
extern int func_004FA820(struct Semaphore *);
extern int func_004FA830(int);
extern int func_004FA620(struct Thread *);
extern int func_004FB960(int, void *);
int func_004D59E0(int priority) {
    struct Thread thread;
    struct Semaphore semaphore;
    D_00782900.priority=priority;
    D_00782900.request=0;
    func_004D8838(2);
    semaphore.initial_count=1;
    semaphore.tag=&D_00613BA0;
    semaphore.maximum_count=1;
    D_00782900.done_semaphore=func_004FA820(&semaphore);
    if(D_00782900.done_semaphore<0) return 0x81058003;
    semaphore.maximum_count=1;
    semaphore.tag=&D_00613BB8;
    semaphore.initial_count=0;
    D_00782900.idle_semaphore=func_004FA820(&semaphore);
    if(D_00782900.idle_semaphore<0) {
        func_004FA830(D_00782900.done_semaphore);
        D_00782900.done_semaphore=-1;
        return 0x81058003;
    }
    thread.entry=func_004D67F0;
    thread.stack=&D_0077A900;
    thread.stack_size=0x8000;
    thread.priority=priority;
    thread.tag=&D_00613BD0;
    thread.global_pointer=0;
    D_00782900.thread=func_004FA620(&thread);
    if(D_00782900.thread<0) {
        func_004FA830(D_00782900.done_semaphore);
        func_004FA830(D_00782900.idle_semaphore);
        D_00782900.done_semaphore=-1;
        D_00782900.idle_semaphore=-1;
        return 0x81058004;
    }
    func_004FB960(D_00782900.thread,0);
    return 0;
}
