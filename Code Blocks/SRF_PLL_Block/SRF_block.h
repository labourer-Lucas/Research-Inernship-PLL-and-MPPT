/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SRF_block.h
 *
 * Code generated for Simulink model 'SRF_block'.
 *
 * Model version                  : 2.8
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Oct 12 18:48:18 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SRF_block_h_
#define SRF_block_h_
#ifndef SRF_block_COMMON_INCLUDES_
#define SRF_block_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SRF_block_COMMON_INCLUDES_ */

#include "SRF_block_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Fcn;                        /* '<S23>/Fcn' */
  real32_T Fcn1;                       /* '<S23>/Fcn1' */
  real32_T Fcn_d;                      /* '<S22>/Fcn' */
  real32_T Fcn1_j;                     /* '<S22>/Fcn1' */
} B_SRF_block_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T LPF1_states;                /* '<S1>/LPF1' */
  real32_T Integrator_DSTATE;          /* '<S10>/Integrator' */
  real32_T LPF3_states;                /* '<S1>/LPF3' */
  int8_T Integrator_PrevResetState;    /* '<S10>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S10>/Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S3>/IC' */
} DW_SRF_block_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Conversion;           /* '<S8>/Conversion' */
  const uint8_T Compare;               /* '<S20>/Compare' */
  const uint8_T Compare_o;             /* '<S21>/Compare' */
} ConstB_SRF_block_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S6>/Gain3'
   */
  real32_T Gain3_Gain[9];

  /* Computed Parameter: Gain3_Gain_l
   * Referenced by: '<S18>/Gain3'
   */
  real32_T Gain3_Gain_l[9];
} ConstP_SRF_block_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T vabc[3];                    /* '<Root>/vabc' */
} ExtU_SRF_block_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Line_RMS;                   /* '<Root>/Line_RMS' */
  real32_T freq;                       /* '<Root>/freq' */
  real32_T theta;                      /* '<Root>/theta' */
  real32_T Vabc_hat[3];                /* '<Root>/Vabc_hat' */
  real32_T dq[2];                      /* '<Root>/dq' */
} ExtY_SRF_block_T;

/* Real-time Model Data Structure */
struct tag_RTM_SRF_block_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_SRF_block_T SRF_block_B;

/* Block states (default storage) */
extern DW_SRF_block_T SRF_block_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_SRF_block_T SRF_block_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SRF_block_T SRF_block_Y;
extern const ConstB_SRF_block_T SRF_block_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_SRF_block_T SRF_block_ConstP;

/* Model entry point functions */
extern void SRF_block_initialize(void);
extern void SRF_block_step(void);
extern void SRF_block_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SRF_block_T *const SRF_block_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Saturation' : Eliminated Saturate block
 * Block '<S17>/Offset' : Unused code path elimination
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
 * '<Root>' : 'SRF_block'
 * '<S1>'   : 'SRF_block/Subsystem'
 * '<S2>'   : 'SRF_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1'
 * '<S3>'   : 'SRF_block/Subsystem/Forward Euler integrator 2¦Ð wrapping1'
 * '<S4>'   : 'SRF_block/Subsystem/Positive siquence'
 * '<S5>'   : 'SRF_block/Subsystem/Root Square1'
 * '<S6>'   : 'SRF_block/Subsystem/abc to Alpha-Beta-Zero'
 * '<S7>'   : 'SRF_block/Subsystem/dq0 to abc'
 * '<S8>'   : 'SRF_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1/Data Type Conversion Inherited'
 * '<S9>'   : 'SRF_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1/Integrator (Discrete or Continuous)'
 * '<S10>'  : 'SRF_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1/Integrator (Discrete or Continuous)/Discrete'
 * '<S11>'  : 'SRF_block/Subsystem/Forward Euler integrator 2¦Ð wrapping1/Compare To Constant'
 * '<S12>'  : 'SRF_block/Subsystem/Forward Euler integrator 2¦Ð wrapping1/Compare To Constant1'
 * '<S13>'  : 'SRF_block/Subsystem/Positive siquence/Variant'
 * '<S14>'  : 'SRF_block/Subsystem/Positive siquence/Variant/mcb'
 * '<S15>'  : 'SRF_block/Subsystem/Positive siquence/Variant/mcb/Park Transform'
 * '<S16>'  : 'SRF_block/Subsystem/Positive siquence/Variant/mcb/Park Transform/Two inputs CRL'
 * '<S17>'  : 'SRF_block/Subsystem/Positive siquence/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S18>'  : 'SRF_block/Subsystem/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S19>'  : 'SRF_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S20>'  : 'SRF_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S21>'  : 'SRF_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S22>'  : 'SRF_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S23>'  : 'SRF_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 */
#endif                                 /* SRF_block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
