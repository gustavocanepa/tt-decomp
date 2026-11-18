/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned long u64;
struct S { char pad[0x24]; u32 data; char *tags; int head, count, bytes, sema; };
extern int D_00598414;
extern int D_00776D44, D_00776D48, D_00776D4C, D_00776D50, D_00776D54;
extern "C" int func_004FA750(int);
extern "C" void func_004FA840(int);
extern "C" int func_004FA860(int);
extern "C" int func_005038D8(void);
extern "C" int func_00503928(void);
#define REG(x) (*(volatile u32 *)(x))
#define SYNC() __asm__ volatile("sync" ::: "memory")
extern "C" int func_004BDF38(S *s) {
 int thread = D_00598414;
 if (thread != -1) func_004FA750(thread);
 func_004FA860(s->sema);
 int tag = 4;
 func_005038D8();
 u32 saved = REG(0x1000f520);
 REG(0x1000f590) = saved | 0x10000; SYNC();
 REG(0x1000b400) = tag; SYNC();
 REG(0x1000f590) = saved; SYNC();
 func_00503928();
 u32 control = REG(0x1000b400);
 char *tags = s->tags;
 u32 index;
 switch (REG(0x1000b410) == (((u32)tags + D_00776D44*16+16) & 0xfffffff)) {
 case 0: index = ((u32)*(int *)0x1000b410 - s->data) >> D_00776D4C; break;
 default: index = 0; break;
 }
 int consumed = ((index - s->head) + D_00776D44) & D_00776D48;
 int count = s->count - consumed;
 int head = (s->head + consumed) & D_00776D48;
 int bytes = s->bytes;
 s->count = count;
 s->head = head;
 int blocks = bytes >> D_00776D4C;
 s->bytes = bytes & D_00776D54;
 if (blocks > 0) {
  int end = head + count;
  index = (end + D_00776D44 - 1) & D_00776D48;
  tag = (D_00776D50 >> 4) & 0xffff;
  tag |= 0x30000000;
  *(u64 *)(tags + index * 16) = tag | ((u64)((s->data + (index << D_00776D4C)) & 0xfffffff) << 32);
  index = end & D_00776D48;
  for (int k = 0; k < blocks - 1; k++) {
   *(u64 *)(s->tags + index * 16) = tag | ((u64)((s->data + (index << D_00776D4C)) & 0xfffffff) << 32);
   index = (index + 1) & D_00776D48;
  }
  tag &= 0x8fffffff;
  *(u64 *)(s->tags + index * 16) = (u32)tag | ((u64)((s->data + (index << D_00776D4C)) & 0xfffffff) << 32);
  s->count += blocks;
 }
 if (s->count != 0) {
  if (blocks > 0) control = (control & 0x8fffffff) | 0x30000000;
  func_005038D8();
  saved = REG(0x1000f520);
  REG(0x1000f590) = saved | 0x10000; SYNC();
  REG(0x1000b400) = control | 0x100; SYNC();
  REG(0x1000f590) = saved; SYNC();
  func_00503928();
 }
 func_004FA840(s->sema);
 return 0;
}
