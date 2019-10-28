/*
 * Copyright (C) 2019, Matthias Clasen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <portal-helpers.h>

G_BEGIN_DECLS

/**
 * XdpWallpaperTarget:
 * @XDP_WALLPAPER_TARGET_BACKGROUND: Set wallpaper on the desktop background
 * @XDP_WALLPAPER_TARGET_LOCKSCREEN: Set wallpaper on the lockscreen
 *
 * The values of this enumeration determine where the wallpaper is being set.
 */
typedef enum {
  XDP_WALLPAPER_TARGET_BACKGROUND = 1 << 0,
  XDP_WALLPAPER_TARGET_LOCKSCREEN = 1 << 1
} XdpWallpaperTarget;

#define XDP_WALLPAPER_TARGET_BOTH (XDP_WALLPAPER_TARGET_BACKGROUND|XDP_WALLPAPER_TARGET_LOCKSCREEN)

XDP_PUBLIC
void       xdp_portal_set_wallpaper           (XdpPortal            *portal,
                                               XdpParent            *parent,
                                               const char           *uri,
                                               gboolean              show_preview,
                                               XdpWallpaperTarget    target,
                                               GCancellable         *cancellable,
                                               GAsyncReadyCallback   callback,
                                               gpointer              data);

XDP_PUBLIC
gboolean  xdp_portal_set_wallpaper_finish     (XdpPortal            *portal,
                                               GAsyncResult         *result,
                                               GError              **error);

G_END_DECLS