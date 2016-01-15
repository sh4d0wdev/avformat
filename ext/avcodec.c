#include "avformat.h"
VALUE rb_cAVCodec;

static VALUE avcodec_name(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	if (context->codec == NULL){
		rb_raise(rb_eRuntimeError, "Codec is null");
	}
	return rb_str_new2(context->codec->name);
};

static VALUE avcodec_long_name(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	if (context->codec == NULL){
		rb_raise(rb_eRuntimeError, "Codec is null");
	}
	return rb_str_new2("");
};

static VALUE avcodec_bit_rate(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->bit_rate);
};

static VALUE avcodec_bit_rate_tolerance(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->bit_rate_tolerance);
};

static VALUE avcodec_global_quality(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->global_quality);
};

static VALUE avcodec_compression_level(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->compression_level);
};

static VALUE avcodec_time_base(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	VALUE args[2];
	AVRational time_base = context->time_base;
	args[0] = INT2NUM(time_base.num);
	args[1] = INT2NUM(time_base.den);
	return rb_class_new_instance(2, args, rb_cRational);
};

static VALUE avcodec_ticks_per_frame(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->ticks_per_frame);
};


static VALUE avcodec_delay(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->delay);
};
static VALUE avcodec_width(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->width);
};
static VALUE avcodec_height(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->height);
};
static VALUE avcodec_coded_width(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->coded_width);
};
static VALUE avcodec_coded_height(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->coded_height);
};
static VALUE avcodec_gop_size(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->gop_size);
};

static VALUE avcodec_max_b_frames(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->max_b_frames);
};

static VALUE avcodec_b_quant_factor(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->b_quant_factor);
};

static VALUE avcodec_b_frame_strategy(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->b_frame_strategy);
};

static VALUE avcodec_b_quant_offset(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->b_quant_offset);
};

static VALUE avcodec_has_b_frames(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->has_b_frames);
};

static VALUE avcodec_mpeg_quant(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->mpeg_quant);
};

static VALUE avcodec_i_quant_factor(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->i_quant_factor);
};

static VALUE avcodec_i_quant_offset(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->i_quant_offset);
};

static VALUE avcodec_lumi_masking(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->lumi_masking);
};

static VALUE avcodec_temporal_cplx_masking(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->temporal_cplx_masking);
};

static VALUE avcodec_spatial_cplx_masking(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->spatial_cplx_masking);
};

static VALUE avcodec_p_masking(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->p_masking);
};

static VALUE avcodec_dark_masking(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return rb_float_new(context->dark_masking);
};

static VALUE avcodec_slice_count(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->slice_count);
};

static VALUE avcodec_prediction_method(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->prediction_method);
};

static VALUE avcodec_sample_aspect_ratio(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	VALUE args[2];
	AVRational ratio = context->sample_aspect_ratio;
	args[0] = INT2NUM(ratio.num);
	args[1] = INT2NUM(ratio.den);
	return rb_class_new_instance(2, args, rb_cRational);
};

static VALUE avcodec_me_cmp(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->me_cmp);
};

static VALUE avcodec_me_sub_cmp(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->me_sub_cmp);
};

static VALUE avcodec_me_subpel_quality(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->me_subpel_quality);
};

static VALUE avcodec_ildct_cmp(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->ildct_cmp);
};

static VALUE avcodec_dia_size(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->dia_size);
};

static VALUE avcodec_last_predictor_count(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->last_predictor_count);
};

static VALUE avcodec_pre_me(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->pre_me);
};

static VALUE avcodec_me_pre_cmp(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->me_pre_cmp);
};


static VALUE avcodec_pre_dia_size(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->pre_dia_size);
};

static VALUE avcodec_me_range(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->me_range);
};

static VALUE avcodec_mb_decision(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->mb_decision);
};

static VALUE avcodec_scenechange_threshold(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->scenechange_threshold);
};

static VALUE avcodec_noise_reduction(VALUE self){
	AVCodecContext *context;
	Data_Get_Struct(self, AVCodecContext, context);
	return INT2NUM(context->noise_reduction);
};

VALUE build_avcodec_obj(AVCodecContext *context){
	VALUE obj = Data_Wrap_Struct(rb_cAVCodec, 0, 0, context);
	return obj;
};

void init_avdiscard(VALUE module){
	rb_define_const(module, "AVDISCARD_NONE", INT2NUM(-16));
	rb_define_const(module, "AVDISCARD_DEFAULT", INT2NUM(0));
	rb_define_const(module, "AVDISCARD_NONREF", INT2NUM(8));
	rb_define_const(module, "AVDISCARD_BIDIR", INT2NUM(16));
	rb_define_const(module, "AVDISCARD_NONINTRA", INT2NUM(24));
	rb_define_const(module, "AVDISCARD_NONKEY", INT2NUM(32));
	rb_define_const(module, "AVDISCARD_ALL", INT2NUM(48));
};

void init_avcodec(VALUE  module) {
	rb_cAVCodec = rb_define_class_under(module, "AVCodec", rb_cObject);
	rb_define_method(rb_cAVCodec, "bit_rate", avcodec_bit_rate, 0);
	rb_define_method(rb_cAVCodec, "name", avcodec_name, 0);
	rb_define_method(rb_cAVCodec, "long_name", avcodec_long_name, 0);
	rb_define_method(rb_cAVCodec, "bit_rate_tolerance", avcodec_bit_rate_tolerance, 0);
	rb_define_method(rb_cAVCodec, "global_quality", avcodec_global_quality, 0);
	rb_define_method(rb_cAVCodec, "compression_level", avcodec_compression_level, 0);
	rb_define_method(rb_cAVCodec, "time_base", avcodec_time_base, 0);
	rb_define_method(rb_cAVCodec, "ticks_per_frame", avcodec_ticks_per_frame, 0);
	rb_define_method(rb_cAVCodec, "delay", avcodec_delay, 0);
	rb_define_method(rb_cAVCodec, "width", avcodec_width, 0);
	rb_define_method(rb_cAVCodec, "height", avcodec_height, 0);
	rb_define_method(rb_cAVCodec, "coded_width", avcodec_coded_width, 0);
	rb_define_method(rb_cAVCodec, "coded_height", avcodec_coded_height, 0);
	rb_define_method(rb_cAVCodec, "gop_size", avcodec_gop_size, 0);
	rb_define_method(rb_cAVCodec, "max_b_frames", avcodec_max_b_frames, 0);
	rb_define_method(rb_cAVCodec, "b_quant_factor", avcodec_b_quant_factor, 0);
	rb_define_method(rb_cAVCodec, "b_frame_strategy", avcodec_b_frame_strategy, 0);
	rb_define_method(rb_cAVCodec, "b_quant_offset", avcodec_b_quant_offset, 0);
	rb_define_method(rb_cAVCodec, "has_b_frames", avcodec_has_b_frames, 0);
	rb_define_method(rb_cAVCodec, "mpeg_quant", avcodec_mpeg_quant, 0);
	rb_define_method(rb_cAVCodec, "i_quant_factor", avcodec_i_quant_factor, 0);
	rb_define_method(rb_cAVCodec, "i_quant_offset", avcodec_i_quant_offset, 0);
	rb_define_method(rb_cAVCodec, "lumi_masking", avcodec_lumi_masking, 0);
	rb_define_method(rb_cAVCodec, "temporal_cplx_masking", avcodec_temporal_cplx_masking, 0);
	rb_define_method(rb_cAVCodec, "spatial_cplx_masking", avcodec_spatial_cplx_masking, 0);
	rb_define_method(rb_cAVCodec, "p_masking", avcodec_p_masking, 0);
	rb_define_method(rb_cAVCodec, "dark_masking", avcodec_dark_masking, 0);
	rb_define_method(rb_cAVCodec, "slice_count", avcodec_slice_count, 0);
	rb_define_method(rb_cAVCodec, "prediction_method", avcodec_prediction_method, 0);
	rb_define_method(rb_cAVCodec, "sample_aspect_ratio", avcodec_sample_aspect_ratio, 0);
	rb_define_method(rb_cAVCodec, "me_cmp", avcodec_me_cmp, 0);
	rb_define_method(rb_cAVCodec, "me_sub_cmp", avcodec_me_sub_cmp, 0);
	rb_define_method(rb_cAVCodec, "ildct_cmp", avcodec_ildct_cmp, 0);
	rb_define_method(rb_cAVCodec, "dia_size", avcodec_dia_size, 0);
	rb_define_method(rb_cAVCodec, "last_predictor_count", avcodec_last_predictor_count, 0);
	rb_define_method(rb_cAVCodec, "pre_me", avcodec_pre_me, 0);
	rb_define_method(rb_cAVCodec, "me_pre_cmp", avcodec_me_pre_cmp, 0);
	rb_define_method(rb_cAVCodec, "pre_dia_size", avcodec_pre_dia_size, 0);
	rb_define_method(rb_cAVCodec, "me_subpel_quality", avcodec_me_subpel_quality, 0);
	rb_define_method(rb_cAVCodec, "me_range", avcodec_me_range, 0);
	rb_define_method(rb_cAVCodec, "mb_decision", avcodec_mb_decision, 0);
	rb_define_method(rb_cAVCodec, "scenechange_threshold", avcodec_scenechange_threshold, 0);
	rb_define_method(rb_cAVCodec, "noise_reduction", avcodec_noise_reduction, 0);
};