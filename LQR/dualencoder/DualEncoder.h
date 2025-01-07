/* Copyright 2023 The MathWorks, Inc. */
#ifndef EXAMPLE_H
#define EXAMPLE_H
#if !( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
#ifdef __cplusplus
#include "rtwtypes.h"
extern "C" {
    #endif
    void stepFunctionDualEncoder(long long * Enc0_Count,int size_vector_1,long long *  Enc1_Count,int size_vector_2,int8_T Reset_Enc0,int size_vector_a,int8_T Reset_Enc1,int size_vector_b);
    void setupFunctionDualEncoder(int8_T  Enc0A_Pin,int size_vector__1,int8_T  Enc0B_Pin,int size_vector__2,int8_T  Enc1A_Pin,int size_vector__3,int8_T  Enc1B_Pin,int size_vector__4);
    #ifdef __cplusplus
}
#endif
#else
#define loop(void) (0)
#define setup(void) (0)
#endif
#endif