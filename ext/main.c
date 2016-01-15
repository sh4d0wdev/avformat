#include "avformat.h"

/***********
STATICS 
************/

/*******************
module AVFormat
********************/
VALUE rb_mAVFormat;

void Init_rubyavformat(void) {
	av_register_all();
	avformat_network_init();
	rb_mAVFormat = rb_define_module("AVFormat");
	init_rational(rb_mAVFormat);
	init_format(rb_mAVFormat);
	init_inputformat(rb_mAVFormat);
	init_stream(rb_mAVFormat);
	init_avdiscard(rb_mAVFormat);
	init_avcodec(rb_mAVFormat);
};
