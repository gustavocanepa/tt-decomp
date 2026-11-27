/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *); };
struct Self { int x0; void *data; int size; int xc; int key; int value; int x18; VEntry *vt; };
struct Src { int x0, x4, size, xc, value; };
extern "C" void func_004C3E18(void *, int);
extern "C" void func_004A45D0(void *) throw();
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void func_0042D8E0(Self *self, Src *src, int flag) {
 int size, value;
 if (flag == 0) {
  size = src->size;
  value = src->value;
  func_004F64C4(self->data, src, size);
 } else {
  func_004C3E18(src, self->key);
  size = src->size;
  void *data = self->data;
  value = src->value;
  func_004F64C4(data, src, size);
  func_004C3E18(data, self->key);
 }
 self->size = size;
 self->value = value;
 func_004A45D0(src);
 VEntry *e = self->vt + 2;
 e->fn((char *)self + e->delta);
}
