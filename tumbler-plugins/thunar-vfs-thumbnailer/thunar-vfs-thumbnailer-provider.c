/* vi:set et ai sw=2 sts=2 ts=2: */
/*-
 * Copyright (c) 2009 Jannis Pohlmann <jannis@xfce.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General 
 * Public License along with this library; if not, write to the 
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib.h>
#include <glib-object.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include <tumbler/tumbler.h>

#include <thunar-vfs-thumbnailer-provider.h>
#include <thunar-vfs-thumbnailer.h>



static void   thunar_vfs_thumbnailer_provider_thumbnailer_provider_init (TumblerThumbnailerProviderIface *iface);
static GList *thunar_vfs_thumbnailer_provider_get_thumbnailers          (TumblerThumbnailerProvider      *provider);



struct _ThunarVfsThumbnailerProviderClass
{
  GObjectClass __parent__;
};

struct _ThunarVfsThumbnailerProvider
{
  GObject __parent__;
};



G_DEFINE_DYNAMIC_TYPE_EXTENDED (ThunarVfsThumbnailerProvider,
                                thunar_vfs_thumbnailer_provider,
                                G_TYPE_OBJECT,
                                0,
                                TUMBLER_ADD_INTERFACE (TUMBLER_TYPE_THUMBNAILER_PROVIDER,
                                                       thunar_vfs_thumbnailer_provider_thumbnailer_provider_init));



void
thunar_vfs_thumbnailer_provider_register (TumblerProviderPlugin *plugin)
{
  thunar_vfs_thumbnailer_provider_register_type (G_TYPE_MODULE (plugin));
}



static void
thunar_vfs_thumbnailer_provider_class_init (ThunarVfsThumbnailerProviderClass *klass)
{
  GObjectClass *gobject_class;

  gobject_class = G_OBJECT_CLASS (klass);
}



static void
thunar_vfs_thumbnailer_provider_class_finalize (ThunarVfsThumbnailerProviderClass *klass)
{
}



static void
thunar_vfs_thumbnailer_provider_thumbnailer_provider_init (TumblerThumbnailerProviderIface *iface)
{
  iface->get_thumbnailers = thunar_vfs_thumbnailer_provider_get_thumbnailers;
}



static void
thunar_vfs_thumbnailer_provider_init (ThunarVfsThumbnailerProvider *provider)
{
}



static GList *
thunar_vfs_thumbnailer_provider_get_thumbnailers (TumblerThumbnailerProvider *provider)
{
  ThunarVfsThumbnailer *thumbnailer;
  GList                *thumbnailers = NULL;
  const gchar          *uri_schemes[] = { NULL, };
  const gchar          *mime_types[] = { NULL, };

  /* create the pixbuf thumbnailer */
  thumbnailer = g_object_new (TYPE_THUNAR_VFS_THUMBNAILER, "mime-types", mime_types,
                              "uri-schemes", uri_schemes, NULL);

  /* add the thumbnailer to the list */
  thumbnailers = g_list_append (thumbnailers, thumbnailer);

  return thumbnailers;
}
