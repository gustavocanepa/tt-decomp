struct Str { char *p; int length() const { return ((int *)p)[-4]; } };
struct Data { char pad[0x10]; int id; };
struct VEntry { short delta, index; int (*fn)(void *); };
struct VObj { char pad[4]; void *vtable; };
extern "C" void func_00120608(void *, void *);
extern "C" void func_001205B0(void *, int);
extern "C" void func_002ADC48(void *, void *);
extern "C" void func_002ADBF0(void *, int);
extern "C" Str *func_002AFE68(void *);
extern "C" void func_003F69D0(int, const char *, int, int);
extern "C" char D_005E03B8[];
static inline const char *get_name(Str *s) {
  if (s->length() == 0) return D_005E03B8;
  s->p[s->length()] = 0;
  return s->p;
}
static inline int get_value(void *argv) {
  VObj *obj = *(VObj **)((char *)argv + 4);
  VEntry *e = (VEntry *)((char *)obj->vtable + 0x68);
  return e->fn((char *)obj + e->delta);
}
extern "C" void func_001226A8(void *ret, void *self, int argc, void *argv) {
  if (argc > 0) {
    int buf[4];
    int id;
    func_00120608(buf, self);
    id = ((Data *)buf[0])->id;
    func_001205B0(buf, 2);
    func_002ADC48(buf, argv);
    func_003F69D0(id, get_name(func_002AFE68((void *)buf[0])), argc < 2 ? 0 : get_value(argv), 4);
    func_002ADBF0(buf, 2);
  }
}
