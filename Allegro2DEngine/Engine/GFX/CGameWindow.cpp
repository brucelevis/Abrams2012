/**************************************************************************************************
// file:	Engine\GFX\CGameWindow.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the game Windows Form
 **************************************************************************************************/
#include "CGameWindow.h"

#include <allegro5/display.h>
#include <allegro5/bitmap.h>
#include <allegro5/allegro_color.h>

#include "../a2de_exceptions.h"

#include <sstream>

A2DE_BEGIN

GameWindow::GameWindow() :
_display_flags(ALLEGRO_WINDOWED | ALLEGRO_DIRECT3D_INTERNAL),
_dimensions(640, 480),
_title("")
{ /* DO NOTHING */ }

GameWindow::GameWindow(int display_flags) :
_display_flags(display_flags),
_dimensions(640, 480),
_title("")
{ /* DO NOTHING */ }

GameWindow::GameWindow(int display_flags, int width, int height) :
_display_flags(display_flags),
_dimensions(width, height),
_title("")
{ /* DO NOTHING */ }

/*************************************************************************************/
/* Trim function courtesy of GManNickG via http://stackoverflow.com/a/1798170/421178 */
/*************************************************************************************/
std::string trim(std::string& str, const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

GameWindow::GameWindow(int display_flags, int width, int height, const std::string& title) :
_display_flags(display_flags),
_dimensions(width, height),
_title(title)
{ /* DO NOTHING */ }

GameWindow::~GameWindow() {
    al_set_target_bitmap(nullptr);
    al_destroy_display(_display);
    _display = nullptr;
}

bool GameWindow::IsWindowed() const {
    return (al_get_display_flags(_display) & (ALLEGRO_WINDOWED | ALLEGRO_FULLSCREEN_WINDOW)) != 0;
}
int GameWindow::GetWidth() const {
    return _dimensions.first;
}
int GameWindow::GetHeight() const {
    return _dimensions.second;
}

void GameWindow::ShowWindow() {
    //Trim extra space in user-supplied title.
    _title = trim(_title);
    _title.append("   Created using the Abrams 2D Engine (c) Casey Ugone");
    //Trim extra space from copyright if trimmed user-supplied title is already empty.
    _title = trim(_title);
    _display = al_create_display(_dimensions.first, _dimensions.second);
    al_set_window_title(_display, _title.c_str());
    al_set_target_bitmap(al_get_backbuffer(_display));
}

void GameWindow::StartRender() {
    al_set_target_backbuffer(_display);
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

void GameWindow::EndRender() {
    al_flip_display();
}

ALLEGRO_DISPLAY* const GameWindow::GetDisplay() const {
    return _display;
}

ALLEGRO_DISPLAY* const GameWindow::GetDisplay() {
    return static_cast<const GameWindow&>(*this).GetDisplay();
}


A2DE_END