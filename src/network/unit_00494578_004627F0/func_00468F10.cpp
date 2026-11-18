struct S { unsigned long long low:26,x:4,y:4,high:30; };
extern "C" void func_00468F10(S* s,int x,int y) {
 int a=1;
 while(a<10 && (1<<a)<x) ++a;
 int b=1;
 while(b<10 && (1<<b)<y) ++b;
 s->x=a;s->y=b;
}
