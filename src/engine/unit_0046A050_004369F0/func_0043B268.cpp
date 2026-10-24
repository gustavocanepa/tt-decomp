struct Dev { int f0; int f4; };
struct Obj { char pad0[0x6E14]; Dev *dev; char pad1[0x6E30 - 0x6E18]; int counter; int flag; };
extern "C" void func_0043B1B8(Obj *self, int a1, int a2, int a3, int a4);
extern "C" void func_0043A130(Dev *d);
extern "C" void func_0043A080(Dev *d, int a, int b, int c, int e);
extern "C" void func_0043A150(Dev *d, int a, int b, int c);
extern "C" void func_0043A168(Dev *d, int a, int b, int c);
extern "C" void func_0043B268(Obj *self) {
    int *p = &self->counter;
    int t = (*p)++;
    if (t != 0) {
        func_0043B1B8(self, 0, 4, 2, 0);
        func_0043A168(self->dev, 3, 3, 3);
    } else {
        func_0043A130(self->dev);
        func_0043A168(self->dev, 2, 2, 2);
    }
    func_0043A150(self->dev, 1, 0x80, 0xFF);
    func_0043A080(self->dev, 0, 0, 0, 0);
    self->flag = 1;
}
