#include "avformat.h"

VALUE rb_cStream;

static VALUE alloc_stream(VALUE klass){
 AVStream *stream = avformat_new_stream(NULL, 0);
 return Data_Wrap_Struct(klass, 0, 0, stream);
};

static VALUE stream_initialize(VALUE self){
    return self;
};

static VALUE stream_duration(VALUE self){
    AVStream *stream;
    Data_Get_Struct(self, AVStream, stream);
    return INT2NUM(stream->duration);
};

static VALUE stream_metadata(VALUE self) {
    AVStream *stream;
    AVDictionaryEntry * t = NULL;
    VALUE result = rb_hash_new();
    Data_Get_Struct(self, AVStream, stream);
    
    while (t = av_dict_get(stream->metadata, "", t, AV_DICT_IGNORE_SUFFIX)) {
        rb_hash_aset(result, rb_str_new2(t->key), rb_str_new2(t->value));
    }
    av_free(t);
    return result;
};

VALUE build_stream_obj(AVStream *stream){
    VALUE obj = Data_Wrap_Struct(rb_cStream, 0, 0, stream);
    
    return obj;
}

void register_stream(VALUE module) {
    rb_cStream = rb_define_class_under(module, "Stream", rb_cObject);
    rb_define_alloc_func(rb_cStream, alloc_stream);
    rb_define_method(rb_cStream, "initialize", stream_initialize, 0);
    rb_define_method(rb_cStream, "duration", stream_duration, 0);
    rb_define_method(rb_cStream, "metadata", stream_metadata, 0);
}
