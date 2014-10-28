#include "CRenderManager.h"

#include <allegro5/drawing.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/bitmap_lock.h>

#include "../Math/CShape.h"
#include "../Physics/IBoundingBox.h"
#include "IDrawable.h"
#include "CSprite.h"
#include "../Objects/ADTObject.h"


A2DE_BEGIN


RenderManager* RenderManager::_instance = nullptr;

RenderManager* RenderManager::GetInstance(ALLEGRO_DISPLAY& display) {
    if(_instance != nullptr) return _instance;

    _instance = new RenderManager(display);

    return _instance;
}

RenderManager::RenderManager(ALLEGRO_DISPLAY& display) : _display_context(&display) { /* DO NOTHING */ }

RenderManager::~RenderManager() {
    _display_context = nullptr;
}

void RenderManager::RenderObject(Object* object) {
    if(object == nullptr) return;
    object->Draw(al_get_backbuffer(_display_context));
}

void RenderManager::RenderObject(Sprite* sprite) {
    if(sprite == nullptr) return;
    sprite->Draw(al_get_backbuffer(_display_context));
}

void RenderManager::RenderObject(Shape* shape) {
    if(shape == nullptr) return;
    shape->Draw(al_get_backbuffer(_display_context));
}

void RenderManager::RenderObject(IBoundingBox* bounding_box) {
    if(bounding_box == nullptr) return;
    bounding_box->Draw(al_get_backbuffer(_display_context));
}

void RenderManager::RenderObject(IDrawable* drawable) {
    if(drawable == nullptr) return;
    drawable->Draw(al_get_backbuffer(_display_context));
}

void RenderManager::RenderObjectAt(Object* object, const a2de::Vector2D& screen_position) {
    if(object == nullptr) return;
    a2de::Vector2D old_pos(object->GetBody()->GetPosition());
    object->GetBody()->SetPosition(screen_position);
    object->Draw(al_get_backbuffer(_display_context));
    object->GetBody()->SetPosition(old_pos);
}

void RenderManager::RenderObjectAt(Sprite* sprite, const a2de::Vector2D& screen_position) {
    if(sprite == nullptr) return;
    a2de::Vector2D old_pos(sprite->GetPosition());
    sprite->SetPosition(screen_position);
    sprite->Draw(al_get_backbuffer(_display_context));
    sprite->SetPosition(old_pos);
}

void RenderManager::RenderObjectAt(Shape* shape, const a2de::Vector2D& screen_position) {
    if(shape == nullptr) return;
    a2de::Vector2D old_pos(shape->GetPosition());
    shape->SetPosition(screen_position);
    shape->Draw(al_get_backbuffer(_display_context));
    shape->SetPosition(old_pos);
}

void RenderManager::RenderObjectAt(IBoundingBox* bounding_box, const a2de::Vector2D& screen_position) {
    if(bounding_box == nullptr) return;
    a2de::Vector2D old_pos(bounding_box->GetTransform().GetPosition());
    bounding_box->GetTransform().SetPosition(screen_position);
    bounding_box->Draw(al_get_backbuffer(_display_context));
    bounding_box->GetTransform().SetPosition(old_pos);
}


A2DE_END
