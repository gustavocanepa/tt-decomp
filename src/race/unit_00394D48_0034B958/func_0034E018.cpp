/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x10]; int mask; char p1[0x24]; float scale; char p2[0xa74]; float ab0,ab4,ab8,abc,ac0,ac4,ac8,acc; };
extern "C" void func_0034DBB0() throw();
extern "C" void func_0034E630(float *,void *,float,float,float,float,float) throw();
extern "C" void func_0046F0F8(int);
extern "C" void func_00473A08(int,int,void *);
extern "C" void func_00478C98(int);
extern "C" void func_0034E018(Obj *o,float a,float b) {
    float out[4];
    float inv,x3,y1,y2,x2,x1,y3;
    char *p;
    int id=0x65;
    int i=0;
    func_0034DBB0();
    inv=1.0f/o->scale;
    y3=1.0f-o->ab4;
    x1=1.0f-o->ac8;
    x2=1.0f-o->ac0;
    y2=1.0f-o->abc;
    y1=1.0f-o->acc;
    x3=1.0f-o->ac4;
    p=(char *)o;
    do {
        int mask=1<<i;
        i++;
        if(o->mask & mask) {
            func_0046F0F8(id);
            func_00473A08(id,13,p+0xd0);
            func_0034E630(out,p+0xe0,a,x1,b,y1,inv);
            func_00473A08(id,0,out);
            func_0034E630(out,p+0xf0,a,y3,b,y2,inv);
            func_00473A08(id,1,out);
            func_0034E630(out,p+0x100,a,x2,b,x3,inv);
            func_00473A08(id,4,out);
        } else func_00478C98(id);
        p+=0x80;
        id++;
    } while(i<4);
}
