/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <mach/video.h>
#include <kern/strings.h>

#define VIDEO_ADDRESS 0xb8000

/* Reset video */
void video_reset()
{
    vm_address16_t *video_address = (vm_address16_t *)VIDEO_ADDRESS;

    for (unsigned int y = 0; y < 25; y++)
    {
        for (unsigned int x = 0; x < 80; x++)
            video_address[(y * 80) + x] = (uint16)' ' | (uint16)0x00 << 8;
    }
}

/* Write to video at xy coordinates */
void video_write(x, y, value)
    video_coordinate x;
    video_coordinate y;
    uint32 value;
{
    vm_address16_t *video_address = (vm_address16_t *)VIDEO_ADDRESS;
    const vm_offset_t video_offset = (y * 80) + x;

    *(video_address + video_offset) = ((uint16)(value & 0xff) | (uint16)(value & 0xff00)) & 0xffff;
}

/* Copy video area */
void video_copy(x1, y1, x2, y2, size)
    video_coordinate x1;
    video_coordinate y1;
    video_coordinate x2;
    video_coordinate y2;
    uint32 size;
{
    vm_address16_t *video_address1 = (vm_address16_t *)VIDEO_ADDRESS + ((y1 * 80) + x1);
    vm_address16_t *video_address2 = (vm_address16_t *)VIDEO_ADDRESS + ((y2 * 80) + x2);

    memcpy(video_address1, video_address2, size);
}