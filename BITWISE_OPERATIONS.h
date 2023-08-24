
#ifndef _BITWISE_OPERATIONS_H_
#define _BITWISE_OPERATIONS_H_


#define SETBIT(REG, BIT) (REG |= (1U<<BIT))
#define CLEARBIT(REG, BIT) (REG &= ~(1U<<BIT))
#define TOGGLEBIT(REG, BIT) (REG ^= (1U<<BIT))
#define CHECKBIT(REG, BIT) ((REG & 1U<<BIT))>>BIT



#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))
#define bit_check(byte,nbit) (((byte) &   (1<<(nbit))))>>nbit

#define portSet(port, val)  (port = val)

#endif /* _BITWISE_OPERATIONS_H_ */
