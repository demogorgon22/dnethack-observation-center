/*	SCCS Id: @(#)dgn_file.h 3.4	1993/01/17	*/
/* Copyright (c) 1989 by M. Stephenson				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef DGN_FILE_H
#define DGN_FILE_H

#ifndef ALIGN_H
#include "align.h"
#endif

/*
 * Structures manipulated by the dungeon loader & compiler
 */

struct	couple {
	short	base, rand;
};

struct tmpdungeon {
	char	name[24],
		protoname[24];
	struct	couple	lev;
	int	flags,
		chance,
		levels,
		alternates,
		branches,
		entry_lev;		/* entry level for this dungeon */
	char	boneschar;
};

struct tmplevel {
	char	name[24];
	struct	couple	lev;
	int	chance, rndlevs, chain, flags;
	char	boneschar;
};

struct tmpbranch {
	char	name[24];	/* destination dungeon name */
	struct	couple	lev;
	int	chain;		/* index into tmplevel array (chained branch)*/
	int	type;		/* branch type (see below) */
	int	up;		/* branch is up or down */
};

/*
 *	Values for type for tmpbranch structure.
 */
#define TBR_STAIR   0	/* connection with both ends having a staircase */
#define TBR_NO_UP   1	/* connection with no up staircase */
#define TBR_NO_DOWN 2	/* connection with no down staircase */
#define TBR_PORTAL  3	/* portal connection */

/*
 *	Flags that map into the dungeon flags bitfields.
 */
#define TOWN	    1	/* levels only */
#define HELLISH     2
#define MAZELIKE    4
#define ROGUELIKE   8

#define D_ALIGN_NONE	0
#define D_ALIGN_CHAOTIC	(AM_CHAOTIC << 4)
#define D_ALIGN_NEUTRAL	(AM_NEUTRAL << 4)
#define D_ALIGN_LAWFUL	(AM_LAWFUL << 4)

#define D_ALIGN_MASK	0x70

/*
 *	Max number of prototype levels and branches.
 */
//increased LEV_LIMIT from 50 to 100 >:[ Not sure WHY there is a limit to begin with...
//...and now to 150
#define LEV_LIMIT	150
#define BRANCH_LIMIT	32

#endif /* DGN_FILE_H */
