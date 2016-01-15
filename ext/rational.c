#include "avformat.h"

VALUE rb_cRational;

static VALUE alloc_avrational(VALUE klass){
	AVRational *rational = malloc(sizeof(AVRational));
	return Data_Wrap_Struct(klass, 0, 0, rational);
};

static VALUE avrational_den(VALUE self){
	AVRational *rational;
	Data_Get_Struct(self, AVRational, rational);
	return INT2NUM(rational->den);
};

static VALUE avrational_num(VALUE self){
	AVRational *rational;
	Data_Get_Struct(self, AVRational, rational);
	return INT2NUM(rational->num);
};

static VALUE avrational_to_s(VALUE self){
	AVRational *rational;
	Data_Get_Struct(self, AVRational, rational);
	VALUE  num = rb_obj_as_string(INT2NUM(rational->num));
	VALUE  den = rb_obj_as_string(INT2NUM(rational->den));
	VALUE t = rb_str_plus(num, rb_str_new2("/"));
	return rb_str_plus(t, den);
};

static VALUE avrational_initialize(VALUE self, VALUE num, VALUE den){
	AVRational *rational;
	Data_Get_Struct(self, AVRational, rational);
	rational->num = NUM2INT(num);
	rational->den = NUM2INT(den);
	return self;
};

void init_rational(VALUE module) {
	rb_cRational = rb_define_class_under(module, "Rational", rb_cObject);
	rb_define_alloc_func(rb_cRational, alloc_avrational);
	rb_define_method(rb_cRational, "initialize", avrational_initialize, 2);
	rb_define_method(rb_cRational, "num", avrational_num, 0);
	rb_define_method(rb_cRational, "den", avrational_den, 0);
	rb_define_method(rb_cRational, "to_s", avrational_to_s, 0);

}