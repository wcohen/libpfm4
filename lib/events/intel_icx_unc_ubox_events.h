/*
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of libpfm, a performance monitoring support library for
 * applications on Linux.
 *
 * PMU: icx_unc_ubox (IcelakeX Uncore UBOX)
 * Based on Intel JSON event table version   : 1.21
 * Based on Intel JSON event table published : 06/06/2023
 */

static const intel_x86_umask_t icx_unc_u_event_msg[]={
  { .uname   = "DOORBELL_RCVD",
    .udesc   = "Doorbell (experimental)",
    .ucode   = 0x0800ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "INT_PRIO",
    .udesc   = "Interrupt (experimental)",
    .ucode   = 0x1000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "IPI_RCVD",
    .udesc   = "IPI (experimental)",
    .ucode   = 0x0400ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "MSI_RCVD",
    .udesc   = "MSI (experimental)",
    .ucode   = 0x0200ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "VLW_RCVD",
    .udesc   = "VLW (experimental)",
    .ucode   = 0x0100ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t icx_unc_u_m2u_misc1[]={
  { .uname   = "RxC_CYCLES_NE_CBO_NCB",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0100ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "RxC_CYCLES_NE_CBO_NCS",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0200ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "RxC_CYCLES_NE_UPI_NCB",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0400ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "RxC_CYCLES_NE_UPI_NCS",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0800ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_CRD_OVF_CBO_NCB",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x1000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_CRD_OVF_CBO_NCS",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x2000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_CRD_OVF_UPI_NCB",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x4000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_CRD_OVF_UPI_NCS",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x8000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t icx_unc_u_m2u_misc2[]={
  { .uname   = "RxC_CYCLES_EMPTY_BL",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0200ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "RxC_CYCLES_FULL_BL",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0100ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_CRD_OVF_VN0_NCB",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0400ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_CRD_OVF_VN0_NCS",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0800ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_EMPTY_AK",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x2000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_EMPTY_AKC",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x4000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_EMPTY_BL",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x1000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_FULL_BL",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x8000ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t icx_unc_u_m2u_misc3[]={
  { .uname   = "TxC_CYCLES_FULL_AK",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0100ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "TxC_CYCLES_FULL_AKC",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0200ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t icx_unc_u_phold_cycles[]={
  { .uname   = "ASSERT_TO_ACK",
    .udesc   = "Assert to ACK (experimental)",
    .ucode   = 0x0100ull,
    .uflags  = INTEL_X86_DFL,
  },
};

static const intel_x86_umask_t icx_unc_u_racu_drng[]={
  { .uname   = "PFTCH_BUF_EMPTY",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0400ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "RDRAND",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0100ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
  { .uname   = "RDSEED",
    .udesc   = "TBD (experimental)",
    .ucode   = 0x0200ull,
    .uflags  = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_entry_t intel_icx_unc_ubox_pe[]={
  { .name   = "UNC_U_CLOCKTICKS",
    .desc   = "Clockticks in the UBOX using a dedicated 48-bit Fixed Counter",
    .code   = 0x0000,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x1ull,
  },
  { .name   = "UNC_U_EVENT_MSG",
    .desc   = "Message Received",
    .code   = 0x0042,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
    .ngrp   = 1,
    .numasks= LIBPFM_ARRAY_SIZE(icx_unc_u_event_msg),
    .umasks = icx_unc_u_event_msg,
  },
  { .name   = "UNC_U_LOCK_CYCLES",
    .desc   = "IDI Lock/SplitLock Cycles (experimental)",
    .code   = 0x0044,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
  },
  { .name   = "UNC_U_M2U_MISC1",
    .desc   = "TBD",
    .code   = 0x004d,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
    .ngrp   = 1,
    .numasks= LIBPFM_ARRAY_SIZE(icx_unc_u_m2u_misc1),
    .umasks = icx_unc_u_m2u_misc1,
  },
  { .name   = "UNC_U_M2U_MISC2",
    .desc   = "TBD",
    .code   = 0x004e,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
    .ngrp   = 1,
    .numasks= LIBPFM_ARRAY_SIZE(icx_unc_u_m2u_misc2),
    .umasks = icx_unc_u_m2u_misc2,
  },
  { .name   = "UNC_U_M2U_MISC3",
    .desc   = "TBD",
    .code   = 0x004f,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
    .ngrp   = 1,
    .numasks= LIBPFM_ARRAY_SIZE(icx_unc_u_m2u_misc3),
    .umasks = icx_unc_u_m2u_misc3,
  },
  { .name   = "UNC_U_PHOLD_CYCLES",
    .desc   = "Cycles PHOLD Assert to Ack",
    .code   = 0x0045,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
    .ngrp   = 1,
    .numasks= LIBPFM_ARRAY_SIZE(icx_unc_u_phold_cycles),
    .umasks = icx_unc_u_phold_cycles,
  },
  { .name   = "UNC_U_RACU_DRNG",
    .desc   = "TBD",
    .code   = 0x004c,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
    .ngrp   = 1,
    .numasks= LIBPFM_ARRAY_SIZE(icx_unc_u_racu_drng),
    .umasks = icx_unc_u_racu_drng,
  },
  { .name   = "UNC_U_RACU_REQUESTS",
    .desc   = "RACU Request (experimental)",
    .code   = 0x0046,
    .modmsk = ICX_UNC_UBO_ATTRS,
    .cntmsk = 0x3ull,
  },
};
/* 9 events available */
