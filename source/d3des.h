/* d3des.h -
 *
 *	Headers and defines for d3des.c
 *	Graven Imagery, 1992.
 *
 * Copyright (c) 1988,1989,1990,1991,1992 by Richard Outerbridge
 *	(GEnie : OUTER; CIS : [71755,204])
 *
 * D2_DES and D3_DES code removed, by Constantin Kaplinsky
 *
 * Modifications by Ramesh Dharan (rrdharan@vmware.com):
 *      - added pragma directives for our build system (ignore int->char cast
 *        errors)
 *      - added filecode
 *      - replaced long with int for 64-bit port
 *      - added DES_HEXKEY_LEN definition
 */


#define EN0	0	/* MODE == encrypt */
#define DE1	1	/* MODE == decrypt */

#define DES_HEXKEY_LEN 8

/* A useful alias on 68000-ish machines, but NOT USED HERE. */

typedef union {
	unsigned int blok[2];
	unsigned short word[4];
	unsigned char byte[8];
	} M68K;

extern void deskey(unsigned char *, int);
/*		      hexkey[8]     MODE
 * Sets the internal key register according to the hexadecimal
 * key contained in the 8 bytes of hexkey, according to the DES,
 * for encryption or decryption according to MODE.
 */

extern void usekey(unsigned int *);
/*		    cookedkey[32]
 * Loads the internal key register with the data in cookedkey.
 */

extern void cpkey(unsigned int *);
/*		   cookedkey[32]
 * Copies the contents of the internal key register into the storage
 * located at &cookedkey[0].
 */

extern void des(unsigned char *, unsigned char *);
/*		    from[8]	      to[8]
 * Encrypts/Decrypts (according to the key currently loaded in the
 * internal key register) one block of eight bytes at address 'from'
 * into the block at address 'to'.  They can be the same.
 */

/* d3des.h V5.09 rwo 9208.04 15:06 Graven Imagery
 ********************************************************************/
