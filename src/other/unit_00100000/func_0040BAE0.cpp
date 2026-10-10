struct Entry { int key; int value; };
extern "C" Entry D_00585C30[];

extern "C" int func_0040BAE0(void *self, int key)
{
    int r = D_00585C30[0].value; for (int i = 0; D_00585C30[i].key != -1; i++) { if (D_00585C30[i].key == key) { r = D_00585C30[i].value; break; } } return r;
}
