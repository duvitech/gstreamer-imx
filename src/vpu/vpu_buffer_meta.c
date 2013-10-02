/* GStreamer meta data structure for VPU specific buffer information
 * Copyright (C) 2013  Carlos Rafael Giani
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include "vpu_buffer_meta.h"


static gboolean gst_imx_vpu_buffer_meta_init(GstMeta *meta, G_GNUC_UNUSED gpointer params, G_GNUC_UNUSED GstBuffer *buffer)
{
	GstImxVpuBufferMeta *imx_vpu_meta = (GstImxVpuBufferMeta *)meta;
	imx_vpu_meta->framebuffer = NULL;
	imx_vpu_meta->not_displayed_yet = FALSE;
	return TRUE;
}


static void gst_imx_vpu_buffer_meta_free(GstMeta *meta, G_GNUC_UNUSED GstBuffer *buffer)
{
	GstImxVpuBufferMeta *imx_vpu_meta = (GstImxVpuBufferMeta *)meta;
	imx_vpu_meta->framebuffer = NULL;
}


GType gst_imx_vpu_buffer_meta_api_get_type(void)
{
	static volatile GType type;
	static gchar const *tags[] = { "imx_vpu", NULL };

	if (g_once_init_enter(&type))
	{
		GType _type = gst_meta_api_type_register("GstImxVpuBufferMetaAPI", tags);
		g_once_init_leave(&type, _type);
	}

	return type;
}


GstMetaInfo const * gst_imx_vpu_buffer_meta_get_info(void)
{
	static GstMetaInfo const *meta_buffer_imx_vpu_info = NULL;

	if (g_once_init_enter(&meta_buffer_imx_vpu_info))
	{
		GstMetaInfo const *meta = gst_meta_register(
			gst_imx_vpu_buffer_meta_api_get_type(),
			"GstImxVpuBufferMeta",
			sizeof(GstImxVpuBufferMeta),
			GST_DEBUG_FUNCPTR(gst_imx_vpu_buffer_meta_init),
			GST_DEBUG_FUNCPTR(gst_imx_vpu_buffer_meta_free),
			(GstMetaTransformFunction)NULL
		);
		g_once_init_leave(&meta_buffer_imx_vpu_info, meta);
	}

	return meta_buffer_imx_vpu_info;
}

