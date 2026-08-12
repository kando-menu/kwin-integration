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

#include <QEvent>

PointerInput::PointerInput() : KWin::InputEventSpy() {}

QPointF const& PointerInput::lastPosition() const { return mLastPosition; }

void PointerInput::pointerMotion(KWin::PointerMotionEvent* event) {
  mLastPosition = event->position;
}

#if defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_STRUCT_EVENTS)
void PointerInput::tabletToolAxisEvent(KWin::TabletToolAxisEvent* event) {
  if (mStylusProximity) {
    mLastPosition = event->position;
  }
}

void PointerInput::tabletToolProximityEvent(KWin::TabletToolProximityEvent* event) {
  if (event->type == KWin::TabletToolProximityEvent::EnterProximity) {
    mStylusProximity = true;
    mLastPosition    = event->position;
  } else {
    mStylusProximity = false;
  }
}
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_TABLET_EVENT)
void PointerInput::tabletToolAxisEvent(KWin::TabletEvent* event) {
  if (mStylusProximity) {
    mLastPosition = event->globalPosition();
  }
}

void PointerInput::tabletToolProximityEvent(KWin::TabletEvent* event) {
  if (event->type() == QEvent::TabletEnterProximity) {
    mStylusProximity = true;
    mLastPosition    = event->globalPosition();
  } else {
    mStylusProximity = false;
  }
}
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_EVENT)
void PointerInput::tabletToolEvent(KWin::TabletEvent* event) {
  switch (event->type()) {
    case QEvent::TabletEnterProximity:
      mStylusProximity = true;
      mLastPosition    = event->globalPosition();
      break;

    case QEvent::TabletLeaveProximity:
      mStylusProximity = false;
      break;

    default:
      if (mStylusProximity) {
        mLastPosition = event->globalPosition();
      }
      break;
  }
}
#endif