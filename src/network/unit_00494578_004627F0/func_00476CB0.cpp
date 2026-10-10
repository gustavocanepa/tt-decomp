/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Src_004A8FC8 {
    char pad0[0xC];
    s32 mC;
    s32 m10;
};

struct Obj_004A8FC8 {
    char *m0;
    char *m4;
    s32 m8;
    s32 mC;
    s32 m10;
};

extern "C" char *func_00476EA0(Src_004A8FC8 *src);

extern "C" char *func_00476CB0(Obj_004A8FC8 *arg0, Src_004A8FC8 *arg1) {
    char *p = func_00476EA0(arg1);
    arg0->m0 = p; 
    arg0->m4 = p; 
    arg0->m8 = 0; 
    arg0->mC = arg1->mC + arg1->m10; 
    arg0->m10 = 0; 
    return p;
}
