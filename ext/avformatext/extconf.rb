require 'mkmf'

have_library("avformat", "av_register_all")

create_makefile 'avformatext/avformatext'
