/* compiler: ee-gcc2.9-991111 */
extern int func_00502898(void);
extern int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
extern char D_0078F700[];
extern int D_0078F500[8];
int func_00503518(int addr, void *src, int type) {
 if (func_00502898()<0) return 0xffff0000;
 D_0078F500[0]=addr;
 D_0078F500[1]=type;
 if (type==0) *(unsigned char *)&D_0078F500[2]=*(unsigned char *)src;
 else if (type==1) *(unsigned short *)&D_0078F500[2]=*(unsigned short *)src;
 else if (type==2) D_0078F500[2]=*(int *)src;
 else return 0xfffefffe;
 if (func_004FE530(D_0078F700,2,0,D_0078F500,32,D_0078F500,16,0,0)<0) return 0xfffeffff;
 return 0;
}
