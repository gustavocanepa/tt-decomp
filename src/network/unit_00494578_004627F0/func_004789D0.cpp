struct E {int a,b;unsigned char state,pad; signed char prev,next;int c,d;};
struct S {unsigned char pad[0xc30];E entries[32];char pad2[12];signed char first,last;short pad3;int other,current; int offset(int i){return i*20+0xc30;}};
extern "C" int func_0046FA30(S*,int);
extern "C" void func_004789D0(S* s,int i) {
 if((unsigned char)s->pad[0x2c2])s->entries[i+1].a=func_0046FA30(s,0);else s->entries[i+1].a=0;
 if(s->entries[i+1].b==s->current)s->current=0;
 int old=s->last;
 if(old>=0)s->entries[old].next=i;else s->first=i;
 E* p=(E*)((char*)s+s->offset(i));p->prev=old;p->next=-1;s->last=i;p->state=3;
}
