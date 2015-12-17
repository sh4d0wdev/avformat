#include "avformat.h"

/***********
   STATICS 
************/

/*******************
   module AVFormat
********************/
VALUE rb_mAVFormat;

/**********************
  func av_register_all
************************/
static VALUE rb_av_register_all( void ) {
    av_register_all();
    return Qnil;
};

void Init_rubyavformat(void) {
    rb_mAVFormat = rb_define_module("AVFormat");
    rb_define_module_function(rb_mAVFormat, "av_register_all", rb_av_register_all, 0);
    register_format(rb_mAVFormat);
    register_inputformat(rb_mAVFormat);
    register_stream(rb_mAVFormat);
};
