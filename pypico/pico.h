#ifndef __PYX_HAVE__pypico__pico
#define __PYX_HAVE__pypico__pico


/* "pypico/pico.pyx":4
 * # See corresponding line in fpico_interface.f90
 * from libc.stdint cimport uint32_t, uint64_t
 * ctypedef public uint64_t fpint             # <<<<<<<<<<<<<<
 * ctypedef public double   fpreal
 * ctypedef public uint32_t fpnchar
 */
typedef uint64_t fpint;

/* "pypico/pico.pyx":5
 * from libc.stdint cimport uint32_t, uint64_t
 * ctypedef public uint64_t fpint
 * ctypedef public double   fpreal             # <<<<<<<<<<<<<<
 * ctypedef public uint32_t fpnchar
 * from numpy import float64 as np_fpreal
 */
typedef double fpreal;

/* "pypico/pico.pyx":6
 * ctypedef public uint64_t fpint
 * ctypedef public double   fpreal
 * ctypedef public uint32_t fpnchar             # <<<<<<<<<<<<<<
 * from numpy import float64 as np_fpreal
 * 
 */
typedef uint32_t fpnchar;

#ifndef __PYX_HAVE_API__pypico__pico

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

__PYX_EXTERN_C DL_IMPORT(void) pico_init(int);
__PYX_EXTERN_C DL_IMPORT(void) print_last_exception_(void);
__PYX_EXTERN_C DL_IMPORT(PyObject) *pico_load(char *);
__PYX_EXTERN_C DL_IMPORT(int) pico_check_success(PyObject *);
__PYX_EXTERN_C DL_IMPORT(PyObject) *pico_compute_result_dict(PyObject *, PyObject *, PyObject *);
__PYX_EXTERN_C DL_IMPORT(PyObject) *pico_compute_result(PyObject *, int, char **, double *);
__PYX_EXTERN_C DL_IMPORT(PyObject) *pico_compute_result2(PyObject *, int, char **, double *, int, char **);
__PYX_EXTERN_C DL_IMPORT(void) pico_read_output(PyObject *, char *, double **, int *, int *);
__PYX_EXTERN_C DL_IMPORT(void) pico_get_output_len(PyObject *, char *, int *);
__PYX_EXTERN_C DL_IMPORT(void) pico_free_result(PyObject *);
__PYX_EXTERN_C DL_IMPORT(int) pico_has_output(PyObject *, char *);
__PYX_EXTERN_C DL_IMPORT(void) pico_set_verbose(PyObject *, int);
__PYX_EXTERN_C DL_IMPORT(void) fpico_init_(fpint *);
__PYX_EXTERN_C DL_IMPORT(void) fpico_load_(char *, fpnchar);
__PYX_EXTERN_C DL_IMPORT(void) fpico_reset_params_(void);
__PYX_EXTERN_C DL_IMPORT(void) fpico_set_param_(char *, double *, fpnchar);
__PYX_EXTERN_C DL_IMPORT(void) fpico_set_param_eval_(char *, char *, fpnchar, fpnchar);
__PYX_EXTERN_C DL_IMPORT(void) fpico_reset_requested_outputs_(void);
__PYX_EXTERN_C DL_IMPORT(void) fpico_request_output_(char *, fpnchar);
__PYX_EXTERN_C DL_IMPORT(void) fpico_compute_result_(int *);
__PYX_EXTERN_C DL_IMPORT(void) fpico_read_output_(char *, fpreal *, fpint *, fpint *, fpnchar);
__PYX_EXTERN_C DL_IMPORT(void) fpico_get_output_len_(char *, fpint *, fpnchar);
__PYX_EXTERN_C DL_IMPORT(void) fpico_set_verbose_(fpint *);

#endif /* !__PYX_HAVE_API__pypico__pico */

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initpico(void);
#else
PyMODINIT_FUNC PyInit_pico(void);
#endif

#endif /* !__PYX_HAVE__pypico__pico */
