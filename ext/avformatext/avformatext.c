#include "avformatext.h"

VALUE r_av_register_all( void ) {
    av_register_all();
    return Qnil;
};



VALUE r_avformat_open_input_file(VALUE self, VALUE filename) {   
    AVFormatContext *ctx=NULL;
    char* fn;
    int res = 1;
    VALUE obj;
    Check_Type(filename, T_STRING);

    fn = StringValuePtr(filename);
    
    res = avformat_open_input(&ctx, fn, NULL, NULL);
    
    if (res != 0) {
        rb_raise(rb_eStandardError, "Could not open file");
        return Qnil;
    } else {
        obj = Data_Wrap_Struct(cAVFormatContext, NULL, r_avformat_context_free, ctx);
        rb_obj_call_init(obj, 0, NULL);
    }


    return obj;
};

VALUE r_avformat_close_input_file(VALUE self, VALUE context) {
    AVFormatContext *ctx;
    Data_Get_Struct(context, AVFormatContext, ctx);

    avformat_close_input(&ctx);
    ctx = avformat_alloc_context();
    return Qnil;
};



void Init_avformatext(void) {
    mAVFormat = rb_define_module("AVFormat");
    rb_define_module_function(mAVFormat, "av_register_all", r_av_register_all, 0);
    rb_define_module_function(mAVFormat, "avformat_open_input_file", r_avformat_open_input_file, 1);
    rb_define_module_function(mAVFormat, "avformat_close_input_file", r_avformat_close_input_file, 1);
    r_register_avformat_context_class(mAVFormat);
    r_register_avstream_class(mAVFormat);
};
