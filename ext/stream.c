#include "avformat.h"

VALUE rb_cStream;


static VALUE stream_initialize(VALUE self){
	return self;
};

static VALUE stream_duration(VALUE self){
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	return INT2NUM(stream->duration);
};

static VALUE stream_nb_frames(VALUE self){
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	return INT2NUM(stream->nb_frames);
};

static VALUE stream_start_time(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	return INT2NUM(stream->start_time);
};

static VALUE stream_time_base(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	VALUE args[2];
	AVRational time_base = stream->time_base;
	args[0] = INT2NUM(time_base.num);
	args[1] = INT2NUM(time_base.den);
	return rb_class_new_instance(2, args, rb_cRational);
}

static VALUE stream_metadata(VALUE self) {
	AVStream *stream;
	AVDictionaryEntry * t = NULL;
	VALUE result = rb_hash_new();
	Data_Get_Struct(self, AVStream, stream);
	
	while (t = av_dict_get(stream->metadata, "", t, AV_DICT_IGNORE_SUFFIX)) {
		rb_hash_aset(result, rb_str_new2(t->key), rb_str_new2(t->value));
	}
	return result;
};

static VALUE stream_sample_aspect_ratio(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	VALUE args[2];
	AVRational aspect_ratio = stream->sample_aspect_ratio;
	args[0] = INT2NUM(aspect_ratio.num);
	args[1] = INT2NUM(aspect_ratio.den);
	return rb_class_new_instance(2, args, rb_cRational);
}

static VALUE stream_avg_frame_rate(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	VALUE args[2];
	AVRational avg_frame_rate = stream->avg_frame_rate;
	args[0] = INT2NUM(avg_frame_rate.num);
	args[1] = INT2NUM(avg_frame_rate.den);
	return rb_class_new_instance(2, args, rb_cRational);
}

static VALUE stream_discard(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	return INT2NUM(stream->discard);
}

static VALUE stream_id(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	return INT2NUM(stream->id);
}

static VALUE stream_codec(VALUE self) {
	AVStream *stream;
	Data_Get_Struct(self, AVStream, stream);
	return build_avcodec_obj(stream->codec);
}

VALUE build_stream_obj(AVStream *stream){
	VALUE obj = Data_Wrap_Struct(rb_cStream, 0, 0, stream);
	return obj;
}

void init_stream(VALUE module) {
	rb_cStream = rb_define_class_under(module, "Stream", rb_cObject);
	rb_define_method(rb_cStream, "initialize", stream_initialize, 0);
	rb_define_method(rb_cStream, "duration", stream_duration, 0);
	rb_define_method(rb_cStream, "metadata", stream_metadata, 0);
	rb_define_method(rb_cStream, "nb_frames", stream_nb_frames, 0);
	rb_define_method(rb_cStream, "start_time", stream_start_time, 0);
	rb_define_method(rb_cStream, "stream_time_base", stream_time_base, 0);
	rb_define_method(rb_cStream, "sample_aspect_ratio", stream_sample_aspect_ratio, 0);
	rb_define_method(rb_cStream, "avg_frame_rate", stream_avg_frame_rate, 0);
	rb_define_method(rb_cStream, "time_base", stream_time_base, 0);
	rb_define_method(rb_cStream, "discard", stream_discard, 0);
	rb_define_method(rb_cStream, "codec", stream_codec, 0);
	rb_define_method(rb_cStream, "id", stream_id, 0);
}
