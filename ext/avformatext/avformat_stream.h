#ifndef __RB_AVSTREAM_H__
#define __RB_AVSTREAM_H__

#include "ruby.h"
#include <libavformat/avformat.h>

/*******************
 * class AVStream  *
 *******************/
VALUE cAVStream;

// memory allocation/free
VALUE r_avstream_allocate(VALUE klass);
void r_avstream_free(AVStream *p);
void r_avstream_mark(void *p);

// initialization 
VALUE r_avstream_initialize(VALUE self);

// instance read methods
VALUE r_avstream_metadata(VALUE self);
VALUE r_avstream_duration(VALUE self);
VALUE r_avstream_bit_rate(VALUE self);

// register data
void r_register_avstream_class(VALUE module);
#endif
