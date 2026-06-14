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

PointerInput::PointerInput() : KWin::InputEventFilter(KWin::InputFilterOrder::Effects) {}

QPointF const& PointerInput::lastPosition() const { return mLastPosition; }

bool PointerInput::pointerMotion(KWin::PointerMotionEvent* event) {
  mLastPosition = event->position;
  return false;
}

#if defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_STRUCT_EVENTS)
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
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_TABLET_EVENT)
bool PointerInput::tabletToolAxisEvent(KWin::TabletEvent* event) {
  if (mStylusProximity) {
    mLastPosition = event->globalPosition();
  }
  return false;
}

bool PointerInput::tabletToolProximityEvent(KWin::TabletEvent* event) {
  if (event->type() == QEvent::TabletEnterProximity) {
    mStylusProximity = true;
    mLastPosition    = event->globalPosition();
  } else {
    mStylusProximity = false;
  }
  return false;
}
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_EVENT)
bool PointerInput::tabletToolEvent(KWin::TabletEvent* event) {
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

  return false;
}
#endif