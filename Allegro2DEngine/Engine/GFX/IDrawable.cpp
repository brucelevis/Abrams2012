#include "IDrawable.h"

void a2de::IDrawable::Draw(ALLEGRO_BITMAP* /*dest*/) {
    /* DO NOTHING */
}

void a2de::IDrawable::SetZIndex(unsigned long z_index) {
    _z_index = z_index;
}

unsigned long a2de::IDrawable::GetZOrder() const {
    return _z_index;
}

unsigned long a2de::IDrawable::GetZOrder() {
    return static_cast<const IDrawable&>(*this).GetZOrder();
}
