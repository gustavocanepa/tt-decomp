typedef short s16;

void func_002E8088(void *, int);

void func_005525D0(void *self, s16 *cur, s16 *target) {
    func_002E8088(self, *target - *cur);
    *cur = *target;
}
