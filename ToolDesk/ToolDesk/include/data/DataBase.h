/*
 * Copyright © 2018 Evgenii Zaitcev.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license.
 *
 * BSD License Usage
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3)The name of the author may not be used to
 *     endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <stddef.h>
#include <stdint.h>
#include <float.h>
#include <QString>

namespace DeskData {

// Integer
typedef int64_t Int;
//#define DataInt int64_t

// Size
typedef uint64_t Size;

// Float
// is always has 1 bit for sign, 11 bits for exponent and 52 bits for mantissa.
// It is 64 bits together.
#if FLT_RADIX == 2

#if FLT_MANT_DIG == 53
    #if FLT_MAX_EXP == 1024
        typedef float Double;
        #define DATA_DOUBLE
    #endif
#endif

#ifndef DATA_DOUBLE
    #if DBL_MANT_DIG == 53
        #if DBL_MAX_EXP == 1024
            typedef double Double;
            #define DATA_DOUBLE
        #endif
    #endif
#endif

#ifndef DATA_DOUBLE
    #if LDBL_MANT_DIG == 53
        #if LDBL_MAX_EXP == 1024
            typedef long double Double;
            #define DATA_DOUBLE
        #endif
    #endif
#endif

#endif // FLT_RADIX == 2

#ifndef DATA_DOUBLE
    Error! "DataDouble can not be defined for this architecture."
#endif
#undef DATA_DOUBLE

}

#endif // DATABASE_H
