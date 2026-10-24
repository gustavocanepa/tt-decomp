/* compiler: ee-gcc2.9-991111 */
/* Submit operation 11 for a live descriptor and wait for its completion word.
 * Partial packet/descriptor layouts are provisional. The original submission
 * error path waits and unlocks without deleting the semaphore. */
struct Entry { int handle, occupied, unknown8, unknownC; };
struct Semaphore { int current, maximum, initial, waiters; unsigned attributes; const char *tag; };
struct Request { int semaphore; int *result; int result_size, handle; void *output; char unknown14[12]; };
extern struct Request D_0078DD00;
extern int D_005A315C, D_0078E940;
extern char D_0078F400;
extern const char D_00617B00[];
extern struct Entry *func_004FEEC8(unsigned);
extern int func_004FF348(int);
extern void func_004FF378(void);
extern int func_004FA820(struct Semaphore *);
extern int func_004FA830(int);
extern int func_004FA860(int);
extern unsigned func_004FEDD8(void *, int, int, void *, int, void *, int,
    void (*)(void *), void *, int);
int func_00501400(unsigned descriptor, void *output) {
    struct Semaphore parameters;
    int result, semaphore, accepted, handle;
    struct Request *request=&D_0078DD00;
    struct Entry *entry=func_004FEEC8(descriptor);
    func_004FF348(11);
    if(!D_005A315C || !entry || !entry->occupied) {
        func_004FF378();return -9;
    }
    handle=entry->handle;
    request->handle=handle;
    request->output=output;
    parameters.maximum=1;
    parameters.tag=D_00617B00;
    parameters.initial=0;
    semaphore=func_004FA820(&parameters);
    request->semaphore=semaphore;
    request->result=&result;
    request->result_size=4;
    if((int)func_004FEDD8(&D_0078F400,11,0,request,32,&D_0078E940,4,0,0,0)<0) {
        func_004FA860(semaphore);
        func_004FF378();return -11;
    }
    accepted=*(int *)((unsigned)&D_0078E940|0x20000000);
    func_004FF378();
    if(!accepted) {func_004FA830(semaphore);return -11;}
    func_004FA860(semaphore);
    func_004FA830(semaphore);
    return result;
}
