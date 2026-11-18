/* compiler: ee-gcc2.96-nogcse */
struct E { unsigned short key; char pad[0x1d]; unsigned char flag; };
struct T { unsigned short count; char pad[2]; E *entries; };
struct O { char pad[0x24]; T *t; };
extern "C" void func_00466DF8(E *, int) throw();
extern "C" void func_00467370(O *o, int key) {
 T *t = o->t;
 if (!t || !t->entries) return;
 int i=0;
 int count=t->count;
 if (count != 0) {
  int one=1;
  int off=0;
  do {
   E *entries=t->entries;
   if (key<0 || ((E *)(off+(int)entries))->key==key) {
    func_00466DF8((E *)((char *)entries+off),count);
    ((E *)(off+(int)t->entries))->flag=one;
    count=t->count;
   }
   i++;
   off+=0x20;
  } while(i<count);
 }
}
