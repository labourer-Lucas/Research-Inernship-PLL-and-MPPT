/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DDSRF_PLL_block.h
 *
 * Code generated for Simulink model 'DDSRF_PLL_block'.
 *
 * Model version                  : 2.5
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Oct 12 18:53:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef DDSRF_PLL_block_h_
#define DDSRF_PLL_block_h_
#ifndef DDSRF_PLL_block_COMMON_INCLUDES_
#define DDSRF_PLL_block_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DDSRF_PLL_block_COMMON_INCLUDES_ */

#include "DDSRF_PLL_block_types.h"
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
  real32_T Fcn;                        /* '<S31>/Fcn' */
  real32_T Fcn1;                       /* '<S31>/Fcn1' */
  real32_T Fcn_d;                      /* '<S30>/Fcn' */
  real32_T Fcn1_j;                     /* '<S30>/Fcn1' */
} B_DDSRF_PLL_block_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real32_T DelayOneStep2_DSTATE;       /* '<S1>/Delay One Step2' */
  real32_T DelayOneStep3_DSTATE;       /* '<S1>/Delay One Step3' */
  real32_T LPF1_states;                /* '<S1>/LPF1' */
  real32_T Integrator_DSTATE;          /* '<S13>/Integrator' */
  real32_T LPF3_states;                /* '<S1>/LPF3' */
  real32_T DelayOneStep_DSTATE;        /* '<S1>/Delay One Step' */
  real32_T DelayOneStep1_DSTATE;       /* '<S1>/Delay One Step1' */
  real32_T DiscreteFilter_states;      /* '<S1>/Discrete Filter' */
  real32_T DiscreteFilter1_states;     /* '<S1>/Discrete Filter1' */
  real32_T DiscreteFilter2_states;     /* '<S1>/Discrete Filter2' */
  real32_T DiscreteFilter3_states;     /* '<S1>/Discrete Filter3' */
  int8_T Integrator_PrevResetState;    /* '<S13>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S13>/Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S5>/IC' */
} DW_DDSRF_PLL_block_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Conversion;           /* '<S11>/Conversion' */
  const uint8_T Compare;               /* '<S28>/Compare' */
  const uint8_T Compare_o;             /* '<S29>/Compare' */
} ConstB_DDSRF_PLL_block_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S9>/Gain3'
   */
  real32_T Gain3_Gain[9];

  /* Computed Parameter: Gain3_Gain_l
   * Referenced by: '<S26>/Gain3'
   */
  real32_T Gain3_Gain_l[9];
} ConstP_DDSRF_PLL_block_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T vabc[3];                    /* '<Root>/vabc' */
} ExtU_DDSRF_PLL_block_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Line_RMS;                   /* '<Root>/Line_RMS' */
  real32_T freq;                       /* '<Root>/freq' */
  real32_T theta;                      /* '<Root>/theta' */
  real32_T Vabc_hat[3];                /* '<Root>/Vabc_hat' */
  real32_T dq[2];                      /* '<Root>/dq' */
} ExtY_DDSRF_PLL_block_T;

/* Real-time Model Data Structure */
struct tag_RTM_DDSRF_PLL_block_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_DDSRF_PLL_block_T DDSRF_PLL_block_B;

/* Block states (default storage) */
extern DW_DDSRF_PLL_block_T DDSRF_PLL_block_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DDSRF_PLL_block_T DDSRF_PLL_block_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DDSRF_PLL_block_T DDSRF_PLL_block_Y;
extern const ConstB_DDSRF_PLL_block_T DDSRF_PLL_block_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_DDSRF_PLL_block_T DDSRF_PLL_block_ConstP;

/* Model entry point functions */
extern void DDSRF_PLL_block_initialize(void);
extern void DDSRF_PLL_block_step(void);
extern void DDSRF_PLL_block_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DDSRF_PLL_block_T *const DDSRF_PLL_block_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Saturation' : Eliminated Saturate block
 * Block '<S20>/Offset' : Unused code path elimination
 * Block '<S25>/Offset' : Unused code path elimination
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
 * '<Root>' : 'DDSRF_PLL_block'
 * '<S1>'   : 'DDSRF_PLL_block/Subsystem'
 * '<S2>'   : 'DDSRF_PLL_block/Subsystem/Decoupling'
 * '<S3>'   : 'DDSRF_PLL_block/Subsystem/Decoupling-'
 * '<S4>'   : 'DDSRF_PLL_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1'
 * '<S5>'   : 'DDSRF_PLL_block/Subsystem/Forward Euler integrator 2¦Ð wrapping1'
 * '<S6>'   : 'DDSRF_PLL_block/Subsystem/Negative siquence'
 * '<S7>'   : 'DDSRF_PLL_block/Subsystem/Positive siquence'
 * '<S8>'   : 'DDSRF_PLL_block/Subsystem/Root Square1'
 * '<S9>'   : 'DDSRF_PLL_block/Subsystem/abc to Alpha-Beta-Zero'
 * '<S10>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc'
 * '<S11>'  : 'DDSRF_PLL_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1/Data Type Conversion Inherited'
 * '<S12>'  : 'DDSRF_PLL_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1/Integrator (Discrete or Continuous)'
 * '<S13>'  : 'DDSRF_PLL_block/Subsystem/Discrete PI Controller with Integral Anti-Windup1/Integrator (Discrete or Continuous)/Discrete'
 * '<S14>'  : 'DDSRF_PLL_block/Subsystem/Forward Euler integrator 2¦Ð wrapping1/Compare To Constant'
 * '<S15>'  : 'DDSRF_PLL_block/Subsystem/Forward Euler integrator 2¦Ð wrapping1/Compare To Constant1'
 * '<S16>'  : 'DDSRF_PLL_block/Subsystem/Negative siquence/Variant'
 * '<S17>'  : 'DDSRF_PLL_block/Subsystem/Negative siquence/Variant/mcb'
 * '<S18>'  : 'DDSRF_PLL_block/Subsystem/Negative siquence/Variant/mcb/Park Transform'
 * '<S19>'  : 'DDSRF_PLL_block/Subsystem/Negative siquence/Variant/mcb/Park Transform/Two inputs CRL'
 * '<S20>'  : 'DDSRF_PLL_block/Subsystem/Negative siquence/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S21>'  : 'DDSRF_PLL_block/Subsystem/Positive siquence/Variant'
 * '<S22>'  : 'DDSRF_PLL_block/Subsystem/Positive siquence/Variant/mcb'
 * '<S23>'  : 'DDSRF_PLL_block/Subsystem/Positive siquence/Variant/mcb/Park Transform'
 * '<S24>'  : 'DDSRF_PLL_block/Subsystem/Positive siquence/Variant/mcb/Park Transform/Two inputs CRL'
 * '<S25>'  : 'DDSRF_PLL_block/Subsystem/Positive siquence/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S26>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S27>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S28>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S29>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S30>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S31>'  : 'DDSRF_PLL_block/Subsystem/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 */
#endif                                 /* DDSRF_PLL_block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
