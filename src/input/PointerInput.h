//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#pragma once

#include <input.h>

#include <QPoint>

class PointerInput : public KWin::InputEventFilter {
 public:
  PointerInput();
  ~PointerInput() override = default;

  QPointF const& lastPosition() const;

  bool pointerMotion(KWin::PointerMotionEvent* event) override;

#if defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_STRUCT_EVENTS)
  bool tabletToolAxisEvent(KWin::TabletToolAxisEvent* event) override;
  bool tabletToolProximityEvent(KWin::TabletToolProximityEvent* event) override;
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_TABLET_EVENT)
  bool tabletToolAxisEvent(KWin::TabletEvent* event) override;
  bool tabletToolProximityEvent(KWin::TabletEvent* event) override;
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_EVENT)
  bool tabletToolEvent(KWin::TabletEvent* event) override;
#endif

 private:
  QPointF mLastPosition{0.0, 0.0};
  bool mStylusProximity{false};
};