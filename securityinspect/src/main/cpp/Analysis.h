//
// Created by qtfreet00 on 2018/1/22.
//

#ifndef VADETECT_ANALYSIS_H
#define VADETECT_ANALYSIS_H


#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include "Syscalls.h"

using namespace std;
#ifndef INLINE
#define INLINE inline
#endif

#ifndef ALWAYS_INLINE
#define ALWAYS_INLINE INLINE __attribute__((always_inline))
#endif


void findInMaps(int, const char *filter, vector<string> &result);

int countPathFromUid();


#endif //VADETECT_ANALYSIS_H
