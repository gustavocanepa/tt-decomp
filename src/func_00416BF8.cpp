struct S { char matrix[80]; float angle,offset,x,y,z; };
extern "C" void func_00473050(); extern "C" void func_004730A8();
extern "C" void func_004751FC(); extern "C" void func_00475248();
extern "C" void func_004752F8(void*); extern "C" void func_00475440(void*);
extern "C" void func_004755EC(float,float,float);
extern "C" void func_00475730(float); extern "C" void func_00475758(float);
extern "C" void func_00416BF8(S* s,float x,float y,float z) {
 void* m=s->matrix+16;
 s->y=y;s->z=z;s->x=x;
 func_00473050();func_004752F8(m);func_004751FC();func_00475730(-s->angle);func_00475758(180.0f);
 func_00475440(m);func_00475248();func_004755EC(-s->x,-s->y,-s->z);func_004755EC(0.0f,-s->offset,0.0f);
 func_004752F8(m);func_004730A8();
}
