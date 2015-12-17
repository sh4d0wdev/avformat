require 'mkmf'

def check_libs libs = []
    libs.each { |lib| have_library(lib) || abort("missing library: #{lib}")  }
end

def check_headers headers = []
    headers.each { |head| have_header(head) || abort("could not find header: #{head}")}
end

def manual
    dir_config('ffmpeg')
    libs = ['avformat']
    heads = ['libavformat/avformat.h']

    check_libs(libs) and check_headers(heads)
end

if pkg_config('libavformat') || manual
    puts "found libavformat"
end

puts "CFLAGS=#{CONFIG['CFLAGS']}"

create_makefile 'rubyavformat'
