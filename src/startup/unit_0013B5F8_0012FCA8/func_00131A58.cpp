#include "types.h"
extern "C" s32 func_00408B58(s32);
extern "C" s32 func_0040DA58(s32);
extern "C" s32 func_00131B88(void*);
extern "C" void func_0045F468(s32, s32, s32, s32);
extern "C" char D_005E0FA8[];
extern "C" s32 D_00586EF8;
struct Car { char pad[0x14]; s32 db; };
extern "C" void func_00131A58(Car *self, s32 arg1, s32 arg2) {
  s32 handle=func_00408B58(self->db);
  s32 rc=func_0040DA58(handle);
  if (rc == 0) {
    func_0045F468(D_00586EF8,arg2,arg1,(s32)D_005E0FA8);
    return;
  }
  func_0045F468(D_00586EF8,arg2,arg1,func_00131B88(self));
}
