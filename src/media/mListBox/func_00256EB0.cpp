extern "C" float func_00253E38(char *) throw();
extern "C" int func_00254218(char *) throw();
extern "C" float func_00254328(char *) throw();
extern "C" int func_00256EB0(char *self) {
 int index=*(int *)(self+0x14C);
 if (!(index+1 < func_00254218(self))) return 0;
 float width=func_00253E38(self);
 float total=func_00254328(self);
 return width < *(float *)(self+0x148)+total;
}
