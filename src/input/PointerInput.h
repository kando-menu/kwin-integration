//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#pragma once

#include <input_event_spy.h>

#include <QPoint>

// An InputEventSpy sees every event before InputEventFilters do, so unlike a filter it
// still receives pointer motion while KWin's drag-and-drop filter has grabbed the
// pointer.
class PointerInput : public KWin::InputEventSpy {
 public:
  PointerInput();
  ~PointerInput() override = default;

  QPointF const& lastPosition() const;

  void pointerMotion(KWin::PointerMotionEvent* event) override;

#if defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_STRUCT_EVENTS)
  void tabletToolAxisEvent(KWin::TabletToolAxisEvent* event) override;
  void tabletToolProximityEvent(KWin::TabletToolProximityEvent* event) override;
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_TABLET_EVENT)
  void tabletToolAxisEvent(KWin::TabletEvent* event) override;
  void tabletToolProximityEvent(KWin::TabletEvent* event) override;
#elif defined(KANDO_KWIN_HAS_TABLET_TOOL_EVENT)
  void tabletToolEvent(KWin::TabletEvent* event) override;
#endif

 private:
  QPointF mLastPosition{0.0, 0.0};
  bool mStylusProximity{false};
};