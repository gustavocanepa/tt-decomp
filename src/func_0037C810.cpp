/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { char pad[0x10]; float start, end; char rest[0x18]; };
struct S { char pad[0x30]; E *entries; };
extern "C" int func_0037C740(S *, int) throw() __attribute__((const));
extern "C" int func_0037C738(S *, int) throw();
extern "C" int func_0037C748(S *, float, int) throw();
static inline E *get(S *self, int i) { return (E *)(i * 0x30 + (int)self->entries); }
extern "C" int func_0037C810(S *self, E **out, int cap, int slot, float time, float range, float period) {
 int offset = func_0037C740(self, slot);
 int size = func_0037C738(self, slot);
 int index = func_0037C748(self, time, slot);
 int count = 0;
 float limit = period * 0.25f;
 if(limit <= range) range = limit;
 if(index >= 0) {
  int first = index + offset;
  int prev = index;
  float start = get(self,first)->start;
  float current = time;
  float delta = start - start;
  
  while(delta < range && count < cap) {
   --prev;
   if(prev < 0) { current += period; prev += size; start += period; }
   E *entry = get(self,prev + offset);
   if(entry->start <= current && current < entry->end) { out[count++] = entry; }
   delta = start - get(self,prev + offset)->start;
  }
  while(get(self,index + offset)->start <= time && count < cap) {
   E *entry = get(self,index + offset);
   if(time < entry->end) { out[count++] = entry; }
   ++index;
   if(index >= size) { time -= period; index -= size; }
  }
 }
 return count;
}
