#include "input_format.h"

VALUE inputformat_initilize(VALUE self){

    return self;
};

VALUE inputformat_open(VALUE self, VALUE filename){
    AVFormatContext * ctx=NULL;
    char* fn;
    int res = 1;
    Check_Type(filename, T_STRING);

    fn = StringValuePtr(filename);
    Data_Get_Struct(self, AVFormatContext, ctx);
    res = avformat_open_input(&ctx, fn, NULL, NULL);
    return self;
};

VALUE inputformat_close(VALUE self) {
    AVFormatContext * ctx = NULL;
    Data_Get_Struct(self, AVFormatContext, ctx);
    avformat_close_input(&ctx);
    //reallocate context, since avformat_close_input calls avfree
    DATA_PTR(self) = avformat_alloc_context();
    return self;
};


void register_inputformat(VALUE module) {
    rb_cInputFormat = rb_define_class_under(module, "InputFormat", rb_cFormat);
    rb_define_method(rb_cInputFormat, "initialize", inputformat_initilize, 0);
    rb_define_method(rb_cInputFormat, "open", inputformat_open, 1);
    rb_define_method(rb_cInputFormat, "close", inputformat_close, 0);
};