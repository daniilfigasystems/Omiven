/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _MACH_VIDEO_H_
#define _MACH_VIDEO_H_

#include <mach/std_types.h>
#include <kern/strings.h>

typedef uint32 video_coordinate;

/* Reset video */
void video_reset();

/* Write to video at xy coordinates */
void video_write(video_coordinate x, video_coordinate y, uint32 value);

/* Copy video area */
void video_copy(video_coordinate x1, video_coordinate y1, video_coordinate x2, video_coordinate y2, uint32 size);

#endif /* !_MACH_VIDEO_H_! */