/*
 * This file contains the definitions of the entry points into the AX.25
 * configuration functions.
 */

#ifndef	_AXCONFIG_H
#define	_AXCONFIG_H

#ifndef	TRUE
#define	TRUE	1
#endif

#ifndef	FALSE
#define	FALSE	0
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This function must be called before using any of the other functions in
 * this part of the library. It returns the number of active ports, or 0
 * on failure.
 */
extern int ax25_config_load_ports(void);

/*
 * This function allows the enumeration of all the active configured ports.
 * Passing NULL as the argument returns the first port name in the list,
 * subsequent calls to this function should be made with the last port name
 * returned. A NULL return indicates either an error, or the end of the list.
 */
extern char *ax25_config_get_next(char *);

/*
 * This function maps the device name onto the port name (as used in the axports
 * file. On error a NULL is returned.
 */
extern char *ax25_config_get_name(char *);

/*
 * This function maps the port name onto the callsign of the port. On error a
 * NULL is returned.
 */
extern char *ax25_config_get_addr(char *);

/*
 * This function maps the port name onto the device name of the port. On error a
 * NULL is returned.
 */
extern char *ax25_config_get_dev(char *);

/*
 * This function maps the callsign onto the port name. The callsign should be
 * in shifted format as per get{peer,sock}name(2). A null_ax25_address will
 * return a "*" meaning all ports. On error NULL is returned.
 */
extern char *ax25_config_get_port(ax25_address *);

/*
 * This function takes the port name and returns the default window size. On
 * error 0 is returned.
 */
extern int ax25_config_get_window(char *);

/*
 * This function takes the port name and returns the maximum packet length.
 * On error a 0 is returned.
 */
extern int ax25_config_get_paclen(char *);

/*
 * This function takes the port name and returns the baud rate. On error a
 * 0 is returned.
 */
extern int ax25_config_get_baud(char *);

/*
 * This function takes the port name and returns the description of the port.
 * On error a NULL is returned.
 */
extern char *ax25_config_get_desc(char *);

#ifdef __cplusplus
}
#endif

#endif
