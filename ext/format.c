#include "avformat.h"

/*****************************************
 *                                       *
 * AVFormat::Format constuct and destroy *
 *                                       *
 *****************************************/
VALUE rb_cFormat;

static void free_format(AVFormatContext * ctx){
	if (ctx == NULL)
		return;
	for(unsigned int i = 0; i < ctx->nb_streams; i++) {
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

static VALUE format_initilize(VALUE self){
	return self;
};

static VALUE alloc_format(VALUE klass){
	AVFormatContext * ctx =  avformat_alloc_context();
	ctx->oformat = NULL;
	ctx->iformat = NULL;
	return Data_Wrap_Struct(klass, 0, free_format, ctx);
};

/************************************
*                                   *
* AVFormat::Format instance methods *
*                                   *
*************************************/



static VALUE format_bit_rate(VALUE self) {
	AVFormatContext *ctx;
	Data_Get_Struct(self, AVFormatContext, ctx);
	return INT2NUM(ctx->bit_rate);
};


static VALUE format_start_time(VALUE self) {
	AVFormatContext *ctx;
	Data_Get_Struct(self, AVFormatContext, ctx);
	return INT2NUM(ctx->start_time);
};

static VALUE format_filename(VALUE self) {
	AVFormatContext *ctx;
	Data_Get_Struct(self, AVFormatContext, ctx);
	return rb_str_new2(ctx->filename);
};

static VALUE format_metadata(VALUE self) {
	AVFormatContext * ctx;
	AVDictionaryEntry * t = NULL;
	VALUE result = rb_hash_new();
	Data_Get_Struct(self, AVFormatContext, ctx);
	
	while (t = av_dict_get(ctx->metadata, "", t, AV_DICT_IGNORE_SUFFIX)) {
		rb_hash_aset(result, rb_str_new2(t->key), rb_str_new2(t->value));
	}
	return result;
};

static VALUE format_streams(VALUE self) {
	AVFormatContext * ctx;
	volatile VALUE streams;
	Data_Get_Struct(self, AVFormatContext, ctx);
	streams  = rb_ary_new2(ctx->nb_streams);
	for(unsigned int i = 0; i < ctx->nb_streams; i++){
		AVStream *stream = ctx->streams[i];
		AVStream *streams_entry = NULL;
		VALUE entry = rb_ary_entry(streams, i);
		if (entry != Qnil)
			Data_Get_Struct(entry, AVStream, streams_entry);
		if (streams_entry != stream){
			rb_ary_store(streams, i, build_stream_obj(stream));
		}

	}
	return streams;
};


/****************
 *              *
 * Registration *
 *              *
 ****************/
void init_format(VALUE module) {
	rb_cFormat = rb_define_class_under(module, "Format", rb_cObject);
	
	rb_define_alloc_func(rb_cFormat, alloc_format);
	rb_define_method(rb_cFormat, "initialize", format_initilize, 0);
	rb_define_method(rb_cFormat, "metadata",  format_metadata, 0);
	rb_define_method(rb_cFormat, "filename", format_filename, 0);
	rb_define_method(rb_cFormat, "start_time", format_start_time, 0);
	rb_define_method(rb_cFormat, "bit_rate", format_bit_rate, 0);
	rb_define_method(rb_cFormat, "streams", format_streams, 0);
};
