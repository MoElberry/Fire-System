
#ifndef UTILS_H_
#define UTILS_H_


#define READ_BIT(reg,bit) ((reg>>bit)&1)

#define SET_BIT(reg,bit) (reg=reg|(1<<bit))

#define CLR_BIT(reg,bit) (reg=reg&(~(1<<bit)))

#define TOGGLE_BIT(reg,bit) (reg=reg^(1<<bit))

#if INTERPOLATION
u16 interpolation2(u16 x,u16 x1,u16 x2,u16 y1,u16 y2){
	u16 y;
	y=(((((u32)10*y2 *(x-x1))-((u32)10*y1*(x-x1))))/(x2-x1))+(y1 * 10) ;
	return y;
}

#endif


#endif /* UTILS_H_ */