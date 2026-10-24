/* compiler: ee-gcc2.9-991111 */
/* Provisional views of the SIF transaction and the caller's completion record. */
struct Completion;
struct Request {
    int unknown0[5];
    struct Request *self;
    int token;
    struct Completion *completion;
    int argument0, argument1, argument2;
};
struct Completion { struct Request *request; int token; int semaphore; };
struct Semaphore { int current_count, maximum_count, initial_count, waiters; unsigned attributes; const char *tag; };
extern char D_0078DC80;
extern const char D_00617908;
extern struct Request *func_004FDD70(void *);
extern void func_004FDE18(struct Request *);
extern int func_004FA820(struct Semaphore *);
extern int func_004FA830(int);
extern int func_004FA860(int);
extern int func_004FD930(int, struct Request *, int, int, int, int);
int func_004FE088(struct Completion *completion, int arg0, int arg1, int arg2, int flags) {
    struct Semaphore semaphore;
    struct Request *request=func_004FDD70(&D_0078DC80);
    if(!request) return -1;
    completion->request=request;
    completion->token=request->token;
    request->argument0=arg0;
    request->argument1=arg1;
    request->argument2=arg2;
    request->self=request;
    request->completion=completion;
    if(!(flags&1)) {
        semaphore.maximum_count=1;
        semaphore.tag=&D_00617908;
        semaphore.initial_count=0;
        completion->semaphore=func_004FA820(&semaphore);
        if(completion->semaphore<0) {func_004FDE18(request); return -3;}
        if(!func_004FD930(0x8000000C,request,64,0,0,0)) {
            func_004FDE18(request);
            func_004FA830(completion->semaphore);
            return -2;
        }
        func_004FA860(completion->semaphore);
        func_004FA830(completion->semaphore);
        return 0;
    } else {
        completion->semaphore=-1;
        if(!func_004FD930(0x8000000C,request,64,0,0,0)) {
            func_004FDE18(request);return -2;
        }
        return 0;
    }
}
