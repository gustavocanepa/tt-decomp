/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Bound { char pad[8]; float size; };
struct Obj { char pad[0x38]; Bound *bound; };
extern "C" void func_004209C8(void *,int,int);
extern "C" void func_00471DC8(float,float);
extern "C" void func_00473178(int);
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" void pglPushAttrib(int);
extern "C" void func_00473498();
extern "C" void func_00475248();
extern "C" void func_0047525C(float *);
extern "C" void func_004752F8(float *);
extern "C" void func_00475638(float,float,float);
static inline void render_scaled(Obj *obj,int n,float size) {
    float far;
            if(size>0.0f) far=1000.0f/size;
            else far=1.0f;
            func_00473178(0);
            func_00473050();
            func_00475248();
            func_00475638(far,far,far);
            func_004209C8(obj,n,0);
            func_004730A8();
}
extern "C" void func_0034C9A0(void *self,Obj *obj,int n,float near,float far) {
    float mat[16];
    if(obj) {
        pglPushAttrib(0x40);
        func_00471DC8(0.0f,1.0f);
        func_00473178(1);
        func_00473050();
        func_004752F8(mat);
        if(mat[2]==0.0f && mat[6]==0.0f) {
            float d=far-near;
            mat[10]=-(far+near)/d;
            mat[14]=(far * -2.0f * near)/d;
            func_0047525C(mat);
            func_00473178(0);
            func_00473050();
            func_00475248();
            func_004209C8(obj,n,0);
            func_004730A8();
        } else {
            render_scaled(obj,n,obj->bound->size);
        }
        func_00473178(1);
        func_004730A8();
        func_00473498();
        func_00473178(0);
    }
}
