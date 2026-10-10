struct Loader {
    int pad0[4];
    void *obj;
    int pad14[3];
};

struct Matrix {
    float m[12];
};

struct Obj {
    int pad0[4];
    void *model;
    int pad14;
    int kind;
};

extern const char D_005F6F90[];
extern "C" void StrobeHandler__readFile(Loader *l, const char *name, int flags);
extern "C" void func_0043A7E8(void *model);
extern "C" void func_002E39A0(void *model);
extern "C" void func_00439930(Matrix *m);
extern "C" void func_0043AD60(void *model, Matrix *m);

extern "C" void func_00377730(Obj *self, int kind)
{
    self->kind = kind;
    Loader l;
    StrobeHandler__readFile(&l, D_005F6F90, 1);
    self->model = l.obj;
    func_0043A7E8(self->model);
    func_002E39A0(self->model);
    Matrix m;
    func_00439930(&m);
    func_0043AD60(self->model, &m);
}
