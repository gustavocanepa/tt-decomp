/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };
struct Obj { char pad[0x28]; Vec3 pos; char pad2[0xC]; int id; };

extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_00319BB0(Obj *self, int id, Vec3 *v, int flags);

extern "C" void func_00319260(Obj *self)
{
    Vec3 v;
    func_004F6678(&v, 0, sizeof(v));
    v.x = self->pos.x;
    v.z = self->pos.z;
    func_00319BB0(self, self->id, &v, 0);
}
