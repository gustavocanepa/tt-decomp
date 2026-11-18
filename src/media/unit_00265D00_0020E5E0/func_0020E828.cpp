struct S {char pad[0xAC];unsigned a:4,b:4,c:4,rest:20;};
extern "C" void func_0020E828(S*p,int mask,int mode){switch(mode){case 0:p->b&=~mask;p->c&=~mask;break;case 1:p->b|=mask;p->c&=~mask;break;case 2:p->b&=~mask;p->c|=mask;break;case 3:p->b|=mask;p->c|=mask;break;}}
