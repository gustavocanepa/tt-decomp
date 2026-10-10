struct Vec3 { float x, y, z; };
struct Cam { char pad[0x100]; char mtx[0xC0]; Vec3 pos; Vec3 rot; };
extern "C" void func_0046E150(void);
extern "C" void func_00473050(void);
extern "C" void func_004751FC(void);
extern "C" void func_00475780(float);
extern "C" void func_00475730(float);
extern "C" void func_00475758(float);
extern "C" void func_004755EC(float, float, float);
extern "C" void func_004752F8(void *);
extern "C" void func_004730A8(void);
extern "C" void func_0046E1B0(void);

extern "C" void func_0032D7F8(Cam *c)
{
    const float &rx = c->rot.x;
    func_0046E150();
    func_00473050();
    func_004751FC();
    func_00475780(c->rot.z);
    func_00475730(rx);
    func_00475758(c->rot.y);
    func_004755EC(-c->pos.x, -c->pos.y, -c->pos.z);
    func_004752F8(c->mtx);
    func_004730A8();
    func_0046E1B0();
}
