/*
 * This file documents the layout of the mheard file. Since this file is
 * common to at least two of the AX25 utilities, it is documented here.
 */
#ifndef MHEARD_H
#define	MHEARD_H

struct mheard_struct {
	ax25_address from_call;
	ax25_address to_call;
	char         portname[20];
	unsigned int count;
	unsigned int sframes;
	unsigned int uframes;
	unsigned int iframes;
	unsigned int ndigis;
	ax25_address digis[8];
	time_t       first_heard;
	time_t       last_heard;

#define	MHEARD_TYPE_SABM	0
#define	MHEARD_TYPE_SABME	1
#define	MHEARD_TYPE_DISC	2
#define	MHEARD_TYPE_UA		3
#define	MHEARD_TYPE_DM		4
#define	MHEARD_TYPE_RR		5
#define	MHEARD_TYPE_RNR		6
#define	MHEARD_TYPE_REJ		7
#define	MHEARD_TYPE_FRMR	8
#define	MHEARD_TYPE_I		9
#define	MHEARD_TYPE_UI		10
#define	MHEARD_TYPE_UNKNOWN	11
	unsigned int type;
	
#define	MHEARD_MODE_TEXT	0x0001
#define	MHEARD_MODE_ARP		0x0002
#define	MHEARD_MODE_IP_DG	0x0004
#define	MHEARD_MODE_IP_VC	0x0008
#define	MHEARD_MODE_NETROM	0x0010
#define	MHEARD_MODE_ROSE	0x0020
#define	MHEARD_MODE_FLEXNET	0x0040
#define	MHEARD_MODE_TEXNET	0x0080
#define	MHEARD_MODE_PSATPB	0x0100
#define	MHEARD_MODE_PSATFT	0x0200
#define	MHEARD_MODE_SEGMENT	0x4000
#define	MHEARD_MODE_UNKNOWN	0x8000
	unsigned int  mode;

	char          spare[128];
};

#endif
