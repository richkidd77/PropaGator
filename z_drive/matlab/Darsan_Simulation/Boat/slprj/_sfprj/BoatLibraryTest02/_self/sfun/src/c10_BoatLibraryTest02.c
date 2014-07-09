/* Include files */

#include <stddef.h>
#include "blas.h"
#include "BoatLibraryTest02_sfun.h"
#include "c10_BoatLibraryTest02.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BoatLibraryTest02_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[11] = { "R", "FxyM", "nargin",
  "nargout", "Fx", "Fy", "M", "phi", "fx", "fy", "m" };

/* Function Declarations */
static void initialize_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance);
static void initialize_params_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance);
static void enable_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance);
static void disable_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct *
  chartInstance);
static void c10_update_debugger_state_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance);
static void set_sim_state_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance, const mxArray *c10_st);
static void finalize_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance);
static void sf_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance);
static void c10_chartstep_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance);
static void initSimStructsc10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_m, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3]);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9]);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(uint32_T c10_u);
static real_T c10_cosd(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T c10_x);
static boolean_T c10_isfinite(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, real_T c10_x);
static real_T c10_sind(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T c10_x);
static void c10_eml_scalar_eg(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_e_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_f_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_BoatLibraryTest02, const
  char_T *c10_identifier);
static uint8_T c10_g_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_cosd(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T *c10_x);
static void c10_b_sind(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T *c10_x);
static void init_dsm_address_info(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_BoatLibraryTest02 = 0U;
}

static void initialize_params_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance)
{
}

static void enable_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_b_hoistedGlobal;
  real_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_c_hoistedGlobal;
  real_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  uint8_T c10_d_hoistedGlobal;
  uint8_T c10_d_u;
  const mxArray *c10_e_y = NULL;
  real_T *c10_fx;
  real_T *c10_fy;
  real_T *c10_m;
  c10_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(4), FALSE);
  c10_hoistedGlobal = *c10_fx;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = *c10_fy;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_hoistedGlobal = *c10_m;
  c10_c_u = c10_c_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  c10_d_hoistedGlobal = chartInstance->c10_is_active_c10_BoatLibraryTest02;
  c10_d_u = c10_d_hoistedGlobal;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_fx;
  real_T *c10_fy;
  real_T *c10_m;
  c10_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  *c10_fx = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    0)), "fx");
  *c10_fy = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    1)), "fy");
  *c10_m = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u,
    2)), "m");
  chartInstance->c10_is_active_c10_BoatLibraryTest02 = c10_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 3)),
     "is_active_c10_BoatLibraryTest02");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_BoatLibraryTest02(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance)
{
}

static void sf_c10_BoatLibraryTest02(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance)
{
  real_T *c10_Fx;
  real_T *c10_fx;
  real_T *c10_Fy;
  real_T *c10_M;
  real_T *c10_fy;
  real_T *c10_m;
  real_T *c10_phi;
  c10_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c10_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_Fy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_Fx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_Fx, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_fx, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_Fy, 2U);
  _SFD_DATA_RANGE_CHECK(*c10_M, 3U);
  _SFD_DATA_RANGE_CHECK(*c10_fy, 4U);
  _SFD_DATA_RANGE_CHECK(*c10_m, 5U);
  _SFD_DATA_RANGE_CHECK(*c10_phi, 6U);
  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_BoatLibraryTest02(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_BoatLibraryTest02MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_chartstep_c10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance)
{
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_c_hoistedGlobal;
  real_T c10_d_hoistedGlobal;
  real_T c10_Fx;
  real_T c10_Fy;
  real_T c10_M;
  real_T c10_phi;
  uint32_T c10_debug_family_var_map[11];
  real_T c10_R[9];
  real_T c10_FxyM[3];
  real_T c10_nargin = 4.0;
  real_T c10_nargout = 3.0;
  real_T c10_fx;
  real_T c10_fy;
  real_T c10_m;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_d0;
  real_T c10_d1;
  int32_T c10_i0;
  int32_T c10_i1;
  static real_T c10_dv0[3] = { 0.0, 0.0, 1.0 };

  int32_T c10_i2;
  real_T c10_a[9];
  real_T c10_b[3];
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_i5;
  real_T c10_C[3];
  int32_T c10_i6;
  int32_T c10_i7;
  int32_T c10_i8;
  int32_T c10_i9;
  int32_T c10_i10;
  int32_T c10_i11;
  real_T *c10_b_Fx;
  real_T *c10_b_Fy;
  real_T *c10_b_M;
  real_T *c10_b_phi;
  real_T *c10_b_fx;
  real_T *c10_b_fy;
  real_T *c10_b_m;
  c10_b_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c10_b_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_b_fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_b_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_b_Fy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_b_fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_Fx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_Fx;
  c10_b_hoistedGlobal = *c10_b_Fy;
  c10_c_hoistedGlobal = *c10_b_M;
  c10_d_hoistedGlobal = *c10_b_phi;
  c10_Fx = c10_hoistedGlobal;
  c10_Fy = c10_b_hoistedGlobal;
  c10_M = c10_c_hoistedGlobal;
  c10_phi = c10_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_R, 0U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_FxyM, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 2U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 3U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_Fx, 4U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_Fy, 5U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_M, 6U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_phi, 7U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_fx, 8U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_fy, 9U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_m, 10U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_x = c10_phi;
  c10_b_x = c10_x;
  c10_b_x = muDoubleScalarSin(c10_b_x);
  c10_c_x = c10_phi;
  c10_d_x = c10_c_x;
  c10_d_x = muDoubleScalarCos(c10_d_x);
  c10_d0 = c10_phi;
  c10_b_cosd(chartInstance, &c10_d0);
  c10_d1 = c10_phi;
  c10_b_sind(chartInstance, &c10_d1);
  c10_R[0] = c10_d0;
  c10_R[3] = -c10_b_x;
  c10_R[6] = 0.0;
  c10_R[1] = c10_d1;
  c10_R[4] = c10_d_x;
  c10_R[7] = 0.0;
  c10_i0 = 0;
  for (c10_i1 = 0; c10_i1 < 3; c10_i1++) {
    c10_R[c10_i0 + 2] = c10_dv0[c10_i1];
    c10_i0 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 8);
  for (c10_i2 = 0; c10_i2 < 9; c10_i2++) {
    c10_a[c10_i2] = c10_R[c10_i2];
  }

  c10_b[0] = c10_Fx;
  c10_b[1] = c10_Fy;
  c10_b[2] = c10_M;
  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3++) {
    c10_FxyM[c10_i3] = 0.0;
  }

  for (c10_i4 = 0; c10_i4 < 3; c10_i4++) {
    c10_FxyM[c10_i4] = 0.0;
  }

  for (c10_i5 = 0; c10_i5 < 3; c10_i5++) {
    c10_C[c10_i5] = c10_FxyM[c10_i5];
  }

  for (c10_i6 = 0; c10_i6 < 3; c10_i6++) {
    c10_FxyM[c10_i6] = c10_C[c10_i6];
  }

  for (c10_i7 = 0; c10_i7 < 3; c10_i7++) {
    c10_C[c10_i7] = c10_FxyM[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 3; c10_i8++) {
    c10_FxyM[c10_i8] = c10_C[c10_i8];
  }

  for (c10_i9 = 0; c10_i9 < 3; c10_i9++) {
    c10_FxyM[c10_i9] = 0.0;
    c10_i10 = 0;
    for (c10_i11 = 0; c10_i11 < 3; c10_i11++) {
      c10_FxyM[c10_i9] += c10_a[c10_i10 + c10_i9] * c10_b[c10_i11];
      c10_i10 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  c10_fx = c10_FxyM[0];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 11);
  c10_fy = c10_FxyM[1];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  c10_m = c10_FxyM[2];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  *c10_b_fx = c10_fx;
  *c10_b_fy = c10_fy;
  *c10_b_m = c10_m;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
}

static void initSimStructsc10_BoatLibraryTest02
  (SFc10_BoatLibraryTest02InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_m, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_m), &c10_thisId);
  sf_mex_destroy(&c10_m);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d2;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d2, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d2;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_m;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_m = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_m), &c10_thisId);
  sf_mex_destroy(&c10_m);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i12;
  real_T c10_b_inData[3];
  int32_T c10_i13;
  real_T c10_u[3];
  const mxArray *c10_y = NULL;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i12 = 0; c10_i12 < 3; c10_i12++) {
    c10_b_inData[c10_i12] = (*(real_T (*)[3])c10_inData)[c10_i12];
  }

  for (c10_i13 = 0; c10_i13 < 3; c10_i13++) {
    c10_u[c10_i13] = c10_b_inData[c10_i13];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_c_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3])
{
  real_T c10_dv1[3];
  int32_T c10_i14;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i14 = 0; c10_i14 < 3; c10_i14++) {
    c10_y[c10_i14] = c10_dv1[c10_i14];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_FxyM;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[3];
  int32_T c10_i15;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_FxyM = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_FxyM), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_FxyM);
  for (c10_i15 = 0; c10_i15 < 3; c10_i15++) {
    (*(real_T (*)[3])c10_outData)[c10_i15] = c10_y[c10_i15];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i16;
  int32_T c10_i17;
  int32_T c10_i18;
  real_T c10_b_inData[9];
  int32_T c10_i19;
  int32_T c10_i20;
  int32_T c10_i21;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i16 = 0;
  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    for (c10_i18 = 0; c10_i18 < 3; c10_i18++) {
      c10_b_inData[c10_i18 + c10_i16] = (*(real_T (*)[9])c10_inData)[c10_i18 +
        c10_i16];
    }

    c10_i16 += 3;
  }

  c10_i19 = 0;
  for (c10_i20 = 0; c10_i20 < 3; c10_i20++) {
    for (c10_i21 = 0; c10_i21 < 3; c10_i21++) {
      c10_u[c10_i21 + c10_i19] = c10_b_inData[c10_i21 + c10_i19];
    }

    c10_i19 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9])
{
  real_T c10_dv2[9];
  int32_T c10_i22;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c10_i22 = 0; c10_i22 < 9; c10_i22++) {
    c10_y[c10_i22] = c10_dv2[c10_i22];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_R;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_R = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_R), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_R);
  c10_i23 = 0;
  for (c10_i24 = 0; c10_i24 < 3; c10_i24++) {
    for (c10_i25 = 0; c10_i25 < 3; c10_i25++) {
      (*(real_T (*)[9])c10_outData)[c10_i25 + c10_i23] = c10_y[c10_i25 + c10_i23];
    }

    c10_i23 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_BoatLibraryTest02_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 40, 1),
                FALSE);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  const mxArray *c10_rhs7 = NULL;
  const mxArray *c10_lhs7 = NULL;
  const mxArray *c10_rhs8 = NULL;
  const mxArray *c10_lhs8 = NULL;
  const mxArray *c10_rhs9 = NULL;
  const mxArray *c10_lhs9 = NULL;
  const mxArray *c10_rhs10 = NULL;
  const mxArray *c10_lhs10 = NULL;
  const mxArray *c10_rhs11 = NULL;
  const mxArray *c10_lhs11 = NULL;
  const mxArray *c10_rhs12 = NULL;
  const mxArray *c10_lhs12 = NULL;
  const mxArray *c10_rhs13 = NULL;
  const mxArray *c10_lhs13 = NULL;
  const mxArray *c10_rhs14 = NULL;
  const mxArray *c10_lhs14 = NULL;
  const mxArray *c10_rhs15 = NULL;
  const mxArray *c10_lhs15 = NULL;
  const mxArray *c10_rhs16 = NULL;
  const mxArray *c10_lhs16 = NULL;
  const mxArray *c10_rhs17 = NULL;
  const mxArray *c10_lhs17 = NULL;
  const mxArray *c10_rhs18 = NULL;
  const mxArray *c10_lhs18 = NULL;
  const mxArray *c10_rhs19 = NULL;
  const mxArray *c10_lhs19 = NULL;
  const mxArray *c10_rhs20 = NULL;
  const mxArray *c10_lhs20 = NULL;
  const mxArray *c10_rhs21 = NULL;
  const mxArray *c10_lhs21 = NULL;
  const mxArray *c10_rhs22 = NULL;
  const mxArray *c10_lhs22 = NULL;
  const mxArray *c10_rhs23 = NULL;
  const mxArray *c10_lhs23 = NULL;
  const mxArray *c10_rhs24 = NULL;
  const mxArray *c10_lhs24 = NULL;
  const mxArray *c10_rhs25 = NULL;
  const mxArray *c10_lhs25 = NULL;
  const mxArray *c10_rhs26 = NULL;
  const mxArray *c10_lhs26 = NULL;
  const mxArray *c10_rhs27 = NULL;
  const mxArray *c10_lhs27 = NULL;
  const mxArray *c10_rhs28 = NULL;
  const mxArray *c10_lhs28 = NULL;
  const mxArray *c10_rhs29 = NULL;
  const mxArray *c10_lhs29 = NULL;
  const mxArray *c10_rhs30 = NULL;
  const mxArray *c10_lhs30 = NULL;
  const mxArray *c10_rhs31 = NULL;
  const mxArray *c10_lhs31 = NULL;
  const mxArray *c10_rhs32 = NULL;
  const mxArray *c10_lhs32 = NULL;
  const mxArray *c10_rhs33 = NULL;
  const mxArray *c10_lhs33 = NULL;
  const mxArray *c10_rhs34 = NULL;
  const mxArray *c10_lhs34 = NULL;
  const mxArray *c10_rhs35 = NULL;
  const mxArray *c10_lhs35 = NULL;
  const mxArray *c10_rhs36 = NULL;
  const mxArray *c10_lhs36 = NULL;
  const mxArray *c10_rhs37 = NULL;
  const mxArray *c10_lhs37 = NULL;
  const mxArray *c10_rhs38 = NULL;
  const mxArray *c10_lhs38 = NULL;
  const mxArray *c10_rhs39 = NULL;
  const mxArray *c10_lhs39 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851972U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c10_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c10_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c10_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c10_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1373328108U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c10_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("rdivide"), "name", "name",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c10_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c10_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c10_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_div"), "name", "name",
                  15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731866U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c10_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("rem"), "name", "name", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c10_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c10_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c10_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1358207740U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c10_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("abs"), "name", "name", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c10_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c10_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c10_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mtimes"), "name", "name", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c10_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c10_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("sin"), "name", "name", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c10_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c10_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("sind"), "name", "name", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c10_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c10_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("cos"), "name", "name", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343851972U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c10_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c10_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mtimes"), "name", "name", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c10_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c10_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c10_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731870U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c10_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1299098368U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c10_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mtimes"), "name", "name", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c10_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c10_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c10_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 39);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1360303950U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c10_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c10_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs39), "lhs", "lhs",
                  39);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
  sf_mex_destroy(&c10_rhs7);
  sf_mex_destroy(&c10_lhs7);
  sf_mex_destroy(&c10_rhs8);
  sf_mex_destroy(&c10_lhs8);
  sf_mex_destroy(&c10_rhs9);
  sf_mex_destroy(&c10_lhs9);
  sf_mex_destroy(&c10_rhs10);
  sf_mex_destroy(&c10_lhs10);
  sf_mex_destroy(&c10_rhs11);
  sf_mex_destroy(&c10_lhs11);
  sf_mex_destroy(&c10_rhs12);
  sf_mex_destroy(&c10_lhs12);
  sf_mex_destroy(&c10_rhs13);
  sf_mex_destroy(&c10_lhs13);
  sf_mex_destroy(&c10_rhs14);
  sf_mex_destroy(&c10_lhs14);
  sf_mex_destroy(&c10_rhs15);
  sf_mex_destroy(&c10_lhs15);
  sf_mex_destroy(&c10_rhs16);
  sf_mex_destroy(&c10_lhs16);
  sf_mex_destroy(&c10_rhs17);
  sf_mex_destroy(&c10_lhs17);
  sf_mex_destroy(&c10_rhs18);
  sf_mex_destroy(&c10_lhs18);
  sf_mex_destroy(&c10_rhs19);
  sf_mex_destroy(&c10_lhs19);
  sf_mex_destroy(&c10_rhs20);
  sf_mex_destroy(&c10_lhs20);
  sf_mex_destroy(&c10_rhs21);
  sf_mex_destroy(&c10_lhs21);
  sf_mex_destroy(&c10_rhs22);
  sf_mex_destroy(&c10_lhs22);
  sf_mex_destroy(&c10_rhs23);
  sf_mex_destroy(&c10_lhs23);
  sf_mex_destroy(&c10_rhs24);
  sf_mex_destroy(&c10_lhs24);
  sf_mex_destroy(&c10_rhs25);
  sf_mex_destroy(&c10_lhs25);
  sf_mex_destroy(&c10_rhs26);
  sf_mex_destroy(&c10_lhs26);
  sf_mex_destroy(&c10_rhs27);
  sf_mex_destroy(&c10_lhs27);
  sf_mex_destroy(&c10_rhs28);
  sf_mex_destroy(&c10_lhs28);
  sf_mex_destroy(&c10_rhs29);
  sf_mex_destroy(&c10_lhs29);
  sf_mex_destroy(&c10_rhs30);
  sf_mex_destroy(&c10_lhs30);
  sf_mex_destroy(&c10_rhs31);
  sf_mex_destroy(&c10_lhs31);
  sf_mex_destroy(&c10_rhs32);
  sf_mex_destroy(&c10_lhs32);
  sf_mex_destroy(&c10_rhs33);
  sf_mex_destroy(&c10_lhs33);
  sf_mex_destroy(&c10_rhs34);
  sf_mex_destroy(&c10_lhs34);
  sf_mex_destroy(&c10_rhs35);
  sf_mex_destroy(&c10_lhs35);
  sf_mex_destroy(&c10_rhs36);
  sf_mex_destroy(&c10_lhs36);
  sf_mex_destroy(&c10_rhs37);
  sf_mex_destroy(&c10_lhs37);
  sf_mex_destroy(&c10_rhs38);
  sf_mex_destroy(&c10_lhs38);
  sf_mex_destroy(&c10_rhs39);
  sf_mex_destroy(&c10_lhs39);
}

static const mxArray *c10_emlrt_marshallOut(char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), FALSE);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c10_y;
}

static real_T c10_cosd(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T c10_x)
{
  real_T c10_b_x;
  c10_b_x = c10_x;
  c10_b_cosd(chartInstance, &c10_b_x);
  return c10_b_x;
}

static boolean_T c10_isfinite(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, real_T c10_x)
{
  real_T c10_b_x;
  boolean_T c10_b_b;
  boolean_T c10_b0;
  real_T c10_c_x;
  boolean_T c10_c_b;
  boolean_T c10_b1;
  c10_b_x = c10_x;
  c10_b_b = muDoubleScalarIsInf(c10_b_x);
  c10_b0 = !c10_b_b;
  c10_c_x = c10_x;
  c10_c_b = muDoubleScalarIsNaN(c10_c_x);
  c10_b1 = !c10_c_b;
  return c10_b0 && c10_b1;
}

static real_T c10_sind(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T c10_x)
{
  real_T c10_b_x;
  c10_b_x = c10_x;
  c10_b_sind(chartInstance, &c10_b_x);
  return c10_b_x;
}

static void c10_eml_scalar_eg(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance)
{
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_e_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i26;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i26, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i26;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_BoatLibraryTest02, const
  char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_BoatLibraryTest02), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_BoatLibraryTest02);
  return c10_y;
}

static uint8_T c10_g_emlrt_marshallIn(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_cosd(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T *c10_x)
{
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  real_T c10_xk;
  real_T c10_f_x;
  real_T c10_g_x;
  real_T c10_absx;
  real_T c10_h_x;
  real_T c10_i_x;
  real_T c10_b;
  int8_T c10_n;
  real_T c10_b_b;
  real_T c10_c_b;
  real_T c10_d_b;
  real_T c10_e_b;
  int8_T c10_b_n;
  c10_b_x = *c10_x;
  if (!c10_isfinite(chartInstance, c10_b_x)) {
    *c10_x = rtNaN;
  } else {
    c10_c_x = c10_b_x;
    c10_d_x = c10_c_x;
    c10_e_x = c10_d_x;
    c10_xk = c10_e_x;
    c10_d_x = muDoubleScalarRem(c10_xk, 360.0);
    c10_f_x = c10_d_x;
    c10_g_x = c10_f_x;
    c10_absx = muDoubleScalarAbs(c10_g_x);
    if (c10_absx > 180.0) {
      if (c10_d_x > 0.0) {
        c10_d_x -= 360.0;
      } else {
        c10_d_x += 360.0;
      }

      c10_h_x = c10_d_x;
      c10_i_x = c10_h_x;
      c10_absx = muDoubleScalarAbs(c10_i_x);
    }

    if (c10_absx <= 45.0) {
      c10_b = c10_d_x;
      c10_d_x = 0.017453292519943295 * c10_b;
      c10_n = 0;
    } else if (c10_absx <= 135.0) {
      if (c10_d_x > 0.0) {
        c10_b_b = c10_d_x - 90.0;
        c10_d_x = 0.017453292519943295 * c10_b_b;
        c10_n = 1;
      } else {
        c10_c_b = c10_d_x + 90.0;
        c10_d_x = 0.017453292519943295 * c10_c_b;
        c10_n = -1;
      }
    } else if (c10_d_x > 0.0) {
      c10_d_b = c10_d_x - 180.0;
      c10_d_x = 0.017453292519943295 * c10_d_b;
      c10_n = 2;
    } else {
      c10_e_b = c10_d_x + 180.0;
      c10_d_x = 0.017453292519943295 * c10_e_b;
      c10_n = -2;
    }

    c10_b_n = c10_n;
    c10_b_x = c10_d_x;
    if ((real_T)c10_b_n == 0.0) {
      *c10_x = muDoubleScalarCos(c10_b_x);
    } else if ((real_T)c10_b_n == 1.0) {
      *c10_x = -muDoubleScalarSin(c10_b_x);
    } else if ((real_T)c10_b_n == -1.0) {
      *c10_x = muDoubleScalarSin(c10_b_x);
    } else {
      *c10_x = -muDoubleScalarCos(c10_b_x);
    }
  }
}

static void c10_b_sind(SFc10_BoatLibraryTest02InstanceStruct *chartInstance,
  real_T *c10_x)
{
  real_T c10_b_x;
  real_T c10_d3;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  real_T c10_xk;
  real_T c10_f_x;
  real_T c10_g_x;
  real_T c10_absx;
  real_T c10_h_x;
  real_T c10_i_x;
  real_T c10_b;
  int8_T c10_n;
  real_T c10_b_b;
  real_T c10_c_b;
  real_T c10_d_b;
  real_T c10_e_b;
  int8_T c10_b_n;
  c10_b_x = *c10_x;
  if (!c10_isfinite(chartInstance, c10_b_x)) {
    c10_d3 = rtNaN;
  } else {
    c10_c_x = c10_b_x;
    c10_d_x = c10_c_x;
    c10_e_x = c10_d_x;
    c10_xk = c10_e_x;
    c10_d_x = muDoubleScalarRem(c10_xk, 360.0);
    c10_f_x = c10_d_x;
    c10_g_x = c10_f_x;
    c10_absx = muDoubleScalarAbs(c10_g_x);
    if (c10_absx > 180.0) {
      if (c10_d_x > 0.0) {
        c10_d_x -= 360.0;
      } else {
        c10_d_x += 360.0;
      }

      c10_h_x = c10_d_x;
      c10_i_x = c10_h_x;
      c10_absx = muDoubleScalarAbs(c10_i_x);
    }

    if (c10_absx <= 45.0) {
      c10_b = c10_d_x;
      c10_d_x = 0.017453292519943295 * c10_b;
      c10_n = 0;
    } else if (c10_absx <= 135.0) {
      if (c10_d_x > 0.0) {
        c10_b_b = c10_d_x - 90.0;
        c10_d_x = 0.017453292519943295 * c10_b_b;
        c10_n = 1;
      } else {
        c10_c_b = c10_d_x + 90.0;
        c10_d_x = 0.017453292519943295 * c10_c_b;
        c10_n = -1;
      }
    } else if (c10_d_x > 0.0) {
      c10_d_b = c10_d_x - 180.0;
      c10_d_x = 0.017453292519943295 * c10_d_b;
      c10_n = 2;
    } else {
      c10_e_b = c10_d_x + 180.0;
      c10_d_x = 0.017453292519943295 * c10_e_b;
      c10_n = -2;
    }

    c10_b_n = c10_n;
    c10_b_x = c10_d_x;
    if ((real_T)c10_b_n == 0.0) {
      c10_d3 = muDoubleScalarSin(c10_b_x);
    } else if ((real_T)c10_b_n == 1.0) {
      c10_d3 = muDoubleScalarCos(c10_b_x);
    } else if ((real_T)c10_b_n == -1.0) {
      c10_d3 = -muDoubleScalarCos(c10_b_x);
    } else {
      c10_d3 = -muDoubleScalarSin(c10_b_x);
    }
  }

  *c10_x = c10_d3;
}

static void init_dsm_address_info(SFc10_BoatLibraryTest02InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c10_BoatLibraryTest02_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4011210989U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1545947261U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3778665766U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2646130504U);
}

mxArray *sf_c10_BoatLibraryTest02_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("grq1SQLwJfFNzlDzvtBHoH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_BoatLibraryTest02_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_BoatLibraryTest02_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_BoatLibraryTest02(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"fx\",},{M[1],M[8],T\"fy\",},{M[1],M[9],T\"m\",},{M[8],M[0],T\"is_active_c10_BoatLibraryTest02\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_BoatLibraryTest02_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
    chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _BoatLibraryTest02MachineNumber_,
           10,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_BoatLibraryTest02MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_BoatLibraryTest02MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _BoatLibraryTest02MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Fx");
          _SFD_SET_DATA_PROPS(1,2,0,1,"fx");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Fy");
          _SFD_SET_DATA_PROPS(3,1,1,0,"M");
          _SFD_SET_DATA_PROPS(4,2,0,1,"fy");
          _SFD_SET_DATA_PROPS(5,2,0,1,"m");
          _SFD_SET_DATA_PROPS(6,1,1,0,"phi");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,242);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c10_Fx;
          real_T *c10_fx;
          real_T *c10_Fy;
          real_T *c10_M;
          real_T *c10_fy;
          real_T *c10_m;
          real_T *c10_phi;
          c10_phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c10_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c10_fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c10_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c10_Fy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c10_Fx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_Fx);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_fx);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_Fy);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_M);
          _SFD_SET_DATA_VALUE_PTR(4U, c10_fy);
          _SFD_SET_DATA_VALUE_PTR(5U, c10_m);
          _SFD_SET_DATA_VALUE_PTR(6U, c10_phi);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _BoatLibraryTest02MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XRFbqpw99xbtBQsPsPoV9C";
}

static void sf_opaque_initialize_c10_BoatLibraryTest02(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar);
  initialize_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_BoatLibraryTest02(void *chartInstanceVar)
{
  enable_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_BoatLibraryTest02(void *chartInstanceVar)
{
  disable_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_BoatLibraryTest02(void *chartInstanceVar)
{
  sf_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_BoatLibraryTest02(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_BoatLibraryTest02
    ((SFc10_BoatLibraryTest02InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_BoatLibraryTest02();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c10_BoatLibraryTest02(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_BoatLibraryTest02();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_BoatLibraryTest02(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_BoatLibraryTest02(S);
}

static void sf_opaque_set_sim_state_c10_BoatLibraryTest02(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c10_BoatLibraryTest02(S, st);
}

static void sf_opaque_terminate_c10_BoatLibraryTest02(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_BoatLibraryTest02InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_BoatLibraryTest02_optimization_info();
    }

    finalize_c10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_BoatLibraryTest02((SFc10_BoatLibraryTest02InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_BoatLibraryTest02(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_BoatLibraryTest02
      ((SFc10_BoatLibraryTest02InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_BoatLibraryTest02(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BoatLibraryTest02_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1603684670U));
  ssSetChecksum1(S,(8876978U));
  ssSetChecksum2(S,(4075276325U));
  ssSetChecksum3(S,(4088645870U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_BoatLibraryTest02(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_BoatLibraryTest02(SimStruct *S)
{
  SFc10_BoatLibraryTest02InstanceStruct *chartInstance;
  chartInstance = (SFc10_BoatLibraryTest02InstanceStruct *)utMalloc(sizeof
    (SFc10_BoatLibraryTest02InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_BoatLibraryTest02InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_BoatLibraryTest02;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_BoatLibraryTest02;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_BoatLibraryTest02;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_BoatLibraryTest02;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_BoatLibraryTest02;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_BoatLibraryTest02;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_BoatLibraryTest02;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_BoatLibraryTest02;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_BoatLibraryTest02;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_BoatLibraryTest02;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_BoatLibraryTest02;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c10_BoatLibraryTest02_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_BoatLibraryTest02(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_BoatLibraryTest02(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_BoatLibraryTest02(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_BoatLibraryTest02_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}