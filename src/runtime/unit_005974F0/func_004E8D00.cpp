/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x00597A70.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Big {int unused,capacity,padding,other,n;unsigned words[1];};
extern "C" Big* func_004E8C80(Big*,int) throw();
extern "C" Big* func_004E8D00(Big* self,unsigned m,unsigned carry){
 int n=self->n;unsigned* p=self->words;int i=0;
 do {unsigned word=*p;unsigned low=(word&65535)*m;unsigned high=(word>>16)*m;unsigned sum=low+carry;high+=sum>>16;carry=high>>16;*p++=(high<<16)+(sum&65535);++i;}while(i<n);
 if(carry){if(n>=self->padding)self=func_004E8C80(self,self->capacity+1);self->words[n++]=carry;self->n=n;}
 return self;
}
