#ifndef _AVFORMAT_FORMAT_H__
#define _AVFORMAT_FORMAT_H__

#include<ruby.h>

#include <libavformat/avformat.h>

VALUE rb_cFormat;

VALUE alloc_format(VALUE klass);
void  free_format(AVFormatContext *ctx);

VALUE format_initilize(VALUE self);
VALUE format_metadata(VALUE self);
VALUE format_duration(VALUE self);
VALUE format_filename(VALUE self);
VALUE format_bit_rate(VALUE self);
VALUE format_start_time(VALUE self);


void register_format(VALUE module);
#endif
