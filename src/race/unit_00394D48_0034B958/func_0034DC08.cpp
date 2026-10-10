struct Vec3 { float x, y, z; };
struct Cam { Vec3 pos; float pad; float fov; float aspect; };

extern "C" Vec3 D_00584088;
extern "C" void func_00471DC8(float fov, float aspect);
extern "C" void func_0034DD00(void);

extern "C" void func_0034DC08(Cam *c, float scale)
{
    func_00471DC8(c->fov * scale, c->aspect);
    D_00584088.x = c->pos.x;
    D_00584088.y = c->pos.y;
    D_00584088.z = c->pos.z;
    func_0034DD00();
}
