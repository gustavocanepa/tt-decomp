extern "C" float func_00253E38(char *) throw();
extern "C" float func_00254328(char *) throw();
extern "C" float func_00256DE0(char *self) {
 float width=func_00253E38(self);
 float total=func_00254328(self);
 float pos=-*(float *)(self+0x148);
 if (pos < 0.0f) return 0.0f;
 float max=1.0f-width/total;
 float ratio=pos/total;
 if (max <= ratio) return max;
 return ratio;
}
