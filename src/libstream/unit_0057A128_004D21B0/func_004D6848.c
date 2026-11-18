/* compiler: ee-gcc2.9-991111 */
struct Request {
    unsigned char mode;
    char pad[3];
    int id, thread;
    char *path;
    int x10,x14,x18,x1c;
    int argc;
    void *argv;
    int *result;
    int status;
    int x30,x34;
    unsigned int newargc;
    void *newargv;
};
struct Module { int x0,x4,x8,id; };
extern struct { int a,b; } D_00782900;
extern struct Module *func_004D82B8(struct Request *, int *);
extern struct Module *func_004D9E50(int);
extern int func_004D6BC8(struct Module *, char *, int, void *, int *);
extern int func_004D70A8(struct Module *, int, int, void *, int *);
extern int func_004D74B8(struct Module *);
extern int func_004A8368(const char *);
extern char *func_004F7B74(char *,const char *);
extern void *func_004F64C4(void *,const void *,unsigned);
extern void func_004FA6B0(int,int);
extern void func_004FA670(int);
extern void func_004FA630(int);
int func_004D6848(struct Request *p) {
    struct Request copy;
    int err;
    struct Module *m;
    switch(p->mode) {
    case 0: case 1: case 2: case 3:
        m=func_004D82B8(p,&err);
        func_004FA6B0(D_00782900.a,D_00782900.b);
        if(err) p->status=err;
        else {
            p->status=m->id;
            if(p->mode==2 || p->mode==3) {
                err=func_004D6BC8(m,p->path,p->argc,p->argv,p->result);
                if(err) { p->status=err; func_004D74B8(m); }
            }
        }
        break;
    case 4:
        m=func_004D9E50(p->id);
        if(m) {
            p->status=m->id;
            err=func_004D6BC8(m,p->path,p->argc,p->argv,p->result);
            if(err) p->status=err;
        } else p->status=0x8105902d;
        break;
    case 5: case 6: case 7: case 8: case 9:
        m=func_004D9E50(p->id);
        if(!m) { p->status=0x8105902d; break; }
        if(p->mode==9) {
            copy=*p;
            copy.path=__builtin_alloca(func_004A8368(p->path)+1);
            func_004F7B74(copy.path,p->path);
            copy.newargv=__builtin_alloca(p->newargc);
            func_004F64C4(copy.newargv,p->newargv,p->newargc);
        }
        p->status=m->id;
        if(p->mode==5 || p->mode==7 || p->mode==8 || p->mode==9) {
            err=func_004D70A8(m,p->mode,p->argc,p->argv,p->result);
            if(err) p->status=err;
        }
        if(p->mode>=6 && p->mode<=9 && p->status>=0) {
            err=func_004D74B8(m);
            if(err) p->status=err;
            if((p->mode==8 || p->mode==9) && p->status>=0) {
                int thread=p->thread;
                func_004FA6B0(D_00782900.a,D_00782900.b);
                func_004FA670(thread);
                func_004FA630(thread);
                if(copy.mode==9) {
                    do {
                        m=func_004D82B8(&copy,&err);
                        if(err==0) {
                            err=func_004D6BC8(m,copy.path,copy.newargc,copy.newargv,0);
                            if(err) func_004D74B8(m);
                        }
                    } while(err);
                }
                return 1;
            }
        }
        break;
    default: for(;;) {}
    }
    return 0;
}
