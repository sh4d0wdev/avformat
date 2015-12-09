#include "avformat_context.h"

VALUE r_avformat_context_allocate(VALUE klass) {
    rb_raise(rb_eRuntimeError, "You can't create instance of AVFormatContext");
    return Qnil;
};

void  r_avformat_context_free(AVFormatContext *p) {
    //someone already used free
    if (!p) return;

    if (p->iformat != NULL)
        avformat_close_input(&p);
    avformat_free_context(p);

};


VALUE r_avformat_context_initialize(VALUE self) {
    return self;
}

VALUE r_avformat_context_metadata(VALUE self) {
    AVFormatContext *ctx;
    AVDictionaryEntry *t = NULL;
    VALUE result = rb_hash_new();
    Data_Get_Struct(self, AVFormatContext, ctx);
    
    while (t = av_dict_get(ctx->metadata, "", t, AV_DICT_IGNORE_SUFFIX)) {
        rb_hash_aset(result, rb_str_new2(t->key), rb_str_new2(t->value));
    }
    return result;
};


VALUE r_avformat_context_duration(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return INT2NUM(ctx->duration);
};

VALUE r_avformat_context_bit_rate(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return INT2NUM(ctx->bit_rate);
};


VALUE r_avformat_context_start_time(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return INT2NUM(ctx->start_time);
};

VALUE r_avformat_context_filename(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return rb_str_new2(ctx->filename);
};


void r_register_avformat_context_class(VALUE module) {
    // AVFormat::AVFormatContext
    cAVFormatContext = rb_define_class_under(module, "AVFormatContext", rb_cObject);
    rb_define_alloc_func(cAVFormatContext, r_avformat_context_allocate);
    rb_define_method(cAVFormatContext, "initialize", r_avformat_context_initialize, 0);

    rb_define_method(cAVFormatContext, "metadata", r_avformat_context_metadata, 0);
    rb_define_method(cAVFormatContext, "duration", r_avformat_context_duration, 0);
    rb_define_method(cAVFormatContext, "bit_rate", r_avformat_context_bit_rate, 0);
    rb_define_method(cAVFormatContext, "filename", r_avformat_context_filename, 0);
    rb_define_method(cAVFormatContext, "start_time", r_avformat_context_start_time, 0);
}
