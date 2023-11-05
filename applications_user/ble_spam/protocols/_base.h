#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ble_spam_icons.h"
#include <furi_hal_random.h>
#include <core/core_defines.h>
#include "../ble_spam.h"

typedef struct ProtocolCfg ProtocolCfg;

typedef struct {
    const Icon* icon;
    const char* (*get_name)(const ProtocolCfg* _cfg);
    void (*make_packet)(uint8_t* _size, uint8_t** _packet, ProtocolCfg* _cfg);
    void (*extra_config)(Ctx* ctx);
    uint8_t (*config_count)(const ProtocolCfg* _cfg);
} Protocol;
