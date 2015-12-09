#ifndef __RB_AVFORMAT_CONTEXT_H__
#define __RB_AVFORMAT_CONTEXT_H__

#include <ruby.h>
#include <libavformat/avformat.h>

/*************************
 * class AVFormatContext *
 *************************/
VALUE cAVFormatContext;

// memory allocation/free
VALUE r_avformat_context_allocate(VALUE klass);
void r_avformat_context_free(AVFormatContext *p);
void r_avformat_context_mark(void *p);

// initialization 
VALUE r_avformat_context_initialize(VALUE self);

// instance read methods
VALUE r_avformat_context_metadata(VALUE self);
VALUE r_avformat_context_duration(VALUE self);
VALUE r_avformat_context_bit_rate(VALUE self);
VALUE r_avformat_context_filename(VALUE self);

// register data
void r_register_avformat_context_class(VALUE module);
#endif 
