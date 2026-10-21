/* compiler: ee-gcc2.96-nogcse */
struct Table { int count; int pad; void **items; };
struct Obj { char pad[0x60]; Table *table; };
extern "C" int func_003A7FE8(void *) throw();
extern "C" int func_003A8140(Obj *self, int start) {
 int i = 0;
 long n = self->table->count;
 int divisor = self->table->count;
 if (n > 0) {
   do {
     int index = (start + i) % divisor;
     ++i;
     if (func_003A7FE8(self->table->items[index])) return index;
   } while (i < n);
 }
 return start;
}
