/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Dec 30 20:24:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void untitled_step(void)
{
  real_T y;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  y = rt_roundd_snf(untitled_P.Constant_Value);
  if (y < 256.0) {
    if (y >= 0.0) {
      tmp = (uint8_T)y;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output3' */

  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  y = rt_roundd_snf(untitled_P.Constant1_Value);
  if (y < 256.0) {
    if (y >= 0.0) {
      tmp = (uint8_T)y;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* MATLABSystem: '<Root>/Enable pin1' */
  untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);

  /* Start for MATLABSystem: '<Root>/Enable pin1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (untitled_P.Constant2_Value <= 255.0) {
    y = untitled_P.Constant2_Value;
  } else {
    y = 255.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  /* MATLABSystem: '<Root>/Enable pin1' */
  MW_PWM_SetDutyCycle(untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, y);

  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (4182314231U);
  untitled_M->Sizes.checksums[1] = (203138483U);
  untitled_M->Sizes.checksums[2] = (4139724280U);
  untitled_M->Sizes.checksums[3] = (2394771005U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1;
  digitalIOSetup(13, 1);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  untitled_DW.obj_p.matlabCodegenIsDeleted = false;
  untitled_DW.obj_p.isInitialized = 1;
  digitalIOSetup(12, 1);
  untitled_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Enable pin1' */
  untitled_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled_DW.obj_h.isInitialized = 1;
  untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(14U, 0.0, 0.0);
  untitled_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!untitled_DW.obj_p.matlabCodegenIsDeleted) {
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Enable pin1' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_h.isInitialized == 1) &&
        untitled_DW.obj_h.isSetupComplete) {
      untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
      MW_PWM_SetDutyCycle(untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
      MW_PWM_Close(untitled_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Enable pin1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
