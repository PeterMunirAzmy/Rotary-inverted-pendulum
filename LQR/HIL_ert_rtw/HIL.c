/*
 * File: HIL.c
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

#include "HIL.h"
#include "HIL_types.h"
#include "HIL_private.h"
#include <math.h>
#include "multiword_types.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_HIL_T HIL_B;

/* Block states (default storage) */
DW_HIL_T HIL_DW;

/* Real-time model */
static RT_MODEL_HIL_T HIL_M_;
RT_MODEL_HIL_T *const HIL_M = &HIL_M_;

/* Forward declaration for local functions */
static void HIL_SystemCore_release(codertarget_arduinobase_inter_T *obj);
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

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

static void HIL_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Enable pin' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<Root>/Enable pin' */
}

/* Model step function */
void HIL_step(void)
{
  int64m_T b_varargout_1;
  int64m_T b_varargout_2;
  real_T rtb_Sum;
  real_T rtb_theta0rad;
  real_T u0;
  uint8_T tmp;
  static const int64m_T tmp_0 = { { 0U, 0U }/* chunks */
  };

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/reset encoders'
   */
  if (HIL_DW.obj.SampleTime != HIL_P.MATLABSystem_SampleTime) {
    HIL_DW.obj.SampleTime = HIL_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  b_varargout_1 = tmp_0;
  b_varargout_2 = tmp_0;
  stepFunctionDualEncoder(&b_varargout_1, 1.0, &b_varargout_2, 1.0,
    HIL_P.resetencoders_Value, 1.0, HIL_P.resetencoders_Value, 1.0);

  /* End of MATLABSystem: '<Root>/MATLAB System' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  rtb_Sum = HIL_P.Gain_Gain * sMultiWord2Double(&b_varargout_2.chunks[0U], 2, 0)
    + HIL_P.Constant_Value;

  /* Math: '<S3>/Rem' incorporates:
   *  Bias: '<S3>/Bias'
   *  Constant: '<S3>/Constant1'
   */
  HIL_B.Rem = rt_remd_snf(rtb_Sum + HIL_P.Bias_Bias_m, HIL_P.Constant1_Value_c);

  /* Switch: '<S3>/Switch' */
  if (rtb_Sum > HIL_P.Switch_Threshold) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Bias: '<S3>/Bias1'
     */
    HIL_B.Switch = HIL_B.Rem + HIL_P.Bias1_Bias;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Bias: '<S3>/Bias2'
     *  Bias: '<S3>/Bias3'
     *  Constant: '<S3>/Constant2'
     *  Math: '<S3>/Rem1'
     */
    HIL_B.Switch = rt_remd_snf(rtb_Sum + HIL_P.Bias2_Bias, HIL_P.Constant2_Value)
      + HIL_P.Bias3_Bias;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Gain: '<Root>/Gain1' */
  rtb_theta0rad = HIL_P.Gain1_Gain * sMultiWord2Double(&b_varargout_1.chunks[0U],
    2, 0);

  /* Switch: '<S4>/Switch' */
  if (rtb_theta0rad > HIL_P.Switch_Threshold_o) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Bias: '<S4>/Bias'
     *  Bias: '<S4>/Bias1'
     *  Constant: '<S4>/Constant1'
     *  Math: '<S4>/Rem'
     */
    HIL_B.Switch_g = rt_remd_snf(rtb_theta0rad + HIL_P.Bias_Bias,
      HIL_P.Constant1_Value_b) + HIL_P.Bias1_Bias_i;
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  Bias: '<S4>/Bias2'
     *  Bias: '<S4>/Bias3'
     *  Constant: '<S4>/Constant2'
     *  Math: '<S4>/Rem1'
     */
    HIL_B.Switch_g = rt_remd_snf(rtb_theta0rad + HIL_P.Bias2_Bias_i,
      HIL_P.Constant2_Value_m) + HIL_P.Bias3_Bias_f;
  }

  /* End of Switch: '<S4>/Switch' */

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_theta0rad *= HIL_P.TSamp_WtEt;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  HIL_B.Diff = rtb_theta0rad - HIL_DW.UD_DSTATE;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Sum *= HIL_P.TSamp_WtEt_e;

  /* Sum: '<S1>/Diff' incorporates:
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  HIL_B.Diff_g = rtb_Sum - HIL_DW.UD_DSTATE_e;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Abs: '<Root>/Abs'
   */
  if (fabs(HIL_B.Switch) > HIL_P.Switch1_Threshold) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    HIL_B.controlaction = HIL_P.Constant1_Value;
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Gain: '<Root>/Gain4'
     *  SignalConversion generated from: '<Root>/Gain4'
     */
    HIL_B.controlaction = ((-HIL_P.k[0] * HIL_B.Switch_g + -HIL_P.k[1] *
      HIL_B.Switch) + -HIL_P.k[2] * HIL_B.Diff) + -HIL_P.k[3] * HIL_B.Diff_g;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch2' */
  if (HIL_B.controlaction > HIL_P.Switch2_Threshold) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    HIL_B.Switch2 = HIL_P.Constant3_Value;
  } else {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    HIL_B.Switch2 = HIL_P.Constant2_Value_g;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* MATLABSystem: '<Root>/Digital Output' */
  u0 = rt_roundd_snf(HIL_B.Switch2);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  /* Switch: '<Root>/Switch3' */
  if (HIL_B.controlaction > HIL_P.Switch3_Threshold) {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    HIL_B.Switch3 = HIL_P.Constant2_Value_g;
  } else {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    HIL_B.Switch3 = HIL_P.Constant5_Value;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  u0 = rt_roundd_snf(HIL_B.Switch3);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */
  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant7'
   */
  if (HIL_B.controlaction > HIL_P.Switch4_Threshold) {
    u0 = HIL_P.Constant4_Value;
  } else {
    u0 = HIL_P.Constant7_Value;
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Abs: '<Root>/Abs2'
   *  Constant: '<Root>/Constant6'
   *  Switch: '<Root>/Switch4'
   */
  u0 = (u0 + HIL_P.PWMBias) + fabs(HIL_B.controlaction);

  /* Saturate: '<Root>/Saturation' */
  if (u0 > HIL_P.PWMSat) {
    /* Saturate: '<Root>/Saturation' */
    HIL_B.Saturation = HIL_P.PWMSat;
  } else if (u0 < HIL_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    HIL_B.Saturation = HIL_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    HIL_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain3' */
  u0 = HIL_P.Gain3_Gain * HIL_B.Saturation;

  /* Start for MATLABSystem: '<Root>/Enable pin' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  /* MATLABSystem: '<Root>/Enable pin' */
  HIL_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);

  /* Start for MATLABSystem: '<Root>/Enable pin' */
  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/Enable pin' */
  MW_PWM_SetDutyCycle(HIL_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, -(u0 * 255.0 /
    255.0));

  /* Gain: '<Root>/Gain6' */
  HIL_B.Gain6 = HIL_P.Gain6_Gain * HIL_B.Switch_g;

  /* Gain: '<Root>/Gain2' */
  HIL_B.Gain2 = HIL_P.Gain2_Gain * HIL_B.Switch;

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  HIL_DW.UD_DSTATE = rtb_theta0rad;

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  HIL_DW.UD_DSTATE_e = rtb_Sum;

  {                                    /* Sample time: [0.005s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  HIL_M->Timing.taskTime0 =
    ((time_T)(++HIL_M->Timing.clockTick0)) * HIL_M->Timing.stepSize0;
}

/* Model initialize function */
void HIL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(HIL_M, -1);
  HIL_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  HIL_M->Sizes.checksums[0] = (524617411U);
  HIL_M->Sizes.checksums[1] = (3683696556U);
  HIL_M->Sizes.checksums[2] = (3330923037U);
  HIL_M->Sizes.checksums[3] = (1866485501U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    HIL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HIL_M->extModeInfo,
      &HIL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HIL_M->extModeInfo, HIL_M->Sizes.checksums);
    rteiSetTPtr(HIL_M->extModeInfo, rtmGetTPtr(HIL_M));
  }

  /* InitializeConditions for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  HIL_DW.UD_DSTATE = HIL_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  HIL_DW.UD_DSTATE_e = HIL_P.DiscreteDerivative_ICPrevScaled;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  HIL_DW.obj.matlabCodegenIsDeleted = false;
  HIL_DW.obj.SampleTime = HIL_P.MATLABSystem_SampleTime;
  HIL_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionDualEncoder(27.0, 1.0, 26.0, 1.0, 25.0, 1.0, 33.0, 1.0);
  HIL_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  HIL_DW.obj_b.matlabCodegenIsDeleted = false;
  HIL_DW.obj_b.isInitialized = 1;
  digitalIOSetup(13, 1);
  HIL_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  HIL_DW.obj_l.matlabCodegenIsDeleted = false;
  HIL_DW.obj_l.isInitialized = 1;
  digitalIOSetup(12, 1);
  HIL_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Enable pin' */
  HIL_DW.obj_j.matlabCodegenIsDeleted = false;
  HIL_DW.obj_j.isInitialized = 1;
  HIL_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(14U, 2000.0, 255.0);
  HIL_DW.obj_j.isSetupComplete = true;
}

/* Model terminate function */
void HIL_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!HIL_DW.obj.matlabCodegenIsDeleted) {
    HIL_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!HIL_DW.obj_b.matlabCodegenIsDeleted) {
    HIL_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!HIL_DW.obj_l.matlabCodegenIsDeleted) {
    HIL_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/Enable pin' */
  if (!HIL_DW.obj_j.matlabCodegenIsDeleted) {
    HIL_DW.obj_j.matlabCodegenIsDeleted = true;
    HIL_SystemCore_release(&HIL_DW.obj_j);
  }

  /* End of Terminate for MATLABSystem: '<Root>/Enable pin' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
