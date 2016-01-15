# AVFormat
Under heavy development

## Install

* Download FFMpeg snapshot

    wget -O ffmpeg-snapshot.tar.bz2 http://ffmpeg.org/releases/ffmpeg-snapshot.tar.bz2
    tar xvjf ffmpeg-snapshot.tar.bz2
    cd ffmpeg



* Configure and build
```
    ./configure --prefix=/opt/ffmpeg --enable-pthreads --enable-shared --enable-gpl
    make
    sudo make install
```
