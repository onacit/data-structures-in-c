#ifndef DATA_STRUCTURES_IN_C_MISCELLANEOUS_H
#define DATA_STRUCTURES_IN_C_MISCELLANEOUS_H

int sprintf_ordinal_u(char *s, unsigned int c);

int snprintf_ordinal_u(char *s, size_t n, unsigned int c);

int sprintf_ordinal_lu(char *s, unsigned long int c);

int snprintf_ordinal_lu(char *s, size_t n, unsigned long int c);

int sprintf_ordinal_llu(char *s, unsigned long long int c);

int snprintf_ordinal_llu(char *s, size_t n, unsigned long long int c);

//#define sprintf_ordinal_u(S, C) _Generic((C), \
//  unsigned char:          ordinal_hhu,      \
//  unsigned short int:     ordinal_hu,       \
//  unsigned int:           ordinal_u,        \
//  unsigned long int:      ordinal_lu,       \
//  unsigned long long int: ordinal_llu,      \
//  default:                ordinal_u         \
//)(S, C)
//
//#define snprintf_ordinal_u(S, N, C) _Generic((C), \
//  unsigned char:          ordinal_hhu_n,         \
//  unsigned short int:     ordinal_hu_n,          \
//  unsigned int:           ordinal_u_n,           \
//  unsigned long int:      ordinal_lu_n,          \
//  unsigned long long int: ordinal_llu_n,         \
//  default:                ordinal_u              \
//)(S, N, C)

#endif //DATA_STRUCTURES_IN_C_MISCELLANEOUS_H
