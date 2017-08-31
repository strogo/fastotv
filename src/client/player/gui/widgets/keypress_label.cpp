/*  Copyright (C) 2014-2017 FastoGT. All right reserved.

    This file is part of FastoTV.

    FastoTV is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoTV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoTV. If not, see <http://www.gnu.org/licenses/>.
*/

#include "client/player/gui/widgets/keypress_label.h"

#include <common/application/application.h>

namespace fastotv {
namespace client {
namespace player {
namespace gui {

KeyPressLabel::KeyPressLabel(const SDL_Color& back_ground_color) : base_class(back_ground_color) {
  fApp->Subscribe(this, gui::events::KeyPressEvent::EventType);
  fApp->Subscribe(this, gui::events::KeyReleaseEvent::EventType);
}

KeyPressLabel::~KeyPressLabel() {}

void KeyPressLabel::HandleKeyPressEvent(player::gui::events::KeyPressEvent* event) {
  const player::gui::events::KeyPressInfo inf = event->GetInfo();
  const SDL_Keycode key_code = inf.ks.sym;
  const Uint16 modifier = inf.ks.mod;
  UNUSED(modifier);
  if (isprint(key_code)) {
    text_ += key_code;
  } else if (key_code == SDLK_BACKSPACE) {
    text_.pop_back();
  }
}

void KeyPressLabel::HandleKeyReleaseEvent(player::gui::events::KeyReleaseEvent* event) {
  UNUSED(event);
}

}  // namespace gui
}  // namespace player
}  // namespace client
}  // namespace fastotv