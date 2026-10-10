struct View { float scale; float rest[15]; } __attribute__((aligned(8)));
struct Cam { struct View view; float fov; };
struct Obj { char pad[0xD40]; struct Cam cam; };
extern struct View D_00583D48;
void func_003207C0(struct Obj *o, float a, float b, float c, float d)
{
    if (b != 0.0f)
        D_00583D48.scale = b / (c * a);
    struct Cam *cam = &o->cam;
    cam->view = D_00583D48;
    cam->fov = d;
}
