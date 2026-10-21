typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Obj { char pad[0x10]; char *p10; };
extern char D_005E1BD8[];
extern "C" void func_00141F98(void *, int);
extern "C" void func_00141FF0(void *, void *);
extern "C" void func_002ADBF0(void *, int);
extern "C" void func_002ADC48(void *, void *);
extern "C" Str *func_002AFE68(s32);
extern "C" void func_003F7360(char *, const char *);
static inline const char *c_str(Str *s) { s32 len=((Rep *)s->p)[-1].len; if(len==0)return D_005E1BD8; s->p[len]=0; return s->p; }
static inline void call(char *p, const char *t) { func_003F7360(p,t); }
extern "C" void func_001463C8(void *, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        Obj *tmp[4];
        s32 buf[4];
        s32 *pb;
        char *base;
        func_00141FF0(tmp,arg1);
        pb=buf;
        func_002ADC48(pb,arg3);
        base=tmp[0]->p10;
        base+=0x1DA0;
        call(base,c_str(func_002AFE68(*pb)));
        func_002ADBF0(pb,2);
        func_00141F98(tmp,2);
    }
}
