#include "a2de_base.h"

A2DE_BEGIN

bool a2de_init() {
    bool system_init_result = al_install_system(ALLEGRO_VERSION_INT, atexit);
    bool image_init_result = al_init_image_addon();
    bool primatives_init_result = al_init_primitives_addon();
    al_init_font_addon();
    bool ttf_init_result = al_init_ttf_addon();
    bool install_audio_result = al_install_audio();
    bool acodec_init_result = al_init_acodec_addon();
    bool native_dialog_init_result = al_init_native_dialog_addon();
    bool keyboard_result = al_install_keyboard();
    bool mouse_result = al_install_mouse();
    bool joystick_result = al_install_joystick();

    if(system_init_result == false) {
        std::cout << "Allegro 5 failed to initialize." << std::endl;
        return false;
    }

    if(native_dialog_init_result == false) {
        std::cout << "Native Dialog add-on failed to initialize." << std::endl;
        return false;
    }

    if(primatives_init_result == false) {
        std::cout << "Primatives add-on to initialize." << std::endl;
        return false;
    }

    if(image_init_result == false) {
        std::cout << "Image add-on failed to initialize." << std::endl;
        return false;
    }

    if(ttf_init_result == false) {
        std::cout << "TrueType Font add-on to initialize." << std::endl;
        return false;
    }

    if(install_audio_result == false) {
        std::cout << "Audio add-on failed to initialize." << std::endl;
        return false;
    }

    if(acodec_init_result == false) {
        std::cout << "Audio Codec add-on failed to initialize." << std::endl;
        return false;
    }

    if(keyboard_result == false) {
        std::cout << "Keyboard failed to initialize." << std::endl;
        return false;
    }

    if(mouse_result == false) {
        std::cout << "Mouse failed to initialize." << std::endl;
        return false;
    }

    if(joystick_result == false) {
        std::cout << "Joystick failed to initialize." << std::endl;
        return false;
    }

    return true;
}

A2DE_END