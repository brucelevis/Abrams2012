/**************************************************************************************************
// file:	Engine\GFX\CSpriteHandler.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the sprite handler class
 **************************************************************************************************/
#include "CSpriteHandler.h"

#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/drawing.h>
#include <allegro5/display.h>

#include "CSprite.h"
#include "../Math/CMiscMath.h"
#include "../Math/CShape.h"
#include "../Math/CRectangle.h"
#include "../Math/CTransform2D.h"
#include "../Math/CMatrix4x4.h"
#include <algorithm>
#include "CGameWindow.h"


A2DE_BEGIN

/************************************************************************/
/* DO NOT DEFINE CONSTRUCTORS, DESTRUCTOR, ASSIGNMENT OPERATOR!         */
/************************************************************************/

void SpriteHandler::Draw(ALLEGRO_BITMAP* dest, Shape* object) {
    if(object == nullptr || dest == nullptr) return;
    object->Draw(dest, object->GetColor(), object->IsFilled());
}

void SpriteHandler::Draw(ALLEGRO_BITMAP* dest, ALLEGRO_BITMAP* source, double x, double y, ALLEGRO_COLOR tintColor) {
    if(source == nullptr || dest == nullptr) return;

    /* DO NOTHING
     * Alpha transparency is set to 0. If the bitmap is completely transparent, there's no need to draw anything or perform a complex tinting/alpha operation.
     */

    unsigned char alpha = tintColor.a * 255.0;
    unsigned char r = tintColor.r * 255.0;
    unsigned char g = tintColor.g * 255.0;
    unsigned char b = tintColor.b * 255.0;
    if(a2de::Math::IsEqual(tintColor.a, 0.0)) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_bitmap(source, al_map_rgba(r, g, b, alpha), a2de::Math::ToScreenScale(x), a2de::Math::ToScreenScale(y), 0);

    al_set_target_bitmap(old_target_bmp);

}
void SpriteHandler::Draw(ALLEGRO_BITMAP* dest, Sprite* sprite) {
    if(sprite == nullptr || dest == nullptr) return;
    Draw(dest, sprite->GetImage(), sprite->GetX(), sprite->GetY(), sprite->GetTint());
}

void SpriteHandler::DrawFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, SpriteHandler::SPRITEAXIS axis) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char r = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_bitmap(sprite->GetImage(), al_map_rgba(r, g, b, alpha), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), axis); //SpriteHandler::SPRITEAXIS maps directly to ALLEGRO_FLIP values.

    al_set_target_bitmap(old_target_bmp);

}

void SpriteHandler::DrawRotate(ALLEGRO_BITMAP* dest, Sprite* sprite) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char r = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_rotated_bitmap(sprite->GetImage(), al_map_rgba(r, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), sprite->GetX(), sprite->GetY(), sprite->GetAngle(), 0);

    al_set_target_bitmap(old_target_bmp);

}

void SpriteHandler::DrawRotateScale(ALLEGRO_BITMAP* dest, Sprite* sprite) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char r = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_scaled_rotated_bitmap(sprite->GetImage(), al_map_rgba(r, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), a2de::Math::ToScreenScale(sprite->GetScaleX()), a2de::Math::ToScreenScale(sprite->GetScaleY()), sprite->GetAngle(), 0);

    al_set_target_bitmap(old_target_bmp);
}

void SpriteHandler::DrawRotateFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, SpriteHandler::SPRITEAXIS axis) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char r = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_rotated_bitmap(sprite->GetImage(), al_map_rgba(r, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), sprite->GetAngle(), axis);

    al_set_target_bitmap(old_target_bmp);
}

void SpriteHandler::DrawRotateScaleFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, SpriteHandler::SPRITEAXIS axis) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char r = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_scaled_rotated_bitmap(sprite->GetImage(), al_map_rgba(r, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), a2de::Math::ToScreenScale(sprite->GetScaleX()), a2de::Math::ToScreenScale(sprite->GetScaleY()), sprite->GetAngle(), axis);

    al_set_target_bitmap(old_target_bmp);

}

void SpriteHandler::DrawScale(ALLEGRO_BITMAP* dest, Sprite* sprite) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char r = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_scaled_bitmap(sprite->GetImage(), al_map_rgba(r, g, b, alpha), 0, 0, sprite->GetWidth(), sprite->GetHeight(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), a2de::Math::ToScreenScale(sprite->GetWidth() * sprite->GetScaleX()), a2de::Math::ToScreenScale(sprite->GetHeight() * sprite->GetY()), 0);
    
    al_set_target_bitmap(old_target_bmp);

}

void SpriteHandler::DrawRotateWorldSpace(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double /*radius*/) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;

    if(alpha == 0) return;

    ALLEGRO_TRANSFORM allegro_t;
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]
    
    a2de::Matrix4x4 t = a2de::Matrix4x4::GetTranslationMatrix(x, y, 0.0);
    a2de::Matrix4x4 r = a2de::Matrix4x4::Get3DZRotationMatrix(sprite->GetAngle());
    a2de::Matrix4x4 s = a2de::Matrix4x4::GetScaleMatrix(sprite->GetScaleX(), sprite->GetScaleY(), 1.0);
    a2de::Matrix4x4 t_inv = a2de::Matrix4x4::GetTranslationMatrix(-x, -y, 0.0);

    a2de::Matrix4x4 m = t * r * s * t_inv;

    allegro_t.m[0][0] = m.GetIndex(0);
    allegro_t.m[0][1] = m.GetIndex(1);
    allegro_t.m[0][2] = m.GetIndex(2);
    allegro_t.m[0][3] = m.GetIndex(3);

    allegro_t.m[1][0] = m.GetIndex(4);
    allegro_t.m[1][1] = m.GetIndex(5);
    allegro_t.m[1][2] = m.GetIndex(6);
    allegro_t.m[1][3] = m.GetIndex(7);

    allegro_t.m[2][0] = m.GetIndex(8);
    allegro_t.m[2][1] = m.GetIndex(9);
    allegro_t.m[2][2] = m.GetIndex(10);
    allegro_t.m[2][3] = m.GetIndex(11);

    allegro_t.m[3][0] = m.GetIndex(12);
    allegro_t.m[3][1] = m.GetIndex(13);
    allegro_t.m[3][2] = m.GetIndex(14);
    allegro_t.m[3][3] = m.GetIndex(15);

    ALLEGRO_TRANSFORM old_transform = *al_get_current_transform();
    al_use_transform(&allegro_t);

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    unsigned char red = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    al_draw_tinted_rotated_bitmap(sprite->GetImage(), al_map_rgba(red, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), sprite->GetAngle(), 0);

    al_set_target_bitmap(old_target_bmp);

    al_use_transform(&old_transform);

}

void SpriteHandler::DrawRotateWorldSpaceScale(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double /*radius*/) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char red = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_TRANSFORM allegro_t;
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]

    a2de::Matrix4x4 t = a2de::Matrix4x4::GetTranslationMatrix(x, y, 0.0);
    a2de::Matrix4x4 r = a2de::Matrix4x4::Get3DZRotationMatrix(sprite->GetAngle());
    a2de::Matrix4x4 s = a2de::Matrix4x4::GetScaleMatrix(sprite->GetScaleX(), sprite->GetScaleY(), 1.0);
    a2de::Matrix4x4 t_inv = a2de::Matrix4x4::GetTranslationMatrix(-x, -y, 0.0);

    a2de::Matrix4x4 m = t * r * s * t_inv;

    allegro_t.m[0][0] = m.GetIndex(0);
    allegro_t.m[0][1] = m.GetIndex(1);
    allegro_t.m[0][2] = m.GetIndex(2);
    allegro_t.m[0][3] = m.GetIndex(3);

    allegro_t.m[1][0] = m.GetIndex(4);
    allegro_t.m[1][1] = m.GetIndex(5);
    allegro_t.m[1][2] = m.GetIndex(6);
    allegro_t.m[1][3] = m.GetIndex(7);

    allegro_t.m[2][0] = m.GetIndex(8);
    allegro_t.m[2][1] = m.GetIndex(9);
    allegro_t.m[2][2] = m.GetIndex(10);
    allegro_t.m[2][3] = m.GetIndex(11);

    allegro_t.m[3][0] = m.GetIndex(12);
    allegro_t.m[3][1] = m.GetIndex(13);
    allegro_t.m[3][2] = m.GetIndex(14);
    allegro_t.m[3][3] = m.GetIndex(15);

    ALLEGRO_TRANSFORM old_transform = *al_get_current_transform();
    al_use_transform(&allegro_t);

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_scaled_rotated_bitmap(sprite->GetImage(), al_map_rgba(red, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), sprite->GetScaleX(), sprite->GetScaleY(), sprite->GetAngle(), 0);

    al_set_target_bitmap(old_target_bmp);

    al_use_transform(&old_transform);

}
void SpriteHandler::DrawRotateWorldSpaceFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double /*radius*/, SpriteHandler::SPRITEAXIS axis) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char red = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_TRANSFORM allegro_t;
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]

    a2de::Matrix4x4 t = a2de::Matrix4x4::GetTranslationMatrix(x, y, 0.0);
    a2de::Matrix4x4 r = a2de::Matrix4x4::Get3DZRotationMatrix(sprite->GetAngle());
    a2de::Matrix4x4 s = a2de::Matrix4x4::GetScaleMatrix(sprite->GetScaleX(), sprite->GetScaleY(), 1.0);
    a2de::Matrix4x4 t_inv = a2de::Matrix4x4::GetTranslationMatrix(-x, -y, 0.0);

    a2de::Matrix4x4 m = t * r * s * t_inv;

    allegro_t.m[0][0] = m.GetIndex(0);
    allegro_t.m[0][1] = m.GetIndex(1);
    allegro_t.m[0][2] = m.GetIndex(2);
    allegro_t.m[0][3] = m.GetIndex(3);

    allegro_t.m[1][0] = m.GetIndex(4);
    allegro_t.m[1][1] = m.GetIndex(5);
    allegro_t.m[1][2] = m.GetIndex(6);
    allegro_t.m[1][3] = m.GetIndex(7);

    allegro_t.m[2][0] = m.GetIndex(8);
    allegro_t.m[2][1] = m.GetIndex(9);
    allegro_t.m[2][2] = m.GetIndex(10);
    allegro_t.m[2][3] = m.GetIndex(11);

    allegro_t.m[3][0] = m.GetIndex(12);
    allegro_t.m[3][1] = m.GetIndex(13);
    allegro_t.m[3][2] = m.GetIndex(14);
    allegro_t.m[3][3] = m.GetIndex(15);

    ALLEGRO_TRANSFORM old_transform = *al_get_current_transform();
    al_use_transform(&allegro_t);

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_rotated_bitmap(sprite->GetImage(), al_map_rgba(red, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), sprite->GetAngle(), axis);

    al_set_target_bitmap(old_target_bmp);

    al_use_transform(&old_transform);

}

void SpriteHandler::DrawRotateWorldSpaceScaleFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double /*radius*/, SpriteHandler::SPRITEAXIS axis) {
    if(sprite == nullptr || dest == nullptr) return;

    unsigned char alpha = sprite->GetAlpha() * 255.0;
    unsigned char red = sprite->GetTint().r * 255.0;
    unsigned char g = sprite->GetTint().g * 255.0;
    unsigned char b = sprite->GetTint().b * 255.0;

    if(alpha == 0) return;

    ALLEGRO_TRANSFORM allegro_t;
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]
    //[0][0][0][0]

    a2de::Matrix4x4 t = a2de::Matrix4x4::GetTranslationMatrix(x, y, 0.0);
    a2de::Matrix4x4 r = a2de::Matrix4x4::Get3DZRotationMatrix(sprite->GetAngle());
    a2de::Matrix4x4 s = a2de::Matrix4x4::GetScaleMatrix(sprite->GetScaleX(), sprite->GetScaleY(), 1.0);
    a2de::Matrix4x4 t_inv = a2de::Matrix4x4::GetTranslationMatrix(-x, -y, 0.0);

    a2de::Matrix4x4 m = t * r * s * t_inv;

    allegro_t.m[0][0] = m.GetIndex(0);
    allegro_t.m[0][1] = m.GetIndex(1);
    allegro_t.m[0][2] = m.GetIndex(2);
    allegro_t.m[0][3] = m.GetIndex(3);

    allegro_t.m[1][0] = m.GetIndex(4);
    allegro_t.m[1][1] = m.GetIndex(5);
    allegro_t.m[1][2] = m.GetIndex(6);
    allegro_t.m[1][3] = m.GetIndex(7);

    allegro_t.m[2][0] = m.GetIndex(8);
    allegro_t.m[2][1] = m.GetIndex(9);
    allegro_t.m[2][2] = m.GetIndex(10);
    allegro_t.m[2][3] = m.GetIndex(11);

    allegro_t.m[3][0] = m.GetIndex(12);
    allegro_t.m[3][1] = m.GetIndex(13);
    allegro_t.m[3][2] = m.GetIndex(14);
    allegro_t.m[3][3] = m.GetIndex(15);

    ALLEGRO_TRANSFORM old_transform = *al_get_current_transform();
    al_use_transform(&allegro_t);

    ALLEGRO_BITMAP* old_target_bmp = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    al_draw_tinted_scaled_rotated_bitmap(sprite->GetImage(), al_map_rgba(red, g, b, alpha), sprite->GetCenterX(), sprite->GetCenterY(), a2de::Math::ToScreenScale(sprite->GetX()), a2de::Math::ToScreenScale(sprite->GetY()), sprite->GetScaleX(), sprite->GetScaleY(), sprite->GetAngle(), axis);

    al_set_target_bitmap(old_target_bmp);

    al_use_transform(&old_transform);

}

A2DE_END