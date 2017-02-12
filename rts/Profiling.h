/* -----------------------------------------------------------------------------
 *
 * (c) The GHC Team, 1998-2005
 *
 * Support for profiling
 *
 * ---------------------------------------------------------------------------*/

#ifndef PROFILING_H
#define PROFILING_H

#include <stdio.h>

#include "BeginPrivate.h"
#include "Rts.h"

#ifdef PROFILING
#define PROFILING_ONLY(s) s
#else
#define PROFILING_ONLY(s) doNothing()
#endif

void initProfiling  (void);
void initProfiling2 (void);
void endProfiling   (void);
void freeProfiling  (void);

extern FILE *prof_file;
extern FILE *hp_file;

#ifdef PROFILING

void reportCCSProfiling ( void );

/* A summary of an execution of a profiled program */
typedef struct {
    /* Total bytes allocated */
    uint64_t total_alloc;
    /* Total number of profiler ticks */
    unsigned int total_prof_ticks;
} ProfilerTotals;

void fprintCCS( FILE *f, CostCentreStack *ccs );
void fprintCCS_stderr (CostCentreStack *ccs, StgClosure *exception, StgTSO *tso);

#ifdef DEBUG
void debugCCS( CostCentreStack *ccs );
#endif

#endif

#include "EndPrivate.h"

#endif /* PROFILING_H */
