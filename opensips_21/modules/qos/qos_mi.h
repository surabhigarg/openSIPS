/*
 * Copyright (C) 2007 SOMA Networks, Inc.
 * Written By Ovidiu Sas (osas)
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 * USA
 *
 * History:
 * --------
 * 2007-07-16 initial version (osas)
 */

#ifndef _QOS_MI_H_
#define _QOS_MI_H_

#include "../../sr_module.h" /* Needed for find_export() */
#include "../../parser/msg_parser.h"
#include "../dialog/dlg_load.h"

/**
 * The dialog mi helper function.
 */
void qos_dialog_mi_context_CB(struct dlg_cell* did, int type, struct dlg_cb_params * params);

#endif /* _QOS_MI_H_ */