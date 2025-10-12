/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SRF_PLL_Block.h
 *
 * Code generated for Simulink model 'SRF_PLL_Block'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Oct 12 17:47:33 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SRF_PLL_Block_h_
#define SRF_PLL_Block_h_
#ifndef SRF_PLL_Block_COMMON_INCLUDES_
#define SRF_PLL_Block_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* SRF_PLL_Block_COMMON_INCLUDES_ */

#include "SRF_PLL_Block_types.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Fcn;                        /* '<S68>/Fcn' */
  real32_T Fcn1;                       /* '<S68>/Fcn1' */
  real32_T Fcn_c;                      /* '<S67>/Fcn' */
  real32_T Fcn1_a;                     /* '<S67>/Fcn1' */
  real32_T Fcn_e;                      /* '<S10>/Fcn' */
  real32_T Fcn1_d;                     /* '<S10>/Fcn1' */
  real32_T Fcn_b;                      /* '<S9>/Fcn' */
  real32_T Fcn1_k;                     /* '<S9>/Fcn1' */
} B_SRF_PLL_Block_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S45>/Integrator' */
  real32_T Delay1_DSTATE;              /* '<S1>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S1>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
} DW_SRF_PLL_Block_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint8_T Compare;               /* '<S7>/Compare' */
  const uint8_T Compare_l;             /* '<S8>/Compare' */
  const uint8_T Compare_g;             /* '<S65>/Compare' */
  const uint8_T Compare_p;             /* '<S66>/Compare' */
} ConstB_SRF_PLL_Block_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S5>/Gain3'
   */
  real32_T Gain3_Gain[9];

  /* Computed Parameter: Gain3_Gain_p
   * Referenced by: '<S63>/Gain3'
   */
  real32_T Gain3_Gain_p[9];
} ConstP_SRF_PLL_Block_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Vabc[3];                    /* '<Root>/Vabc' */
} ExtU_SRF_PLL_Block_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T theta;                      /* '<Root>/theta' */
  real_T Freq;                         /* '<Root>/Freq' */
  real32_T Vabc_hat[3];                /* '<Root>/Vabc_hat' */
} ExtY_SRF_PLL_Block_T;

/* Real-time Model Data Structure */
struct tag_RTM_SRF_PLL_Block_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_SRF_PLL_Block_T SRF_PLL_Block_B;

/* Block states (default storage) */
extern DW_SRF_PLL_Block_T SRF_PLL_Block_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_SRF_PLL_Block_T SRF_PLL_Block_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SRF_PLL_Block_T SRF_PLL_Block_Y;
extern const ConstB_SRF_PLL_Block_T SRF_PLL_Block_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_SRF_PLL_Block_T SRF_PLL_Block_ConstP;

/* Model entry point functions */
extern void SRF_PLL_Block_initialize(void);
extern void SRF_PLL_Block_step(void);
extern void SRF_PLL_Block_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SRF_PLL_Block_T *const SRF_PLL_Block_M;

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
 * '<Root>' : 'SRF_PLL_Block'
 * '<S1>'   : 'SRF_PLL_Block/Subsystem'
 * '<S2>'   : 'SRF_PLL_Block/Subsystem/Alpha-Beta-Zero to dq0'
 * '<S3>'   : 'SRF_PLL_Block/Subsystem/PID Controller'
 * '<S4>'   : 'SRF_PLL_Block/Subsystem/Root Square1'
 * '<S5>'   : 'SRF_PLL_Block/Subsystem/abc to Alpha-Beta-Zero'
 * '<S6>'   : 'SRF_PLL_Block/Subsystem/dq0 to abc'
 * '<S7>'   : 'SRF_PLL_Block/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S8>'   : 'SRF_PLL_Block/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S9>'   : 'SRF_PLL_Block/Subsystem/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S10>'  : 'SRF_PLL_Block/Subsystem/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S11>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Anti-windup'
 * '<S12>'  : 'SRF_PLL_Block/Subsystem/PID Controller/D Gain'
 * '<S13>'  : 'SRF_PLL_Block/Subsystem/PID Controller/External Derivative'
 * '<S14>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Filter'
 * '<S15>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Filter ICs'
 * '<S16>'  : 'SRF_PLL_Block/Subsystem/PID Controller/I Gain'
 * '<S17>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Ideal P Gain'
 * '<S18>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S19>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Integrator'
 * '<S20>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Integrator ICs'
 * '<S21>'  : 'SRF_PLL_Block/Subsystem/PID Controller/N Copy'
 * '<S22>'  : 'SRF_PLL_Block/Subsystem/PID Controller/N Gain'
 * '<S23>'  : 'SRF_PLL_Block/Subsystem/PID Controller/P Copy'
 * '<S24>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Parallel P Gain'
 * '<S25>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Reset Signal'
 * '<S26>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Saturation'
 * '<S27>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Saturation Fdbk'
 * '<S28>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Sum'
 * '<S29>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Sum Fdbk'
 * '<S30>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tracking Mode'
 * '<S31>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S32>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tsamp - Integral'
 * '<S33>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S34>'  : 'SRF_PLL_Block/Subsystem/PID Controller/postSat Signal'
 * '<S35>'  : 'SRF_PLL_Block/Subsystem/PID Controller/preInt Signal'
 * '<S36>'  : 'SRF_PLL_Block/Subsystem/PID Controller/preSat Signal'
 * '<S37>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S38>'  : 'SRF_PLL_Block/Subsystem/PID Controller/D Gain/Disabled'
 * '<S39>'  : 'SRF_PLL_Block/Subsystem/PID Controller/External Derivative/Disabled'
 * '<S40>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Filter/Disabled'
 * '<S41>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S42>'  : 'SRF_PLL_Block/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S43>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S44>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Integrator/Discrete'
 * '<S46>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S47>'  : 'SRF_PLL_Block/Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S48>'  : 'SRF_PLL_Block/Subsystem/PID Controller/N Gain/Disabled'
 * '<S49>'  : 'SRF_PLL_Block/Subsystem/PID Controller/P Copy/Disabled'
 * '<S50>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S51>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S52>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Saturation/Passthrough'
 * '<S53>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S54>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Sum/Sum_PI'
 * '<S55>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S56>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S57>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S59>'  : 'SRF_PLL_Block/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'SRF_PLL_Block/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S61>'  : 'SRF_PLL_Block/Subsystem/PID Controller/preInt Signal/Internal PreInt'
 * '<S62>'  : 'SRF_PLL_Block/Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S63>'  : 'SRF_PLL_Block/Subsystem/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S64>'  : 'SRF_PLL_Block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S65>'  : 'SRF_PLL_Block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S66>'  : 'SRF_PLL_Block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S67>'  : 'SRF_PLL_Block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S68>'  : 'SRF_PLL_Block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 */
#endif                                 /* SRF_PLL_Block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
