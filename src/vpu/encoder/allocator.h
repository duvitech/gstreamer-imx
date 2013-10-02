/* VPU encoder specific allocator
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


#ifndef GST_IMX_VPU_ENCODER_ALLOCATOR_H
#define GST_IMX_VPU_ENCODER_ALLOCATOR_H

#include <glib.h>
#include "../../common/phys_mem_allocator.h"


G_BEGIN_DECLS


typedef struct _GstImxVpuEncAllocator GstImxVpuEncAllocator;
typedef struct _GstImxVpuEncAllocatorClass GstImxVpuEncAllocatorClass;
typedef struct _GstImxVpuEncMemory GstImxVpuEncMemory;


#define GST_TYPE_IMX_VPU_ENC_ALLOCATOR             (gst_imx_vpu_enc_allocator_get_type())
#define GST_IMX_VPU_ENC_ALLOCATOR(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_IMX_VPU_ENC_ALLOCATOR, GstImxVpuEncAllocator))
#define GST_IMX_VPU_ENC_ALLOCATOR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_IMX_VPU_ENC_ALLOCATOR, GstImxVpuEncAllocatorClass))
#define GST_IS_IMX_VPU_ENC_ALLOCATOR(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_IMX_VPU_ENC_ALLOCATOR))
#define GST_IS_IMX_VPU_ENC_ALLOCATOR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_IMX_VPU_ENC_ALLOCATOR))

#define GST_IMX_VPU_ENC_ALLOCATOR_MEM_TYPE "ImxVpuEncMemory"


struct _GstImxVpuEncAllocator
{
	GstImxPhysMemAllocator parent;
};


struct _GstImxVpuEncAllocatorClass
{
	GstImxPhysMemAllocatorClass parent_class;
};


GType gst_imx_vpu_enc_allocator_get_type(void);
GstAllocator* gst_imx_vpu_enc_allocator_obtain(void);


G_END_DECLS


#endif


