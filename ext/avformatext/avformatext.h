#ifndef __RB_AVFORMT_EXT_H__
#define __RB_AVFORMT_EXT_H__

#include <libavformat/avformat.h>

#include "ruby.h"
#include "avformat_context.h"
#include "avformat_stream.h"


// module AVFormat
VALUE mAVFormat;

VALUE r_av_register_all(void);
VALUE r_avformat_open_input_file(VALUE self, VALUE filename);
VALUE r_avformat_close_input_file(VALUE self, VALUE context);


#endif
