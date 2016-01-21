#ifndef BLE_LBS_H__
#define BLE_LBS_H__

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"

//groovy:000> a.reverse().collect({s -> "0x"+Integer.toHexString(s)})
#define APPLE_MIDI_UUID_BASE        {0x0, 0xc7, 0xc4, 0x4e, 0xe3, 0x6c, 0x51, 0xa7, 0x33, 0x4b, 0xe8, 0xed, 0x5a, 0xe, 0xb8, 0x3}
#define LBS_UUID_SERVICE     0x0e5a
#define LBS_UUID_LED_CHAR    0x1525

// Forward declaration of the ble_lbs_t type.
typedef struct ble_midi_s ble_midi_t;

typedef void (*ble_lbs_led_write_handler_t) (ble_midi_t * p_lbs, uint8_t new_state);

/** @brief LED Button Service init structure. This structure contains all options and data needed for
 *        initialization of the service.*/
typedef struct
{
    ble_lbs_led_write_handler_t led_write_handler; /**< Event handler to be called when the LED Characteristic is written. */
} ble_lbs_init_t;

/**@brief LED Button Service structure. This structure contains various status information for the service. */
struct ble_midi_s
{
    uint16_t                    service_handle;      /**< Handle of LED Button Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t    led_char_handles;    /**< Handles related to the LED Characteristic. */
    ble_gatts_char_handles_t    midi_io_char_handles; /**< Handles related to the Button Characteristic. */
    uint8_t                     uuid_type;           /**< UUID type for the LED Button Service. */
    uint16_t                    conn_handle;         /**< Handle of the current connection (as provided by the BLE stack). BLE_CONN_HANDLE_INVALID if not in a connection. */
    ble_lbs_led_write_handler_t midi_write_handler;   /**< Event handler to be called when the LED Characteristic is written. */
};

/**@brief Function for initializing the LED Button Service.
 *
 * @param[out] p_lbs      LED Button Service structure. This structure must be supplied by
 *                        the application. It is initialized by this function and will later
 *                        be used to identify this particular service instance.
 * @param[in] p_lbs_init  Information needed to initialize the service.
 *
 * @retval NRF_SUCCESS If the service was initialized successfully. Otherwise, an error code is returned.
 */
uint32_t ble_midi_init(ble_midi_t * p_lbs, const ble_lbs_init_t * p_lbs_init);

/**@brief Function for handling the application's BLE stack events.
 *
 * @details This function handles all events from the BLE stack that are of interest to the MIDI Service.
 *
 * @param[in] p_lbs      LED Button Service structure.
 * @param[in] p_ble_evt  Event received from the BLE stack.
 */
void ble_midi_on_ble_evt(ble_midi_t * p_lbs, ble_evt_t * p_ble_evt);

uint32_t ble_midi_send_note(ble_midi_t * p_lbs, int note, int velocity);
#endif // BLE_MIDI_H__

/** @} */
