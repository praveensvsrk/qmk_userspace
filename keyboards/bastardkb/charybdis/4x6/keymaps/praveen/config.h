/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

/* RP2040-Zero: GP21 is on the hard-to-reach back pads - remap col 2 to GP3. */
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { GP27, GP28, GP3, GP6, GP8, GP7 }
//                                    ^^^            ^^^^^^^^
//                       col2 was GP21 -> GP3; cols 4 & 5 swapped (GP8, GP7) to match wiring

/* Row pins remapped to match hand-wiring: row3 GP4->GP14, row4(thumb) GP9->GP12. */
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { GP29, GP26, GP5, GP14, GP12 }
//   logical row:            0     1    2     3     4(thumb)

/* RP2040-Zero has no VBUS sense wired to GP19 (that's a Splinky-only connection),
 * so the firmware can't detect USB via the pin and never becomes master / never
 * enumerates. Drop the pin and use software USB detection instead. */
#undef USB_VBUS_PIN
#define SPLIT_USB_DETECT

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
