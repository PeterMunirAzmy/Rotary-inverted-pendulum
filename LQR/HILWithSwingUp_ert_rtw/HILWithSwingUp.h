/*
 * File: HILWithSwingUp.h
 *
 * Code generated for Simulink model 'HILWithSwingUp'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan  2 04:50:25 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HILWithSwingUp_h_
#define RTW_HEADER_HILWithSwingUp_h_
#ifndef HILWithSwingUp_COMMON_INCLUDES_
#define HILWithSwingUp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "DualEncoder.h"
#endif                                 /* HILWithSwingUp_COMMON_INCLUDES_ */

#include "HILWithSwingUp_types.h"
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
  real_T Switch;                       /* '<S5>/Switch' */
  real_T Rem;                          /* '<S4>/Rem' */
  real_T Switch_e;                     /* '<S4>/Switch' */
  real_T Diff;                         /* '<S3>/Diff' */
  real_T Diff_f;                       /* '<S2>/Diff' */
  real_T Gain8;                        /* '<Root>/Gain8' */
  real_T controlaction;                /* '<Root>/Switch4' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Abs1;                         /* '<Root>/Abs1' */
  real_T Switch5;                      /* '<Root>/Switch5' */
  real_T Switch6;                      /* '<Root>/Switch6' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Gain9;                        /* '<Root>/Gain9' */
  real_T pwm;                          /* '<Root>/Chart1' */
} B_HILWithSwingUp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DualEncoder_HILWithSwingUp_T obj;    /* '<Root>/MATLAB System' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Enable pin' */
  real_T UD_DSTATE;                    /* '<S3>/UD' */
  real_T UD_DSTATE_a;                  /* '<S2>/UD' */
  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     /* '<S4>/Scope' */

  uint32_T is_c1_HILWithSwingUp;       /* '<Root>/Chart1' */
  uint8_T is_active_c1_HILWithSwingUp; /* '<Root>/Chart1' */
} DW_HILWithSwingUp_T;

/* Parameters (default storage) */
struct P_HILWithSwingUp_T_ {
  real_T PWMBias;                      /* Variable: PWMBias
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T PWMSat;                       /* Variable: PWMSat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T k[4];                         /* Variable: k
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T DiscreteDerivative3_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative3_ICPrevScale
                               * Referenced by: '<S3>/UD'
                               */
  real_T DiscreteDerivative2_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                               * Referenced by: '<S2>/UD'
                               */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant8_Value;              /* Expression: 5
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Bias1_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S4>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Bias2_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S4>/Bias2'
                                        */
  real_T Bias3_Bias;                   /* Expression: pi
                                        * Referenced by: '<S4>/Bias3'
                                        */
  real_T Constant1_Value_i;            /* Expression: 2*pi
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: pi
                                        * Referenced by: '<S5>/Bias'
                                        */
  real_T Bias1_Bias_l;                 /* Expression: -pi
                                        * Referenced by: '<S5>/Bias1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 2*pi
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Bias2_Bias_p;                 /* Expression: -pi
                                        * Referenced by: '<S5>/Bias2'
                                        */
  real_T Bias3_Bias_p;                 /* Expression: pi
                                        * Referenced by: '<S5>/Bias3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2*pi/2400
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Bias_Bias_d;                  /* Expression: pi
                                        * Referenced by: '<S4>/Bias'
                                        */
  real_T Constant1_Value_j;            /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S3>/TSamp'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch4'
                                        */
  real_T Constant2_Value_c;            /* Expression: 100
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch5'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch6'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch7'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain7_Gain;                   /* Expression: 0
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T Gain6_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain9_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain9'
                                        */
  int8_T resetencoders_Value;          /* Expression: int8(0)
                                        * Referenced by: '<Root>/reset encoders'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_HILWithSwingUp_T {
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
extern P_HILWithSwingUp_T HILWithSwingUp_P;

/* Block signals (default storage) */
extern B_HILWithSwingUp_T HILWithSwingUp_B;

/* Block states (default storage) */
extern DW_HILWithSwingUp_T HILWithSwingUp_DW;

/* Model entry point functions */
extern void HILWithSwingUp_initialize(void);
extern void HILWithSwingUp_step(void);
extern void HILWithSwingUp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HILWithSwingUp_T *const HILWithSwingUp_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'HILWithSwingUp'
 * '<S1>'   : 'HILWithSwingUp/Chart1'
 * '<S2>'   : 'HILWithSwingUp/Discrete Derivative2'
 * '<S3>'   : 'HILWithSwingUp/Discrete Derivative3'
 * '<S4>'   : 'HILWithSwingUp/wraping angle2'
 * '<S5>'   : 'HILWithSwingUp/wraping angle3'
 */
#endif                                 /* RTW_HEADER_HILWithSwingUp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
