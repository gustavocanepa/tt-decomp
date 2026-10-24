/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" float func_002F9150(void *,float);
extern "C" int func_0039F048(void *) throw();
extern "C" void func_0039F178(void) throw();
extern "C" float D_00584988,D_0058498C,D_0058497C,D_00584980;
extern "C" float func_0039F218(char *self) {
    char *p=self+0x104;
    float v=1.0f;
    float dt=F(self,float,0x56C);
    char *q=F(self,char *,0x10)+0x240;
    func_0039F178();
    float x=F(p,float,0x4B4);
    float factor=F(p,float,0x4A8);
    if(F(p,u8,0x542)==1) {
        float target=1.0f;
        if(F(p,u8,0x540)) {
            v=F(p,float,0x51C)/F(p,float,0x530);
            int flag=0;
            if(v>1.0f) v=1.0f;
            else {
                float low=F(q,float,0x40+F(q,u8,2)*4);
                if(v<low) v=low;
            }
            float speed;
            if(func_0039F048(q)) {
                float n=F(q,unsigned short,0x30)*0x1.acee9cp-4f;
                float coeff=factor*0x1.999998p-2f+0x1.333332p-1f;
                n*=coeff;
                float high=F(p,float,0x530);
                target=1.0f;
                if(n<high) {
                    target=n/high;
                    float low=F(q,float,0x40+F(q,u8,2)*4);
                    if(target<low) target=low;
                    else if(target>1.0f) target=1.0f;
                }
                float a=D_00584980;
                speed=a+factor*(D_0058497C-a);
            } else {
                if(F(p,u8,0x540)>=2) target=F(q,float,0x40+F(p,u8,0x540)*4);
                if(target<v) speed=D_00584988; else speed=D_0058498C;
                if(F(p,signed char,0x486)==1 || F(p,u8,0x487)!=0 || F(p,u8,0x462)==0) flag=1;
            }
            if(target!=v) {
                speed*=dt;
                speed*=F(p,float,0x538);
                if(v<target) {
                    v+=speed;
                    if(target<=v) v=target;
                    else if(flag) F(p,u8,0x546)=1;
                } else {
                    v-=speed;
                    if(v<=target) v=target;
                    else if(flag) F(p,u8,0x546)=1;
                }
            }
        }
    }
    F(p,float,0x538)=v;
    return v*func_002F9150(self,x);
}
