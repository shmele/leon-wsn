/************************************************************************
 *
 *  putbits.c, bitstream handling for tmn (TMN encoder)
 *  Copyright (C) 1995, 1996  Telenor R&D, Norway
 *        Karl Olav Lillevold <Karl.Lillevold@nta.no>
 *  
 *  Contacts: 
 *  Karl Olav Lillevold               <Karl.Lillevold@nta.no>, or
 *  Robert Danielsen                  <Robert.Danielsen@nta.no>
 *
 *  Telenor Research and Development  http://www.nta.no/brukere/DVC/
 *  P.O.Box 83                        tel.:   +47 63 84 84 00
 *  N-2007 Kjeller, Norway            fax.:   +47 63 81 00 76
 *  
 ************************************************************************/

/*
 * Disclaimer of Warranty
 *
 * These software programs are available to the user without any
 * license fee or royalty on an "as is" basis.  Telenor Research and
 * Development disclaims any and all warranties, whether express,
 * implied, or statuary, including any implied warranties or
 * merchantability or of fitness for a particular purpose.  In no
 * event shall the copyright-holder be liable for any incidental,
 * punitive, or consequential damages of any kind whatsoever arising
 * from the use of these programs.
 *
 * This disclaimer of warranty extends to the user of these programs
 * and user's customers, employees, agents, transferees, successors,
 * and assigns.
 *
 * Telenor Research and Development does not represent or warrant that
 * the programs furnished hereunder are free of infringement of any
 * third-party patents.
 *
 * Commercial implementations of H.263, including shareware, are
 * subject to royalty fees to patent holders.  Many of these patents
 * are general enough such that they are unavoidable regardless of
 * implementation design.
 * */


/************************************************************************
 *  Based on functions in the MPEG-2 software encoder by the
 *  MPEG-2 Software Simulation Group, modified by
 *
 *  Robert Danielsen, <Robert.Danielsen@nta.no>
 ************************************************************************/
 

#include "sim.h"

#if IF_ON_PC
extern FILE *streamfile; /* the only global var we need here */
#endif

/* private data */
static unsigned char outbfr;
static int outcnt;
static int bytecnt;

/* initialize buffer, call once before first putbits or alignbits */
void
initbits()
{
  outcnt = 8;
  bytecnt = 0;
}

/* write rightmost n (0<=n<=32) bits of val to outfile */

void
putbits (int n, int val)
{
  int i;
  unsigned int mask;
  char bitstring[32];

  //if (trace) {
  //  if (n > 0) {
  //    BitPrint(n,val,bitstring);
  //    fprintf(tf,bitstring);
  //  }
  //}

  mask = 1 << (n-1); /* selects first (leftmost) bit */

  for (i=0; i<n; i++) {
    outbfr <<= 1;

    if (val & mask)
      outbfr|= 1;

    mask >>= 1; /* select next bit */
    outcnt--;

    if (outcnt==0) /* 8 bit buffer full */ {
#if IF_ON_PC
		putc(outbfr,streamfile);
#else
		//xiaoyang yi @2010.12.25 
		mBuffer.stream_output[mBuffer.output_size++] = outbfr;
		//mputc(outbfr,streamfile);
#endif
	  outcnt = 8;
      bytecnt++;
    }
  }
}


/* zero bit stuffing to next byte boundary (5.2.3, 6.2.1) */

int
alignbits ()
{
  int ret_value;
  
  if (outcnt!=8) {
    ret_value = outcnt;	/* outcnt is reset in call to putbits () */
    putbits (outcnt, 0);
    return ret_value;
  }
  else
    return 0;
}

/* return total number of generated bits */
int
bitcount()
{
  return 8*bytecnt + (8-outcnt);
}

/* convert to binary number */
void 
BitPrint(int length, int val, char *bit)
{
  int m;
  
  m = length;
  bit[0] = '"';
  while (m--) {
    bit[length-m] = (val & (1<<m)) ? '1' : '0';
  }
  bit[length+1] = '"';
  bit[length+2] = '\n';
  bit[length+3] = '\0';
  return;
}

