/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Vec { float x,y,z,w; };
struct Ent { Vec a; Vec b; Vec c; float inv; float pad; float one; };
struct Obj { char pad[0x222C]; Ent ent[1]; };
extern "C" void func_00390328(Obj *arg0, s32 arg1, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7,
                              float sp0, float sp8, float sp10, float sp18, float sp20) {
    arg0->ent[arg1].a.x = f0;
    arg0->ent[arg1].a.y = f1;
    arg0->ent[arg1].a.z = f2;
    arg0->ent[arg1].a.w = f3 * 10.0f;
    arg0->ent[arg1].b.x = f4;
    arg0->ent[arg1].b.z = f6;
    arg0->ent[arg1].b.y = f5;
    arg0->ent[arg1].b.w = f7;
    arg0->ent[arg1].c.x = sp0;
    arg0->ent[arg1].c.y = sp8;
    arg0->ent[arg1].c.z = sp10;
    arg0->ent[arg1].c.w = sp18 * 128.0f;
    if (sp20 == 0.0f) {
        arg0->ent[arg1].inv = 0.0f;
    } else {
        arg0->ent[arg1].inv = 1.0f / sp20;
    }
    arg0->ent[arg1].one = 1.0f;
}
