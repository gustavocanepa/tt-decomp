/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x58]; unsigned char state[8]; };
extern "C" int func_002DED20(Obj *o) {
 int count = 0;
 for (int i=0; i<8; i++) {
  if (o->state[i] == 2) count++;
 }
 return count >= 3;
}
