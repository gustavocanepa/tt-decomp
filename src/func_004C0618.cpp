/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00777340[];
extern "C" void func_004C07B0();
extern "C" void *func_004F6678(void *, int, unsigned);
extern "C" void *exception__structor_0(int);
extern "C" void rbuf__structor_0(void *, int);
extern "C" void func_004C26B0(void *);
extern "C" void func_004C0908(void *, int, int);
extern "C" void func_004C0918(int);
extern "C" void func_004CEE70(void *);
extern "C" void func_004CEB90(void *, int);
extern "C" void func_004CEEC8(void *);
struct S { int pad[2]; void *buffer; int padc; void *table; char pad14[0x40]; int magic; int size; int pad5c; void *queue; void (*callback)(); int pad68; char data[8]; char pad74[0x9c]; int state; };
extern "C" void func_004C0618(S *self) {
    void **buffer = &self->buffer;
    self->table = D_00777340;
    self->magic = 0x424b5550;
    self->size = 5;
    self->callback = func_004C07B0;
    func_004F6678(self->data, 0, 8);
    void *p = exception__structor_0(0x44);
    rbuf__structor_0(p, 0x80);
    *buffer = p;
    func_004C26B0(p);
    func_004C0908(self, 0x14, 5);
    self->state = 0;
    func_004C0918(2);
    func_004CEE70(self);
    func_004CEB90(self->queue, 0);
    func_004CEEC8(self);
}
