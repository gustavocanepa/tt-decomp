/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { char pad[0x58]; int a,b,c,dirty; };
extern "C" int func_005038D8(void);
extern "C" void func_004B7680(State *s,int mode,int a,int b,int flag,int dirty) {
    int intr=func_005038D8();
    int m=mode;
    if(m < -10) m=-11;
    switch(m) {
    case -1:
        dirty=1;
    case 0:
        s->a=a;
        s->b=b;
        s->c=flag!=0;
        break;
    default:
        int old=s->a;
        s->a=0;
        if(old) dirty=1;
        if(mode==-2) s->a=a;
        s->b=0;
        s->c=0;
        break;
    }
    s->dirty=(s->dirty!=0) | (dirty!=0);
    if(intr) __asm__ volatile("ei");
}
