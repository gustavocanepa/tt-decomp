/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short id, pad; int value; };
struct Row { int pad[2]; Entry entry; };
struct Table { int lock[2]; Entry entries[256]; unsigned char refs[0x1c]; int count; };
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);
extern "C" void RaceEventQueue__clear(Table *t,int id) {
 func_004A4930(t);
 int n=t->count;
 int j=0;
 for (int i=0;i<n;i++) {
  Row *e=(Row *)((char *)t+i*8);
  if(e->entry.id==id) t->count--;
  else t->entries[j++]=e->entry;
 }
 t->refs[id]=0;
 func_004A4970(t);
}
