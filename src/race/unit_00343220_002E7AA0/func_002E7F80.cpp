extern "C" void func_002E7BE0(void *self, int n);
extern "C" void AutomobileControlRecord__Recorder__read(void *self, void *out);

extern "C" void func_002E7F80(void *self, int n, int keep)
{
    char buf[0x20];
    if (!keep)
        func_002E7BE0(self, n);
    for (int i = 0; i < n; i++) AutomobileControlRecord__Recorder__read(self, buf);
}
