struct S { int pad,capacity,position,mode; unsigned char *cursor; int remain,func_005AE2E8,err,failed; };
extern "C" void func_00459910(S*);
extern "C" int func_00459A38(S *self) {
 if(self->failed) return 0;
 if(self->mode!=7){func_00459910(self);self->mode=7;}
 if(!self->remain){self->err=1;self->failed=1;return 0;}
 int value=*self->cursor<<8;
 func_00459910(self);
 if(!self->remain){self->err=1;self->failed=1;return 0;}
 value|=*self->cursor;
 func_00459910(self);
 self->func_005AE2E8=1;
 return value;
}
