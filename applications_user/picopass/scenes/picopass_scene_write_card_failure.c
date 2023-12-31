#include "../picopass_i.h"
#include <dolphin/dolphin.h>

void picopass_scene_write_card_failure_widget_callback(
    GuiButtonType result,
    InputType type,
    void* context) {
    furi_assert(context);
    Picopass* picopass = context;

    if(type == InputTypeShort) {
        view_dispatcher_send_custom_event(picopass->view_dispatcher, result);
    }
}

void picopass_scene_write_card_failure_on_enter(void* context) {
    Picopass* picopass = context;
    Widget* widget = picopass->widget;
    FuriString* str = furi_string_alloc_set("Write Failure!");

    widget_add_button_element(
        widget,
        GuiButtonTypeLeft,
        "Retry",
        picopass_scene_write_card_failure_widget_callback,
        picopass);

    widget_add_button_element(
        widget,
        GuiButtonTypeRight,
        "Menu",
        picopass_scene_write_card_failure_widget_callback,
        picopass);

    widget_add_string_element(
        widget, 64, 5, AlignCenter, AlignCenter, FontSecondary, furi_string_get_cstr(str));

    furi_string_free(str);

    view_dispatcher_switch_to_view(picopass->view_dispatcher, PicopassViewWidget);
}

bool picopass_scene_write_card_failure_on_event(void* context, SceneManagerEvent event) {
    Picopass* picopass = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == GuiButtonTypeLeft) {
            consumed = scene_manager_previous_scene(picopass->scene_manager);
        } else if(event.event == GuiButtonTypeRight) {
            // Clear device name
            picopass_device_set_name(picopass->dev, "");
            consumed = scene_manager_search_and_switch_to_previous_scene(
                picopass->scene_manager, PicopassSceneStart);
        }
    }
    return consumed;
}

void picopass_scene_write_card_failure_on_exit(void* context) {
    Picopass* picopass = context;

    // Clear view
    widget_reset(picopass->widget);
}
