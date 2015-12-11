require 'mkmf'

have_header("libavformat/avformat.h")
have_library("avformat", "av_register_all")

create_makefile 'avformatext/avformatext'
