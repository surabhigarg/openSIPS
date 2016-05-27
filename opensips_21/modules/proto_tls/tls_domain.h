/*
 * Copyright (C)  2001-2003 FhG Fokus
 * Copyright (C)  2004,2005 Free Software Foundation, Inc.
 * Copyright (C)  2005,2006 iptelorg GmbH
 * Copyright (C)  2006 enum.at
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef TLS_DOMAIN_H
#define TLS_DOMAIN_H

#include "../../str.h"
#include "../../ip_addr.h"
#include "tls_config.h"
#include <openssl/ssl.h>

/*
 * TLS configuration domain type
 */
enum tls_domain_type {
	TLS_DOMAIN_DEF = (1 << 0), /* Default domain */
	TLS_DOMAIN_SRV = (1 << 1), /* Server domain */
	TLS_DOMAIN_CLI = (1 << 2), /* Client domain */
	TLS_DOMAIN_NAME= (1 << 3)  /* Name based TLS domain */
};

/*
 * separate configuration per ip:port
 */
struct tls_domain {
	str             id;
	int             type;
	struct ip_addr  addr;
	unsigned short  port;
	SSL_CTX        *ctx;
	int             verify_cert;
	int             require_client_cert;
	char           *cert_file;
	char           *pkey_file;
	char           *ca_file;
	char           *tmp_dh_file;
	char           *tls_ec_curve;
	char	       *ca_directory;
	char           *ciphers_list;
	enum tls_method method;
	struct tls_domain *next;
	str name;
};

extern struct tls_domain *tls_server_domains;
extern struct tls_domain *tls_client_domains;
extern struct tls_domain tls_default_server_domain;
extern struct tls_domain tls_default_client_domain;


/*
 * find domain with given ID
 */
struct tls_domain *tls_find_domain_by_id( str *id);

/*
 * find domain with given ip and port
 */
struct tls_domain *tls_find_server_domain(struct ip_addr *ip,
				   unsigned short port);

/*
 * find client with given ip and port
 */
struct tls_domain *tls_find_client_domain(struct ip_addr *ip,
				   unsigned short port);

/*
 * find domain with given name
 */
struct tls_domain *tls_find_client_domain_name(str name);

/*
 * create a new server domain (identified by socket)
 */
int tls_new_server_domain(str *id, struct ip_addr *ip, unsigned short port);

/*
 * create a new client domain (identified by socket)
 */
int tls_new_client_domain(str *id, struct ip_addr *ip, unsigned short port);

/*
 * create a new client domain (identified by string)
 */
int tls_new_client_domain_name(str *id, str *domain);

/*
 * allocate memory and set default values for
 * TLS domain structure
 */
struct tls_domain *tls_new_domain(str *id, int type);

/*
 * clean up
 */
void  tls_free_domains(void);

#endif
