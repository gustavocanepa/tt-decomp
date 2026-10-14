/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TexData {char pad[0x20];unsigned long bits;};
struct Tex {char pad[0x18];TexData *data;};
struct Self {char pad[0x18];Tex *tex,*tex2;int speed;char pad24[8];int tw,th,flag;};
struct Buffer {int id,flags;};
struct Font {int unk,flags;float x,y;char pad10[8];float sx,sy;};
extern Font D_00585CC8;extern char D_006A1460[],D_005F55D0[],D_006A1438[];
extern "C" void func_001055C0(void*),func_00104A48(void*,int,int),func_00104C88(void*);
extern "C" int func_00104B10(void*);
extern "C" void pglPushAttrib(int),func_00470450(int),func_00470B48(int),func_00470E60(int),func_00473498(),func_00477DC0(unsigned),func_0046F0F8(int),func_00478C98(int),func_00470478(int),func_004702D8(int,float),func_00473178(int),func_00473050(),func_004751FC(),func_004730A8();
extern "C" void func_004738A0(float,float,float,float,float,float),func_004AA1D8(float,float,float,float),func_0038EC28(Tex*,float,float,float,float,int,int),func_00470220(int,float),func_00470298(int);
extern "C" void func_00416010(Font*,float,float),func_004155A8(Font*,const char*),func_00415540(Font*),func_00415578(Font*),func_00415B10(Font*,unsigned),func_00415D18(Font*,const char*,...);
extern "C" int func_00416030(Font*,int,int);
extern "C" float func_00415C58(Font*,const char*);
extern "C" unsigned func_003AFEC8(unsigned,float);
extern char D_005F55C0[],D_005F5998[];
extern "C" void RaceMTRSpeedMeterPanel__init_texset(Self*);
extern "C" int func_00416078(Font*);
extern "C" unsigned RaceDisplayUtil__getScaledColor(unsigned,float,float);
extern "C" void RaceMTRSpeedMeterPanel__render_buffer(Self *self,Buffer *buf) {
 Font *font=&D_00585CC8;float one=1.0f;
 pglPushAttrib(1);RaceMTRSpeedMeterPanel__init_texset(self);
 float sx=font->sx;float sy=font->sy;
 func_00416010(font,one,one);func_004155A8(font,D_005F55C0);
 if(self->tw==0){self->tw=(int)func_00415C58(font,D_005F55D0);self->th=func_00416078(font);}
 int h=self->th+3;
 unsigned long bits=self->tex->data->bits;
 int texH=(int)(((bits>>34)&0x3FF)+1),texW=(int)(((bits>>14)&0x3FF)+1);
 int w=texW+self->tw;
 if(h<texH)h=texH;
 if(buf->id==-1){func_00104A48(buf,w,h);buf->flags=0;func_00104B10(buf);}
 func_00104C88(buf);func_00470450(-1);func_00470B48(0);func_00470E60(1);
 float fw=(float)w;
 func_00477DC0(0x80FFFFFF);func_0046F0F8(6);func_0046F0F8(4);func_00478C98(15);func_00478C98(5);func_00470478(0);
 float fh=(float)h;
 func_00470220(6,0.0f);func_00470298(0);func_004702D8(0x44,0.0f);func_00473178(1);func_00473050();func_004751FC();
 func_004738A0(0.0f,fw,fh,0.0f,-1.0f,1.0f);func_00473178(0);func_00473050();func_004751FC();
 float x=(float)(w-texW),y=(float)(h-texH);
 func_0038EC28(self->tex,x,y,fw,fh,0,0);
 float lit=self->flag?1.0f:0.0f;
 func_00477DC0(RaceDisplayUtil__getScaledColor(0x800000FF,lit,1.0f));
 func_0038EC28(self->tex2,x,y,fw,fh,0,0);
 func_00416030(&D_00585CC8,w,h);func_00415540(&D_00585CC8);func_00415B10(&D_00585CC8,0x80E3B896);
 D_00585CC8.flags=4;D_00585CC8.y=D_00585CC8.x=0.0f;
 func_00415D18(&D_00585CC8,D_005F5998,self->speed<0?-self->speed:self->speed);
 D_00585CC8.flags=0;func_00415578(&D_00585CC8);
 func_00478C98(4);func_004730A8();func_00473178(1);func_004730A8();func_00473178(0);
 func_00416010(&D_00585CC8,sx,sy);func_00473498();
}
