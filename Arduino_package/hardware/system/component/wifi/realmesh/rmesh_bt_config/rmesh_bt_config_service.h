/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file     bt_config_service.h
  * @brief    Demonstration of how to implement a self-definition service.
  * @details  Demonstration of different kinds of service interfaces.
  * @author
  * @date
  * @version
  * *************************************************************************************
  */

/* Define to prevent recursive inclusion */
#ifndef _RMESH_BT_CONFIG_SERVICE_H_
#define _RMESH_BT_CONFIG_SERVICE_H_

#ifdef __cplusplus
extern "C"  {
#endif      /* __cplusplus */

/* Add Includes here */
#include <profile_server.h>
#include "rmesh_bt_config_config.h"


/** @defgroup SIMP_Service Simple Ble Service
  * @brief Simple BLE service
  * @{
  */
/*============================================================================*
 *                              Macros
 *============================================================================*/
/** @defgroup SIMP_Service_Exported_Macros SIMP Service Exported Macros
  * @brief
  * @{
  */

/** @defgroup SIMP_Service_Application_Parameters SIMP Service Application Parameters
  * @brief  Type of parameters set/got from application.
  * @{
  */
typedef enum {
	RMESH_BTCONFIG_SERVICE_PARAM_V1_READ_CHAR_VAL = 0x01,
} T_RMESH_BTCONFIG_PARAM_TYPE;

/** @} */



/** @defgroup SIMP_Service_Upstream_Message SIMP Service Upstream Message
  * @brief  Upstream message used to inform application.
  * @{
  */

/** @defgroup SIMP_Service_Read_Info SIMP Service Read Info
  * @brief  Parameter for reading characteristic value.
  * @{
  */
#define RMESH_BTCONFIG_READ_V1                                        1
/** @} */

/** @defgroup SIMP_Service_Write_Info SIMP Service Write Info
  * @brief  Parameter for writing characteristic value.
  * @{
  */
#define RMESH_BTCONFIG_WRITE_V1                                       1

/** @} */

#define RMESH_BT_CONFIG_READ_V1_MAX_LEN               300

/** @} End of SIMP_Service_Upstream_Message */



/** @} End of SIMP_Service_Exported_Macros */
/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup SIMP_Service_Exported_Types SIMP Service Exported Types
  * @brief
  * @{
  */

/** @defgroup TSIMP_WRITE_MSG TSIMP_WRITE_MSG
  * @brief Simple BLE service written msg to application.
  * @{
  */
typedef struct {
	uint8_t opcode; //!< ref:  @ref SIMP_Service_Write_Info
	T_WRITE_TYPE write_type;
	uint16_t len;
	uint8_t *p_value;
} TRMESH_BTCONFIG_WRITE_MSG;
/** @} End of TSIMP_WRITE_MSG */


/** @defgroup TSIMP_UPSTREAM_MSG_DATA TSIMP_UPSTREAM_MSG_DATA
  * @brief Simple BLE service callback message content.
  * @{
  */
typedef union {
	uint8_t read_value_index; //!< ref: @ref SIMP_Service_Read_Info
	TRMESH_BTCONFIG_WRITE_MSG write;
	uint16_t read_offset;
} TRMESH_BTCONFIG_MSG_DATA;
/** @} End of TSIMP_UPSTREAM_MSG_DATA */

/** @defgroup TSIMP_CALLBACK_DATA TSIMP_CALLBACK_DATA
  * @brief Simple BLE service data to inform application.
  * @{
  */
typedef struct {
	uint8_t                 conn_id;
	T_SERVICE_CALLBACK_TYPE msg_type;
	TRMESH_BTCONFIG_MSG_DATA msg_data;
} TRMESH_BTCONFIG_CALLBACK_DATA;
/** @} End of TSIMP_CALLBACK_DATA */

/** @} End of SIMP_Service_Exported_Types */
/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup SIMP_Service_Exported_Functions SIMP Service Exported Functions
  * @brief
  * @{
  */

/**
  * @brief Add simple BLE service to the BLE stack database.
  *
  * @param[in]   p_func  Callback when service attribute was read, write or cccd update.
  * @return Service id generated by the BLE stack: @ref T_SERVER_ID.
  * @retval 0xFF Operation failure.
  * @retval others Service id assigned by stack.
  *
  */
T_SERVER_ID rmesh_bt_config_service_add_service(void *p_func);

/**
  * @brief  Set service related data from application.
  *
  * @param[in] param_type            parameter type to set.
  * @param[in] len                   value length to be set.
  * @param[in] p_value             value to set.
  * @return parameter set result.
  * @retval 0 false
  * @retval 1 true
  */
bool rmesh_bt_config_service_set_parameter(T_RMESH_BTCONFIG_PARAM_TYPE param_type, uint16_t len, void *p_value);

/** @} End of SIMP_Service_Exported_Functions */

/** @} End of SIMP_Service */


#ifdef __cplusplus
}
#endif

#endif /* _BT_CONFIG_WIFI_SERVICE_H_ */

