//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#include "PointerInput.h"

#include <input_event.h>

PointerInput::PointerInput() : KWin::InputEventFilter(KWin::InputFilterOrder::Effects) {}

QPointF const& PointerInput::lastPosition() const { return mLastPosition; }

bool PointerInput::pointerMotion(KWin::PointerMotionEvent* event) {
  mLastPosition = event->position;
  return false;
}

bool PointerInput::tabletToolAxisEvent(KWin::TabletToolAxisEvent* event) {
  if (mStylusProximity) {
    mLastPosition = event->position;
  }
  return false;
}

bool PointerInput::tabletToolProximityEvent(KWin::TabletToolProximityEvent* event) {
  if (event->type == KWin::TabletToolProximityEvent::EnterProximity) {
    mStylusProximity = true;
    mLastPosition    = event->position;
  } else {
    mStylusProximity = false;
  }
  return false;
}