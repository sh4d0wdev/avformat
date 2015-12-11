#ifndef __AVFORMAT_INPUT_FORMAT_H__
#define __AVFORMAT_INPUT_FORMAT_H__

#include <ruby.h>

#include <libavformat/avformat.h>
#include "format.h"

VALUE rb_cInputFormat;

VALUE inputformat_initilize(VALUE self);
VALUE inputformat_open(VALUE self, VALUE filename);
VALUE inputformat_close(VALUE self);
VALUE inputformat_metadata(VALUE self);

void register_inputformat(VALUE module);
#endif
