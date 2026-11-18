/* compiler: ee-gcc2.9-991111 */
struct Slot { int fd,flags,a,b; };
struct Req { int sema; int *result; int size,flags,mode; char name[1024]; int slot; };
struct Sema { int attr,max,init,a,b; char *name; };
extern struct Req D_0078DD00;
extern struct Slot D_0078F200[32];
extern char D_0078F400[],D_0078E940[],D_006179E0[];
extern int D_005A315C,D_005A3168;
int func_004FF348(int);
void func_004FF378(void);
int func_004FF470(void),func_004FF678(void);
struct Slot *func_004FED50(void);
int func_004FA820(struct Sema *);
int func_004FA830(int);
int func_004FA860(int),func_004FA840(int);
int func_004FEDD8(void *,int,int,void *,int,void *,int,int,int,int);
int func_004FF970(const char *name,int flags,...) {
    struct Req *req=&D_0078DD00;
    char *args;
    struct Sema sp;
    int result;
    struct Slot *slot;
    int i, idx, sema, reply, mode;
    func_004FF348(0);
    if (!D_005A315C) func_004FF470();
    if (func_004FF678()) { func_004FF378(); return -0x10004; }
    slot=func_004FED50();
    if (!slot) { func_004FF378(); return -19; }
    args=(char *)__builtin_next_arg(flags) - (__builtin_args_info(2)>=8 ? 0 : (8-__builtin_args_info(2))*8);
    mode=*(int *)args;
    for (i=0; i<1024; i++) {
        char *dst=(char *)req+i;
        if ((*(dst+20)=name[i])==0) break;
    }
    if (i==1024) req->name[1023]=0;
    idx=slot-D_0078F200;
    req->flags=flags&0x7fffffff;
    req->mode=mode;
    sp.max=1;
    sp.name=D_006179E0;
    req->slot=idx;
    sp.init=0;
    sema=func_004FA820(&sp);
    req->result=&result;
    req->sema=sema;
    req->size=4;
    if (func_004FEDD8(D_0078F400,0,0,&D_0078DD00,0x418,D_0078E940,4,0,0,0)<0) {
        func_004FA830(sema); func_004FF378(); return -11;
    }
    reply=*(int *)((unsigned int)D_0078E940|0x20000000);
    func_004FF378();
    if (!reply) { func_004FA830(sema); return -11; }
    func_004FA860(sema);
    func_004FA830(sema);
    if (result<0) {
        func_004FA860(D_005A3168);
        slot->flags=0;
        func_004FA840(D_005A3168);
        return result;
    }
    reply=idx;
    func_004FA860(D_005A3168);
    { int old=slot->flags; int fd=result;
    slot->fd=fd;
    slot->flags=old|flags; }
    func_004FA840(D_005A3168);
    return reply;
}
