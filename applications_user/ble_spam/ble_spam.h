#pragma once

#include <notification/notification_messages.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/byte_input.h>
#include <gui/modules/submenu.h>
#include <gui/modules/text_input.h>
#include <gui/modules/variable_item_list.h>
#include <furi.h>
#include <furi_hal.h>

#include <gui/gui.h>
#include <gui/scene_manager.h>
#include <gui/modules/widget.h>

#include <furi_hal_bt.h>
#include <stdint.h>
#include <furi_hal_random.h>
//#include "lib/continuity/continuity.h"

#include <furi/core/log.h>
#include <furi/core/timer.h>

#include "scenes/_setup.h"

enum {
    ViewMain,
    ViewByteInput,
    ViewSubmenu,
    ViewTextInput,
    ViewVariableItemList,
};

enum {
    ConfigRandomMac,
    ConfigExtraStart = ConfigRandomMac,
    ConfigLedIndicator,
    ConfigLockKeyboard,
};

typedef struct Attack Attack;

typedef struct {
    Attack* attack;
    uint8_t byte_store[3];
    VariableItemListEnterCallback fallback_config_enter;
    bool led_indicator;
    bool lock_keyboard;

    NotificationApp* notification;
    ViewDispatcher* view_dispatcher;
    SceneManager* scene_manager;

    ByteInput* byte_input;
    Submenu* submenu;
    TextInput* text_input;
    VariableItemList* variable_item_list;
} Ctx;
