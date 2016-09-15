# Build this with docker build -t rafaelauler/artifact17 .

FROM debian:jessie
MAINTAINER Rafael Auler <rafaelauler@gmail.com>
RUN apt-get update && apt-get install -y \
  build-essential \
  bzip2 \
  cmake \
  git \
  gnuplot-nox \
  libc6-dev-i386 \
  lib32z1 \
  ninja-build \
  python \
  wget
RUN mkdir /openisa
WORKDIR /openisa
COPY build.sh build.sh
RUN ./build.sh
COPY run.sh run.sh
COPY crossbuild_arm.sh crossbuild_arm.sh
CMD /bin/bash
