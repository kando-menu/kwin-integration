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
  bool tabletToolAxisEvent(KWin::TabletToolAxisEvent* event) override;
  bool tabletToolProximityEvent(KWin::TabletToolProximityEvent* event) override;

 private:
  QPointF mLastPosition{0.0, 0.0};
  bool mStylusProximity{false};
};