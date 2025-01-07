/*
 * File: HIL.h
 *
 * Code generated for Simulink model 'HIL'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan  2 10:55:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HIL_h_
#define RTW_HEADER_HIL_h_
#ifndef HIL_COMMON_INCLUDES_
#define HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "DualEncoder.h"
#endif                                 /* HIL_COMMON_INCLUDES_ */

#include "HIL_types.h"
#include "rtGetNaN.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Rem;                          /* '<S3>/Rem' */
  real_T Switch;                       /* '<S3>/Switch' */
  real_T Switch_g;                     /* '<S4>/Switch' */
  real_T Diff;                         /* '<S2>/Diff' */
  real_T Diff_g;                       /* '<S1>/Diff' */
  real_T controlaction;                /* '<Root>/Switch1' */
  real_T Switch2;                      /* '<Root>/Switch2' */
  real_T Switch3;                      /* '<Root>/Switch3' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Gain2;                        /* '<Root>/Gain2' */
} B_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DualEncoder_HIL_T obj;               /* '<Root>/MATLAB System' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_b;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_j;/* '<Root>/Enable pin' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
  real_T UD_DSTATE_e;                  /* '<S1>/UD' */
  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S3>/Scope' */
} DW_HIL_T;

/* Parameters (default storage) */
struct P_HIL_T_ {
  real_T PWMBias;                      /* Variable: PWMBias
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T PWMSat;                       /* Variable: PWMSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T k[4];                         /* Variable: k
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S2>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 5
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Bias1_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S3>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Bias2_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S3>/Bias2'
                                        */
  real_T Bias3_Bias;                   /* Expression: pi
                                        * Referenced by: '<S3>/Bias3'
                                        */
  real_T Constant1_Value_b;            /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: pi
                                        * Referenced by: '<S4>/Bias'
                                        */
  real_T Bias1_Bias_i;                 /* Expression: -pi
                                        * Referenced by: '<S4>/Bias1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Bias2_Bias_i;                 /* Expression: -pi
                                        * Referenced by: '<S4>/Bias2'
                                        */
  real_T Bias3_Bias_f;                 /* Expression: pi
                                        * Referenced by: '<S4>/Bias3'
                                        */
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 2*pi/2400
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Bias_Bias_m;                  /* Expression: pi
                                        * Referenced by: '<S3>/Bias'
                                        */
  real_T Constant1_Value_c;            /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.9
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch4'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain6_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain2_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain2'
                                        */
  int8_T resetencoders_Value;          /* Expression: int8(0)
                                        * Referenced by: '<Root>/reset encoders'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_HIL_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_HIL_T HIL_P;

/* Block signals (default storage) */
extern B_HIL_T HIL_B;

/* Block states (default storage) */
extern DW_HIL_T HIL_DW;

/* Model entry point functions */
extern void HIL_initialize(void);
extern void HIL_step(void);
extern void HIL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HIL_T *const HIL_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HIL'
 * '<S1>'   : 'HIL/Discrete Derivative'
 * '<S2>'   : 'HIL/Discrete Derivative1'
 * '<S3>'   : 'HIL/wraping angle'
 * '<S4>'   : 'HIL/wraping angle1'
 */
#endif                                 /* RTW_HEADER_HIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
