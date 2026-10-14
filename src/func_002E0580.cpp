/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x10]; float x,y,z; char pad1[0x44-0x1c]; unsigned char index,kind,a,b; };
struct Render;
struct Manager2 {char pad[0x80]; Render* render;};
struct Manager {char pad[4]; Manager2* p;};
extern Manager* D_0061B710;
extern int D_00582AAC,D_00582AB0,D_00582AC4;
extern "C" {
int func_002DDBE8(int) throw() __attribute__((const));
bool func_002E0778(Obj*);
void func_002E0488(Obj*,float*) throw();
void func_002E04C0(Obj*,float*) throw();
void func_0034DE60(Render*,float,float);
float func_0034E1E8(Render*,float,float);
void func_002E0F10(int,int);
void func_00468B68(float);
void func_00470478(int);
void func_00473178(int);
void func_00473050();
void func_004730A8();
void func_00473EF0(float,float,float,float);
void func_00475440(float*);
}
extern "C" void func_002E0580(Obj* o) {
 float m[16],n[16];
 if(func_002DDBE8(o->kind) && func_002E0778(o)) {
 func_002E0488(o,m);
 m[12]=o->x;m[13]=o->y;m[14]=o->z;
 Render* r=D_0061B710->p->render;
 int a=o->a,b=o->b;
 float fa=(float)a*0x1.010100p-8f;
 float fb=(float)b*0x1.010100p-8f;
 
 if(D_00582AAC!=a || D_00582AB0!=b) {
 func_0034DE60(r,fa,fb);D_00582AAC=o->a;D_00582AB0=o->b;
 }
 if(D_00582AC4) {
 func_002E04C0(o,n);func_00473178(1);func_00473050();func_00468B68(0x1.47ae14p-8f);
 func_00473178(0);func_00473050();func_00475440(n);func_00475440(m);func_00470478(0);
 func_00473EF0(1,1,1,func_0034E1E8(r,fa,fb));func_002E0F10(o->index,1);func_00470478(1);
 func_00473178(1);func_004730A8();func_00473178(0);func_004730A8();
 }
 func_00473050();func_00475440(m);func_002E0F10(o->index,0);func_004730A8();
 }
}
