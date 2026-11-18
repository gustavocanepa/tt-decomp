/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mesh { int p0; char *data; };
extern "C" int func_003939E8(int) throw();
extern "C" int func_003E5988(unsigned);
extern "C" Mesh *ModelSet2__searchModelName(void *, int, int *);
extern "C" void ModelSet2__begin(void *, int);
extern "C" void ModelSet2__end(void *);
extern "C" int ModelSet2___render(void *, char *, int);
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" void func_00475440(int);
extern "C" void func_004755EC(float, float, float);
extern "C" void func_00475908(int, int);

extern "C" void func_0039A920(void *self, int arg1, int arg2, float *pos)
{
    int count;
    int i;
    int name;
    Mesh *m;
    int k;
    ModelSet2__begin(self, 0);
    for (i = 0; i < 0x15; i++) {
        if (i < 0x14) {
            name = func_003E5988(i);
        } else {
            if (arg1 == 0)
                break;
            name = arg1;
        }
        m = ModelSet2__searchModelName(self, name, &count);
        if (m != 0 && count > 0) {
            func_00473050();
            int h = func_003939E8(name);
            if (h != 0) {
                func_00475440(h);
                for (k = 0; k < count; k++)
                    ModelSet2___render(self, m->data + k, 0);
            }
            func_004730A8();
        }
    }
    m = ModelSet2__searchModelName(self, (int)"SKINNING", &count);
    if (m != 0) {
        func_00473050();
        func_004755EC(pos[0], pos[1], pos[2]);
        func_00475908(arg2, 0x14);
        for (k = 0; k < count; k++)
            ModelSet2___render(self, m->data + k, 0);
        func_004730A8();
    }
    ModelSet2__end(self);
}
