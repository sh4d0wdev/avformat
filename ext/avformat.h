#ifndef _AVFORMAT_FORMAT_H__
#define _AVFORMAT_FORMAT_H__

#include <libavformat/avformat.h>
#ifdef RSHIFT
    #undef RSHIFT
#endif

#include <ruby.h>

RUBY_EXTERN VALUE rb_cFormat;

RUBY_EXTERN VALUE rb_cRational;

VALUE build_stream_obj(AVStream *stream);
VALUE build_avcodec_obj(AVCodecContext *context);

void init_format(VALUE module);
void init_inputformat(VALUE module);
void init_stream(VALUE module);
void init_rational(VALUE module);
void init_avdiscard(VALUE module);
void init_avcodec(VALUE module);
void init_avmediatype(VALUE module);
#endif
