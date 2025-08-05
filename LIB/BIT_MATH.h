#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

#define SET_BIT(val, bit)       ((val) |= (1 << (bit)))
#define CLEAR_BIT(val, bit)     ((val) &= ~(1 << (bit)))
#define TOGGLE_BIT(val, bit)    ((val) ^= (1 << (bit)))
#define GET_BIT(val, bit)       (((val) >> (bit)) & 1)
#define SET_BYTE(reg , byte)    (reg = byte)

#endif
