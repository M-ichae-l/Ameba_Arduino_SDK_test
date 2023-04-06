/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __RTL8721D_DM_H__
#define __RTL8721D_DM_H__
enum {
	UP_LINK,
	DOWN_LINK,
};
#define RTW_ADAPTIVITY_EN_DISABLE 0
#define RTW_ADAPTIVITY_EN_ENABLE 1
#define RTW_ADAPTIVITY_EN_AUTO 2

//============================================================
// structure and define
//============================================================

//============================================================
// function prototype
//============================================================

void rtl8721d_phy_init_dm_priv(PADAPTER);
void rtl8721d_phy_dm_timer_cancel(PADAPTER);
void rtl8721d_phy_init_haldm(PADAPTER);
void rtl8721d_phy_haldm_watchdog(PADAPTER);
void rtl8721d_phy_haldm_in_lps(PADAPTER);
void rtl8721d_phy_haldm_watchdog_in_lps(PADAPTER);
void rtl8721d_query_phy_statistic(PADAPTER padapter, rtw_phy_statistics_t *statistic);

#endif

