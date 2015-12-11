#include "avformatext.h"

VALUE rb_av_register_all( void ) {
    av_register_all();
    return Qnil;
};

void Init_avformatext(void) {
    rb_mAVFormat = rb_define_module("AVFormat");
    rb_define_module_function(rb_mAVFormat, "av_register_all", rb_av_register_all, 0);
    register_format(rb_mAVFormat);
    register_inputformat(rb_mAVFormat);

};
