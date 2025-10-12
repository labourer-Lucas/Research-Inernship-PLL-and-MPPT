/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SRF_block_data.c
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

#include "SRF_block.h"

/* Invariant block signals (default storage) */
const ConstB_SRF_block_T SRF_block_ConstB = {
  0.0F,                                /* '<S8>/Conversion' */
  0U,                                  /* '<S20>/Compare' */
  1U                                   /* '<S21>/Compare' */
};

/* Constant parameters (default storage) */
const ConstP_SRF_block_T SRF_block_ConstP = {
  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S6>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain3_Gain_l
   * Referenced by: '<S18>/Gain3'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F, 1.0F, 1.0F, 1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
