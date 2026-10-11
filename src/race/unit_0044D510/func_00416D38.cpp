class Drawable {
public:
    virtual void v1();
    virtual void v2();
    virtual void draw(float t);
};

extern "C" void func_00473050(void);
extern "C" void func_004751FC(void);
extern "C" void func_004730A8(void);
extern "C" void func_00416BF8(void *self, float x, float y, float z);

extern "C" void func_00416D38(void *self, Drawable *d, float x, float y, float z, float t)
{
    func_00473050();
    func_004751FC();
    d->draw(t);
    func_00416BF8(self, x, y, z);
    func_004730A8();
}
