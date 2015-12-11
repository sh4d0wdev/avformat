#include "format.h"

/*****************************************
 *                                       *
 * AVFormat::Format constuct and destroy *
 *                                       *
 *****************************************/

VALUE alloc_format(VALUE klass){
    AVFormatContext * ctx =  avformat_alloc_context();
    ctx->oformat = NULL;
    ctx->iformat = NULL;
    return Data_Wrap_Struct(klass, 0, free_format, ctx);
}

void free_format(AVFormatContext * ctx){
    if (ctx == NULL)
        return;
    for(int i = 0; i < ctx->nb_streams; i++) {
        if (ctx->streams[i]->codec->codec != NULL){
            avcodec_close(ctx->streams[i]->codec);
        } 
    }
    //InputFormat
    if (ctx->iformat){
        avformat_close_input(&ctx);
    } else {
        av_free(ctx);
    }
};

VALUE format_initilize(VALUE self){
    return self;
};


/************************************
*                                   *
* AVFormat::Format instance methods *
*                                   *
*************************************/

VALUE format_duration(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return INT2NUM(ctx->duration);
};

VALUE format_bit_rate(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return INT2NUM(ctx->bit_rate);
};


VALUE format_start_time(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return INT2NUM(ctx->start_time);
};

VALUE format_filename(VALUE self) {
    AVFormatContext *ctx;
    Data_Get_Struct(self, AVFormatContext, ctx);
    return rb_str_new2(ctx->filename);
};

VALUE format_metadata(VALUE self) {
    AVFormatContext * ctx;
    AVDictionaryEntry * t = NULL;
    VALUE result = rb_hash_new();
    Data_Get_Struct(self, AVFormatContext, ctx);
    
    while (t = av_dict_get(ctx->metadata, "", t, AV_DICT_IGNORE_SUFFIX)) {
        rb_hash_aset(result, rb_str_new2(t->key), rb_str_new2(t->value));
    }
    return result;
};


/****************
 *              *
 * Registration *
 *              *
 ****************/
void register_format(VALUE module) {
    rb_cFormat = rb_define_class_under(module, "Format", rb_cObject);
    
    rb_define_alloc_func(rb_cFormat, alloc_format);
    rb_define_method(rb_cFormat, "initialize", format_initilize, 0);
    rb_define_method(rb_cFormat, "metadata",  format_metadata, 0);
    rb_define_method(rb_cFormat, "duration", format_duration, 0);
    rb_define_method(rb_cFormat, "filename", format_filename, 0);
    rb_define_method(rb_cFormat, "start_time", format_start_time, 0);
    rb_define_method(rb_cFormat, "bit_rate", format_bit_rate, 0);
};
