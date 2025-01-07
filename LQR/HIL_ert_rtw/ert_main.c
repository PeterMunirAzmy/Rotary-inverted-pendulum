/*
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "HIL.h"
#include "HIL_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "ext_mode.h"
#include "MW_ArduinoHWInit.h"
#include "mw_freertos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
SemaphoreHandle_t stopSem;
SemaphoreHandle_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
SemaphoreHandle_t rateTaskFcnRunningMutex[1];
int testForRateOverrun(int rateID);
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(HIL_M) == (NULL));
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);
    mw_osSemaphoreWaitEver(&rateTaskFcnRunningMutex[0]);
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      HIL_M->Timing.taskTime0;

    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    HIL_step();

    /* Get model outputs here */

    /* Trigger External Mode event */
    extmodeEvent(0, currentTime);
    mw_osSemaphoreRelease(&rateTaskFcnRunningMutex[0]);
    stopRequested = !((rtmGetErrorStatus(HIL_M) == (NULL)));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(HIL_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  HIL_terminate();
  extmodeReset();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int testForRateOverrun(int rateID)
{
  if (mw_osBinarySemaphoreTryLock(&rateTaskFcnRunningMutex[rateID]) == 0) {
    mw_osSemaphoreRelease(&rateTaskFcnRunningMutex[rateID]);
    return 0;                          /* Not overruning this rate */
  } else {
    onOverrunDetect(rateID);
    return 1;                          /* Overruning this rate */
  }
}

int app_main(int argc, char **argv)
{
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(HIL_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(argc, (const char_T **)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  /* Initialize model */
  HIL_initialize();

  /* External Mode initialization */
  errorCode = extmodeInit(HIL_M->extModeInfo, &rtmGetTFinal(HIL_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(HIL_M, true);
    }
  }

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.005, 0);

  /* Wait for stop semaphore */
  mw_osSemaphoreWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSemaphoreDelete(&timerTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }
  }

#endif

  {
    int idxMutex;
    for (idxMutex=0; idxMutex<1; idxMutex++)
      mw_osSemaphoreDelete(&rateTaskFcnRunningMutex[idxMutex]);
  }

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
