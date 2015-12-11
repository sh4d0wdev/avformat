#ifndef _AVFORMAT_EXT_H__
#define _AVFORMAT_EXT_H__

#include <libavformat/avformat.h>

#include "ruby.h"
#include "format.h"
#include "input_format.h"

// module AVFormat
VALUE rb_mAVFormat;

VALUE rb_av_register_all(void);


#endif
