#ifndef _AVFORMAT_FORMAT_H__
#define _AVFORMAT_FORMAT_H__

#include <libavformat/avformat.h>
#ifdef RSHIFT
    #undef RSHIFT
#endif

#include <ruby.h>

RUBY_EXTERN VALUE rb_cFormat;

VALUE build_stream_obj(AVStream *stream);

void register_format(VALUE module);
void register_inputformat(VALUE module);
void register_stream(VALUE module);
#endif
